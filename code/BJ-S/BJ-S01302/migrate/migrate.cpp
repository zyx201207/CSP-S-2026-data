

#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

ifstream inFile("migrate.in");
ofstream outFile("migrate.out");

const int INF = 0x7fffffff;

int _test = 0;
int _maxi = 0;
long long _maxDis = 0;
long long _place[2000009];
int _step[5009][5009];
int _dp[5009][5009];
long long _cc = 0;

void Solve1 () {
    int r = 0;
    int solo = 0;
    _cc = 0;
    for (int len = 2; len < _maxi + 1; len++) {
        for (int l = 1; l + len - 1 < _maxi + 1; l++) {
            r = l + len - 1;
            if (_place[r] - _place[l] <= _maxDis) {
                _step[l][r] = 1;
                continue;
            }
            if (len == 2 && _place[r] - _place[l] > _maxDis) {
                _step[l][r] = INF;
                continue;
            }
            solo = upper_bound(_place + 1, _place + _maxi + 1, _place[l] + _maxDis) - _place - 1;
            if (_step[solo][r] == INF || solo == l) {
               _step[l][r] = INF;
               continue;
            }
            _step[l][r] = _step[solo][r] + 1;
        }
    }

    for (int len = 2; len < _maxi + 1; len++) {
        for (int l = 1; l + len - 1 < _maxi + 1; l++) {
            r = l + len - 1;
            if (_step[l][r] == INF) {
                continue;
            }
            if (_place[r] - _place[l] <= _maxDis) {
                _dp[l][r] = 1;
                continue;
            }
            solo = upper_bound(_place + 1, _place + _maxi + 1, _place[l] + _maxDis) - _place - 1;
            if (_dp[solo][r] == 1 && _step[solo - 1][r] > _step[solo][r]) {
                _dp[l][r] = 1;
                continue;
            }
            if (_dp[solo][r] == 2 && _step[solo - 1][r] > _step[solo][r]) {
                _dp[l][r] = 2;
                _cc++;
                continue;
            }
            if (solo - 2 < l) {
                _dp[l][r] = 3;
                continue;
            }
            if (_dp[solo][r] == 1 && _dp[solo - 1][r] == 1 && _step[solo - 2][r] > _step[solo][r] && _step[solo - 1][r] == _step[solo][r]) {
                _dp[l][r] = 2;
                _cc++;
                continue;
            }
            _dp[l][r] = 3;
        }
    }
    outFile << _cc << "\n";
}

void Solve2 () {
    if (_maxi == 1) {
        outFile << "0\n";
        return;
    }
    long long jump = _maxDis / (_place[2] - _place[1]);
    if (jump <= 1) {
        outFile << "0\n";
        return;
    }
    outFile << max(_maxi - jump * 2 + 1ll, 0ll) << "\n";
}

int main () {

    int maxi = 0;

    inFile >> _test >> maxi;
    //_test = 11;
    for (int i = 0; i < maxi; i++) {
        inFile >> _maxi >> _maxDis;

        for (int i = 1; i < _maxi + 1; i++) {
            inFile >> _place[i];
        }
        if (_test <= 10) {
            Solve1();
            continue;
        }
        if (_test <= 12) {
            Solve2();
            continue;
        }
    }

    inFile.close();
    outFile.close();

    return 0;
}
