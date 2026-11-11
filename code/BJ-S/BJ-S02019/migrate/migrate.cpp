

#include <bits/stdc++.h>

using namespace std;

#define int long long

int _AllNum;
int _island;
int _len;
int _myArr[2000009];
int _res;


void ParseIn () {
//  nothing
}

void Core () {
    for (int i = 0; i < _island; i++) {
        for (int m = i; m < _island; m++) {
            if (_myArr[i] + _len - 1 < _myArr[m] && _myArr[i] + _len + _len > _myArr[m]) {
                _res += 2;
            }
        }
    }
}

void WriteOut () {

    ofstream outFile("migrate.out");

    outFile << _res << endl;

    outFile.close();
}

void CWriteOut () {
    cout << _res << endl;
}

void Solve () {

    ifstream inFile("migrate.in");

    int trash;
    inFile >> trash >> _AllNum;
    for (int i = 0; i < _AllNum; i++) {
        inFile >> _island >> _len;
        for (int m = 0; m < _island; m++) {
            inFile >> _myArr[m];
        }
        Core();
        WriteOut();
//      CWriteOut();
        _res = 0;
    }

    inFile.close();
}

signed main () {

    Solve();

    return 0;
}
