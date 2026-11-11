#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 2E5 +500;
int a[MAXN];
int len[MAXN];
int flag[MAXN];
vector<int> erx[MAXN]; //daoxv cun
int n, m, maxlen;
int getlen (int i, int x) {
    int xlen = 0;
    while (x) {
        xlen++;
        x /= 2;
    }
    return xlen;
}
void turn (int i, int x) {
    while (x) {
        erx[i].push_back(x % 2);
        x /= 2;
    }
    if (erx[i].size() < maxlen) {
        for (int j = erx[i].size(); j < maxlen; j++) {
            erx[i].push_back(0);
        }
    }
    vector<int> p;
    for (int j = maxlen - 1; j >= 0; j--) {
        p.push_back(erx[i][j]);
    }
    erx[i].clear();
    for (int j = 0; j < p.size(); j++) {
        erx[i].push_back(p[j]);
    }
}

int judge (int k) {
    int num = 0;
    for (int i = 1; i <= n; i++) {
            //cout << "erx " << i << ' ' << k << ' ' << erx[i][k] << '\n';
        if (erx[i][k] == 1 && !flag[i]) num++;
    }
    return num;
}
signed main () {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        len[i] = getlen(i, a[i]);
        maxlen = max(maxlen, len[i]);
    }
    for (int i = 1; i <= n; i++) {
        turn(i, a[i]);
    }
    int maxn = 0;
    for (int k = 0; k < maxlen; k++) {
        if (judge(k) < m) continue;
        maxn += pow(2, maxlen - k - 1);
        for (int i = 1; i <= n; i++) {
            if (erx[i][k] == 0) flag[i] = 1; //shanchu
        }
    }
    cout << maxn;
    return 0;
}