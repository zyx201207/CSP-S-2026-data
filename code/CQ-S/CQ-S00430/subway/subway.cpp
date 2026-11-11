#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 5;
const int M = 505;
int C, n, m, d, q, w[N], dis1[M][M];
vector<pair<int, int>> g[N];
void chmin(int &x, int y) {
    x = min(x, y);
}
signed main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> C >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++) {
        cin >> w[i];
    }
    memset(dis1, 0x3f, sizeof dis1);
    for (int i = 1; i <= n; i++) {
        dis1[i][i] = 0;
        int k;
        cin >> k;
        for (int j = 1; j <= k; j++) {
            int x, y;
            cin >> x >> y;
            g[x].push_back({m + i, y});
            g[m + i].push_back({x, y});
            // dis[i][x] = y;
        }
    }
    for (int i = 1; i <= m; i++) {
        for (auto p1 : g[i]) {
            for (auto p2 : g[i]) {
                chmin(dis1[p1.first - m][p2.first - m], p1.second + p2.second);
            }
        }
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            if (k == i) continue;
            for (int j = 1; j <= n; j++) {
                if (k == j || i == j) continue;
                chmin(dis1[i][j], dis1[i][k] + dis1[k][j]);
            }
        }
    }
    while (q--) {
        int u, v;
        cin >> u >> v;
        int ans = 1e18;
        for (auto p1 : g[u]) {
            for (auto p2 : g[v]) {
                ans = min(ans, p1.second + p2.second + dis1[p1.first - m][p2.first - m]);
            }
        }
        cout << ans + w[u] + w[v] << "\n";
    }
    return 0;
}