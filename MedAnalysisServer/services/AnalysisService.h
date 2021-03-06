#ifndef MEDANALYSIS_SERVER_ANALYSISSERVICE_H
#define MEDANALYSIS_SERVER_ANALYSISSERVICE_H

#include <vector>
#include <string>
#include <algorithm>
#include "../models/Disease.h"
#include "../models/Genome.h"
#include "../storage/DiseaseDAO.h"

using std::vector;
using std::string;
using std::unordered_multimap;
using std::pair;


class AnalysisService {

public:

    AnalysisService();

    vector<Disease> evaluateAll(Genome g);

    unordered_multimap<string, Disease> getDisease();
    const pair<
            unordered_multimap<string, Disease>::iterator,
            unordered_multimap<string, Disease>::iterator
    >  getDiseaseByName(string name);

    bool evaluateOne(Genome &g, Disease &d) const;

private:
    DiseaseDAO diseaseDAO;

};

#endif //MEDANALYSIS_SERVER_ANALYSISSERVICE_H
