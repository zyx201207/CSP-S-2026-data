

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream inFile("hub.in");
ofstream outFile("hub.out");

int _test = 0;
int _maxi = 0;
int _size = 0;
vector<int> _graph[19];
int _dis[19][19];
bool _vis[19];
bool _isHub[19];

int PopCnt (int num) {
    int cc = 0;
    while (num > 0) {
        cc += num % 2;
        num /= 2;
    }
    return cc;
}

void DFS (int curV, int fa, int starti) {
    if (curV == starti) {
        _dis[starti][curV] = 0;
    }
    else {
        _dis[starti][curV] = _dis[starti][fa] + 1;
    }
    //cout << curV << "," << fa << endl;
    for (auto to : _graph[curV]) {
        if (to != fa) {
            DFS(to, curV, starti);
        }
    }
    return;
}

void DFS2 (int curV, int fa) {
    if (!_isHub[curV]) {
        return;
    }
    _vis[curV] = true;
    //cout << "!" << endl;
    for (auto to : _graph[curV]) {
        if (to != fa) {
            DFS2(to, curV);
        }
    }
}

void Solve () {
    for (int i = 1; i < _maxi + 1; i++) {
        for (int m = 1; m < _maxi + 1; m++) {
            _dis[i][m] = 0x7fffffff;
        }
        DFS(i, 0, i);
    }
    //cout << "1" << endl;
    int minDis = 0x7fffffff;
    int cc = 0;
    int maxi = 0;
    int res = 0x7fffffff;
    for (int i = 0; i < (1 << _maxi); i++) {
            //cout << i << endl;
        if (PopCnt(i) != _size) {
            continue;
        }

        for (int m = 1; m < _maxi + 1; m++) {
            if ((i >> m - 1) & 1) {
                _isHub[m] = true;
            }
            else {
                _isHub[m] = false;
            }
        }
        fill(_vis, _vis + _maxi + 1, false);
        cc = 0;
        for (int m = 1; m < _maxi + 1; m++) {
            if (_isHub[m] && !_vis[m]) {
                DFS2(m, 0);
                cc++;
            }
        }
        if (cc > 2) {
            continue;
        }
        maxi = 0;

        for (int m = 1; m < _maxi + 1; m++) {
            minDis = 0x7fffffff;
            for (int k = 1; k < _maxi + 1; k++) {
                if (_isHub[k]) {
                    minDis = min(minDis, _dis[m][k]);
                }
            }
            maxi = max(maxi, minDis);
        }
        res = min(res, maxi);
    }

    outFile << res << "\n";
}

int main () {

    int maxi = 0;
    int from = 0;
    int to = 0;

    inFile >> _test >> maxi;

    for (int i = 0; i < maxi; i++) {
        inFile >> _maxi >> _size;
        for (int i = 1; i < _maxi + 1; i++) {
            _graph[i].clear();
        }
        for (int i = 1; i < _maxi; i++) {
            inFile >> from >> to;
            _graph[from].push_back(to);
            _graph[to].push_back(from);
        }
        Solve();
    }

    inFile.close();
    outFile.close();

    return 0;
}
