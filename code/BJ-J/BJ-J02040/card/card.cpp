

#include <bits/stdc++.h>

using namespace std;

#define int long long

stack<int> _mySta;
int _all;
int _type;
int _myArr[500009];
int _visArr[300009];
int _resArr[300009];

void ParseIn () {

    ifstream inFile("card.in");

    inFile >> _all >> _type;

    for (int i = 1; i < _all + 1; i++) {
        inFile >> _myArr[i];
    }

    inFile.close();
}

void CParseIn () {
    cin >> _all >> _type;
    for (int i = 1; i < _all + 1; i++) {
        cin >> _myArr[i];
    }
}

void Core () {

    for (int i = 1; i < _all + 1; i++) {
        fill(_visArr, _visArr + _type + 2, 0);
        for (int m = i; m < _all + 1; m++) {
            if (_visArr[_myArr[m]]) {
                while (_mySta.top() != _myArr[m]) {
                    _visArr[_mySta.top()] = 0;
                    _mySta.pop();
                }
                _mySta.pop();
                _visArr[_myArr[m]] = 0;
            }
            _mySta.push(_myArr[m]);
            _visArr[_myArr[m]] = 1;
        }
        for (int m = 1; m < _type + 1; m++) {
            _resArr[m] += _visArr[m];

        }
    }
}

void WriteOut () {

    ofstream outFile("card.out");

    outFile << _resArr[1];
    for (int i = 2; i < _type + 1; i++) {
        outFile << ' ';
        outFile << _resArr[i];
    }

    outFile << endl;

    outFile.close();
}

void CWriteOut () {
    cout << _resArr[1];
    for (int i = 2; i < _type + 1; i++) {
        cout << ' ';
        cout << _resArr[i];
    }

    cout << endl;
}

signed main () {

    ParseIn();
//  CParseIn();
    Core();
    WriteOut();
//  CWriteOut();

    return 0;
}
