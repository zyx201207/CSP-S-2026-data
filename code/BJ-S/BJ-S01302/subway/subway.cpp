

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct Node {
    int _line = 0;
    long long _time = 0;
};

const long long INF = 1e18;

int _test = 0;
int _maxiL = 0;//line
int _maxiV = 0;//vertex
int _maxiLS = 0;//line per station
int _maxiQ = 0;
pair<int, int> _query[100009];
long long _inTime[500009];
vector<Node> _lines[500009];
long long _graph[509][509];
long long _dis[509][509];
long long _res[100009];

void ParseIn () {
    ifstream inFile("subway.in");

    inFile >> _test >> _maxiL >> _maxiV >> _maxiLS >> _maxiQ;

    for (int i = 1; i < _maxiV + 1; i++) {
        inFile >> _inTime[i];
    }

    int maxi = 0;
    int station = 0;
    int time = 0;
    Node solo;

    for (int i = 1; i < _maxiL + 1; i++) {
        inFile >> maxi;
        for (int m = 1; m < maxi + 1; m++) {
            inFile >> station >> time;
            solo._line = i;
            solo._time = time;
            _lines[station].push_back(solo);
        }
    }

    for (int i = 1; i < _maxiQ + 1; i++) {
        inFile >> _query[i].first >> _query[i].second;
    }

    inFile.close();
}

void MakeGraph (int curV) {
    for (int i = 0; i < _lines[curV].size(); i++) {
        for (int m = i + 1; m < _lines[curV].size(); m++) {
            _graph[_lines[curV][i]._line][_lines[curV][m]._line] = min(_graph[_lines[curV][i]._line][_lines[curV][m]._line], _lines[curV][i]._time + _lines[curV][m]._time);
            _graph[_lines[curV][m]._line][_lines[curV][i]._line] = _graph[_lines[curV][i]._line][_lines[curV][m]._line];
        }
    }
}

long long FindPath (int from, int to) {
    long long add = _inTime[from] + _inTime[to];
    long long res = INF;

    for (auto line1 : _lines[from]) {
        for (auto line2 : _lines[to]) {
            res = min(res, _dis[line1._line][line2._line] + line1._time + line2._time);
        }
    }

    return res + add;
}

void Core () {
    for (int i = 1; i < _maxiL + 1; i++) {
        for (int m = 1; m < _maxiL + 1; m++) {
            if (i == m) {
                continue;
            }
            _graph[i][m] = INF;
        }
    }

    for (int i = 1; i < _maxiV + 1; i++) {
        MakeGraph(i);
    }

    for (int i = 1; i < _maxiL + 1; i++) {
        for (int m = 1; m < _maxiL + 1; m++) {
            _dis[i][m] = _graph[i][m];
        }
    }

    for (int k = 1; k < _maxiL + 1; k++) {
        for (int i = 1; i < _maxiL + 1; i++) {
            for (int m = 1; m < _maxiL + 1; m++) {
                _dis[i][m] = min(_dis[i][k] + _dis[k][m], _dis[i][m]);
            }
        }
    }

    for (int i = 1; i < _maxiQ + 1; i++) {
        _res[i] = FindPath(_query[i].first, _query[i].second);
    }
}

void CWriteOut () {
    for (int i = 1; i < _maxiQ + 1; i++) {
        cout << _res[i] << endl;
    }
}

void WriteOut () {
    ofstream outFile("subway.out");
    for (int i = 1; i < _maxiQ + 1; i++) {
        outFile << _res[i] << "\n";
    }
    outFile.close();
}

int main () {

    ParseIn();
    Core();
    WriteOut();

    return 0;
}
