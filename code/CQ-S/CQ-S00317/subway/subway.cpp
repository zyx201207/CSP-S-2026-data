#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define endl '\n'
#define CONTEST

const int inf = 2e18;
void solve() {
    int c, n, m, d, q; 
    if (!(cin >> c >> n >> m >> d >> q))
        exit(0);
    vector<int> w(m);
    for (int i = 0; i < m; i++)
        cin >> w[i];
    // 只记地铁线路
    vector<vector<pair<int, int>>> dz(m); 
    for (int i = 0; i < m; i++) dz[i].reserve(d);
    vector<vector<int>> g(n, vector<int> (n, inf));
    for (int i = 0; i < n; i++) g[i][i] = 0;
    for (int i = 0; i < n; i++) {
        int k; cin >> k;
        for (int j = 0; j < k; j++) {
            int a, t; cin >> a >> t; a--;
            dz[a].emplace_back(i, t);
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < (int)dz[i].size(); j++) {
            for (int k = j + 1; k < (int)dz[i].size(); k++) {
                int u = dz[i][j].first, v = dz[i][k].first;
                int w1 = dz[i][j].second, w2 = dz[i][k].second;
                // cerr << u << " " << v << " " << w1 + w2 << endl;
                g[u][v] = g[v][u] = min(g[u][v], w1 + w2);
            }
        }
    }
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         cerr << g[i][j] << " ";
    //     } cerr << endl;
    // } 
    while (q--) {
        int x, y; cin >> x >> y; x--; y--;
        int ans = inf;
        for (int i = 0; i < (int)dz[x].size(); i++) {
            for (int j = 0; j < (int)dz[y].size(); j++) {
                int u = dz[x][i].first, v = dz[y][j].first;
                int w1 = dz[x][i].second, w2 = dz[y][j].second;
                // cerr << u << " " << v << " " << w1 << " " << w2 << endl;
                ans = min(ans, w1 + g[u][v] + w2);
            }
        }
        cout << w[x] + ans + w[y] << endl;
    }
}
signed main() {
    #ifdef CONTEST
    #ifndef LOCAL
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    #endif
    #endif

    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T = -1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;   
}
// CSP-S 2026 RP++

/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/