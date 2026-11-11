#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
const int maxn = 500 + 10;
const int maxk = 5e5 + 10;
const int inf = 0x3f3f3f3f3f3f3f3f;
int c, n, m, d, q, a[maxk], f[maxn][maxn];
vector<pii> trans[maxk];
signed main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        int k; cin >> k;
        for (int j = 1; j <= k; j++) {
            int st, tm; cin >> st >> tm;
            trans[st].push_back({i, tm});
        }
    }
    memset(f, 0x3f, sizeof(f));
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j < (int)trans[i].size(); j++) {
            for (int k = j + 1; k < (int)trans[i].size(); k++) {
                int jj = trans[i][j].first, kk = trans[i][k].first;
                f[jj][kk] = min(f[jj][kk], trans[i][j].second + trans[i][k].second);
                f[kk][jj] = f[jj][kk];
            }
        }
    }
    for (int i = 1; i <= n; i++) f[i][i] = 0;
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
            }
        }
    }
    while (q--) {
        int st, ed, res = 0; cin >> st >> ed;
        res = a[st] + a[ed];
        int cur = inf;
        for (auto i : trans[st]) {
            for (auto j : trans[ed]) {
                cur = min(cur, f[i.first][j.first] + i.second + j.second);
            }
        }
        cout << res + cur << "\n";
    }
    return 0;
}

/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/

/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/