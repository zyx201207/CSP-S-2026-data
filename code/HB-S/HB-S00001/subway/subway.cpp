#include <bits/stdc++.h>
#define int long long
using namespace std;

namespace stdp {
    const int N = 500, M = 5e5;
    int c, n, m, d, q;
    int w[M + 5];
    int dis[N + 5][N + 5];
    vector<pair<int, int> > qwq[M + 5];
    void main() {
        cin >> c >> n >> m >> d >> q;
        for (int i = 1; i <= m; i++) cin >> w[i];
        for (int i = 1; i <= n; i++) {
            int k, p, t;
            cin >> k;
            for (int j = 1; j <= k; j++) {
                cin >> p >> t;
                qwq[p].push_back({i, t});
            }
        }
        memset(dis, 0x3f, sizeof dis);
        for (int i = 1; i <= n; i++) dis[i][i] = 0;
        for (int i = 1; i <= m; i++) {
            for (pair<int, int> &j : qwq[i]) {
                int u = j.first, w1 = j.second;
                for (pair<int, int> &k : qwq[i]) {
                    int v = k.first, w2 = k.second;
                    dis[u][v] = min(dis[u][v], w1 + w2);
                    dis[v][u] = dis[u][v];
                }
            }
        }
        for (int k = 1; k <= n; k++) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
                }
            }
        }

        while (q--) {
            int x, y;
            cin >> x >> y;
            int res = 1e18;
            for (pair<int, int> &i : qwq[x]) {
                int u = i.first, w1 = i.second;
                for (pair<int, int> &j : qwq[y]) {
                    int v = j.first, w2 = j.second;
                    res = min(res, w1 + dis[u][v] + w2);
                }
            }
            cout << res + w[x] + w[y] << "\n";
        }
    }
}

signed main() {

    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int t = 1;
    // cin >> t;

    while (t--) stdp::main();
    return 0;
}

// 92
// Maybe TLE on the last subtask.
