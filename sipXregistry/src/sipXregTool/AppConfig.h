/*
 * Copyright (c) 2011 eZuce, Inc. All rights reserved.
 * Contributed to SIPfoundry under a Contributor Agreement
 *
 * This library is free software; you can redistribute it and/or modify it under
 * the terms of the GNU Lesser General Public License as published by the Free
 * Software Foundation; either version 2.1 of the License, or (at your option)
 * any later version.
 *
 * This library is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more
 * details.
 */

#ifndef APP_CONFIG_H
#define APP_CONFIG_H


#include "os/OsServiceOptions.h"

#include <string>



namespace MongoDBTool
{

extern const char* pListEntriesConfOpt;      //"list-entries"
extern const char* pDeleteEntriesConfOpt;    //"delete-entries"
extern const char* pDatabaseNameConfOpt;     //"select-database"
extern const char* pMultipleLinesConfOpt;    //"multiple-lines"
extern const char* pWhereConfOpt;            //"where"
extern const char* pNodeRegistrarDbName;     //"node.registrar"
extern const char* pImdbEntityDbName;        //"imdb.entity"

/**
 * Application configuration class
 * Used for parsing configuration line options
 */
class AppConfig
{
public:

  /**
   * Constructor
   * @param  argc   Number of arguments.
   * @param  pArgv  Array of command line arguments.
   */
  AppConfig(int argc, char** pArgv);

  /* Destructor */
  ~AppConfig();

  // Sets the configuration options
  bool setDefaultOptions();

  /**
   * Parse configuration options
   */

  bool parseOptions();

  // Display help
  void displayUsage(std::ostream& strm) const;

  /**
   * Check if "list-entries" option parameter was given in command line
   * @return  Return true if "list-entries" configuration option is set
   */
  bool hasOptListEntries();


  /**
   * Check if "delete-entries" option parameter was given in command line
   * @return  Return true if "delete-entries" is set in command line
   */
  bool hasOptDeleteEntries();


  /**
   * Check if "multiple-lines" option parameter was given in command line
   * @return  Return true if "multiple-lines" is set in command line
   */
  bool hasOptMultipleLines();

  /**
   * Check if "select-database" option parameter was given in command line
   * @return  Return true if "select-database" is set in command line
   */
  bool hasOptDatabaseName();


  /**
   * Check if "where" option parameter was given in command line
   * @return  Return true if "where" is set in command line
   */
  bool hasOptWhere();


  // Return the value associated with "select-database" parameter
  std::string& databaseName();


  // Return the value associated with "where" parameter
  std::vector<std::string>& whereOptVector();

private:
  bool _hasOptListEntries;                      // Is set true if "list-entries" was found in command line
  bool _hasOptDeleteEntries;                    // Is set true if "delete-entries" was found in command line
  bool _hasOptMultipleLines;                    // Is set true if "multiple-lines" was found in command line
  bool _hasOptDatabaseName;                     // Is set true if "select-database" was found in command line
  std::string _databaseName;                    // The database specified in command line option

  bool _hasOptWhere;                             // Is set true if "where" was found in command line
  std::vector<std::string> _whereOptVector;    /* Contains the parameters associated with "where" configuration entry
                                                * added into a vector
                                                */

  int _argc;                                    // Number of arguments.
  char** _pArgv;                                // Array of command line arguments.

  void checkOptions();   // Sets internal configuration variables after the command line were parsed

  // Creates extra help
  void createExtraHelp(std::ostream& strm) const;
};

inline bool AppConfig::hasOptListEntries()
{
  return _hasOptListEntries;
}

inline bool AppConfig::hasOptDeleteEntries()
{
  return _hasOptDeleteEntries;
}

inline bool AppConfig::hasOptMultipleLines()
{
  return _hasOptMultipleLines;
}

inline bool AppConfig::hasOptDatabaseName()
{
  return _hasOptDatabaseName;
}

inline bool AppConfig::hasOptWhere()
{
  return _hasOptWhere;
}

inline std::string& AppConfig::databaseName()
{
  return _databaseName;
}

inline std::vector<std::string>& AppConfig::whereOptVector()
{
  return _whereOptVector;
}

};




#endif   /* APP_CONFIG_H */
