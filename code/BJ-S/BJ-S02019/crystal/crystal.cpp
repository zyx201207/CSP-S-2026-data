

#include <bits/stdc++.h>

using namespace std;

#define int long long

int _AllNum;
int _times;
int _maxNum = -1e9;
int _minNum = 1e9;
int _myArr[500009];
int _res;


void ParseIn () {

    ifstream inFile("crystal.in");

    inFile >> _AllNum >> _times;
    for (int i = 0; i < _AllNum; i++) {
        inFile >> _myArr[i];
        _maxNum = max(_maxNum, _myArr[i]);
        _minNum = min(_minNum, _myArr[i]);
    }

    inFile.close();
}

bool Check (int Num) {
    int cur = 0;
    for (int i = 0; i < _AllNum; i++) {
        if (_myArr[i] < Num) {
            cur += Num - _myArr[i];
        }
        if (cur > _times) {
            return false;
        }
    }
    if (cur > _times) {
        return false;
    }
    return true;
}

void Core () {
    int LENum = _minNum;
    int RINum = _maxNum;
    int midNu;

    while (LENum < RINum) {
        midNu = (LENum + RINum) / 2;
//        cout << midNu << endl;
        if (Check(midNu)) {
            LENum = midNu + 1;
            continue;
        }
        RINum = midNu - 1;
    }
//
    LENum -= 10;
    while (Check(LENum + 1)) {
        LENum++;
//        cout << LENum << ' ' << Check(LENum + 1) << endl;
    }
//
//    cout << LENum << ' ' << RINum << endl;
    for (int i = 0; i < _AllNum; i++) {
        if (_myArr[i] < LENum && _times + 1 > LENum - _myArr[i]) {
            _times -= LENum - _myArr[i];
            _myArr[i] = LENum;
        }
        if (_myArr[i] == LENum) {
//            cout << i << endl;
            _res++;
        }
    }
}

void WriteOut () {

    ofstream outFile("crystal.out");

    outFile << _res << endl;

    outFile.close();
}

void CWriteOut () {
    cout << _res << endl;
}

signed main () {

    ParseIn();
    Core();
    WriteOut();
//  CWriteOut();

    return 0;
}
