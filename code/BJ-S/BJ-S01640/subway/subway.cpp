// subway.cpp
// v3
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int
    N = 500 + 7,
    M = 5e5 + 7;

int w[M];

struct dat {
    int x, w;
};

vector<dat> e[N+M];
int g[N][N];

signed main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);

    int c, n, m, d, q;
    cin >> c >> n >> m >> d >> q;

    for (int i = 1; i <= m; i++) cin >> w[i];
    for (int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        for (int j = 1; j <= k; j++) {
            int a, t;
            cin >> a >> t;
            e[n+a].push_back({i, t});
            e[i].push_back({n+a, t});
        }
    }

    memset(g, 0x3f, sizeof g);

    // 2e8
    for (int i = n+1; i <= n+m; i++) {
        for (int j = 0; j < e[i].size(); j++) {
            for (int k = j+1; k < e[i].size(); k++) {
                int u = e[i][j].x, v = e[i][k].x;
                int w = e[i][j].w + e[i][k].w;

                g[u][v] = g[v][u] = w;
            }
        }
    }

    for (int i = 1; i <= n; i++)
        g[i][i] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = n; k >= 1; k--) {
                g[i][j] = g[j][i] = min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }

    for (int i = 1; i <= q; i++) {
        int x, y;
        cin >> x >> y;

        long long ans = LLONG_MAX;

        for (auto u : e[n+x]) {
            for (auto v : e[n+y]) {
                ans = min(ans, u.w + g[u.x][v.x] + v.w);
            }
        }

        cout << ans + w[x] + w[y] << endl;
    }

    return 0;
}
