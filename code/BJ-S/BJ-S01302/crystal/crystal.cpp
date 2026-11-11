

#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

const int MAXN = 5e5 + 9;

int _maxi = 0;
long long _time = 0;
long long _val[MAXN];
long long _pre[MAXN];
long long _res = 0;

void ParseIn  () {
    ifstream inFile("crystal.in");

    inFile >> _maxi >> _time;

    for (int i = 1; i < _maxi + 1; i++) {
        inFile >> _val[i];
    }

    inFile.close();
}

void Core () {
    sort(_val + 1, _val + _maxi + 1);
    for (int i = 1; i < _maxi + 1; i++) {
        _pre[i] = _pre[i - 1] + _val[i];
        //cout << _pre[i] << endl;
    }

    long long r = 0;

    for (long long l = 1; l < _maxi + 1; l++) {
        while (r < _maxi) {
            if (_val[r + 1] * (r - l + 2ll) - (_pre[r + 1] - _pre[l - 1]) <= _time) {
                r++;
                continue;
            }
            break;
        }
        //cout << l << "," << r << endl;
        _res = max(_res, r - l + 1);
    }
}

void CWriteOut () {
    cout << _res << endl;
}

void WriteOut () {
    ofstream outFile("crystal.out");
    outFile << _res << endl;
    outFile.close();
}

int main () {

    ParseIn();
    Core();
    WriteOut();

    return 0;
}
