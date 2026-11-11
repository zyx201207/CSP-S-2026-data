

#include <bits/stdc++.h>

using namespace std;

#define int long long

int _all;
int _cho;
int _myArr[200009];
int _visArr[200009];
int _res = -1e9;

void ParseIn () {

    ifstream inFile("and.in");

    inFile >> _all >> _cho;

    for (int i = 0; i < _all; i++) {
        inFile >> _myArr[i];
    }

    inFile.close();
}

void CParseIn () {
    cin >> _all >> _cho;

    for (int i = 0; i < _all; i++) {
        cin >> _myArr[i];
    }
}

int DFS (int now, int have) {
    if (have == _cho) {
        return now;
    }
    int curRes = -1e9;

    for (int i = 0; i < _all; i++) {
        if (!_visArr[i]) {
            _visArr[i] = 1;
            curRes = max(curRes, DFS((int)(_myArr[i] & now), have + 1));
            _visArr[i] = 0;
        }
    }
    return curRes;
}

void Core () {

    for (int i = 0; i < _all; i++) {
        _visArr[i] = 1;
        _res = max(_res, DFS(_myArr[i], 1));
        _visArr[i] = 0;
    }
}

void WriteOut () {

    ofstream outFile("and.out");

    outFile << _res << endl;

    outFile.close();
}

void CWriteOut () {

    cout << _res << endl;

}

signed main () {

    ParseIn();
//  CParseIn();
    Core();
    WriteOut();
//  CWriteOut();

    return 0;
}
