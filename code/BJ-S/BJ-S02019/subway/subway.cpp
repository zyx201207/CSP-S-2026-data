

#include <bits/stdc++.h>

using namespace std;

#define int long long

int _case;
int _roll;
int _stube;
int _MaxCro;
int _task;
int _startArr[500009];
vector<int> _ROMap[10009];
vector<int> _STMap[10009];
int _myArr[509][10009];
int _froArr[500009];
int _endArr[500009];
int _resArr[500009];

void ParseIn () {

    ifstream inFile("subway.in");

    inFile >> _case >> _roll >> _stube >> _MaxCro >> _task;
    for (int i = 0; i < _stube; i++) {
        inFile >> _startArr[i];
    }
    for (int i = 0; i < _roll; i++) {
        int len;
        inFile >> len;
        for (int m = 0; m < len; m++) {
            int to;
            int time;
            inFile >> to >> time;
            _ROMap[i + (int)1].push_back(to);
            _STMap[to].push_back(i + (int)1);
            _myArr[i + (int)1][to] = time;
        }
    }
    for (int i = 0; i < _task; i++) {
        inFile >> _froArr[i] >> _endArr[i];
    }

    inFile.close();
}

int DFS (int now, int two, int cur) {
    if (now == two) {
        return cur;
    }
    if (cur > 1e13) {
        return 1e9;
    }
    if (now > two) {
        return 1e9;
    }
    int MINNum = 1e9;

    for (int i = 0; i < _STMap[now].size(); i++) {
        for (int m = 0; m < _ROMap[_STMap[now][i]].size(); m++) {
            if (_ROMap[_STMap[now][i]][m] != now) {
                MINNum = min(MINNum, DFS(_ROMap[_STMap[now][i]][m], two, cur + _myArr[_STMap[now][i]][_ROMap[_STMap[now][i]][m]]));
            }
        }
    }
    return MINNum;
}

void Core () {
 /*   if (_MaxCro < 3) {
        for (int i = 0; i < _task; i++) {
            _resArr[i] = DFST(_froArr, _endArr, _startArr[_froArr] + _startArr[_endArr]);
        }
    }
*/
    for (int i = 0; i < _task; i++) {
        _resArr[i] = DFS(_froArr[i], _endArr[i], (int)(_startArr[_froArr[i]] + _startArr[_endArr[i]]));
    }
}

void WriteOut () {

    ofstream outFile("subway.out");

    for (int i = 0; i < _task; i++) {
        outFile << _resArr[i] << endl;
    }

    outFile.close();
}

void CWriteOut () {
    for (int i = 0; i < _task; i++) {
        cout << _resArr[i] << endl;
    }
}

signed main () {

    ParseIn();
    Core();
    WriteOut();
//  CWriteOut();

    return 0;
}
