#include <bits/stdc++.h>
using namespace std;

#define int long long

int dis[505][505], c, n, m, d, q;
int w[500005];
vector<int> g[500005], v[500005];

signed main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; ++i) cin >> w[i];
    for (int i = 1; i <= n; ++i) {
        int k;
        cin >> k;
        for (int j = 1; j <= k; ++j) {
            int a1, t1;
            cin >> a1 >> t1;
            g[a1].push_back(i);
            v[a1].push_back(t1);
        }
    }
    memset(dis, 0x3f, sizeof(dis));
    for (int i = 1; i <= n; ++i) dis[i][i] = 0;
    for (int i = 1; i <= m; ++i) {
        for (int j = 0; j < g[i].size(); ++j) {
            for (int k = 0; k < g[i].size(); ++k) {
                int l1 = g[i][j], l2 = g[i][k];
                dis[l1][l2] = dis[l2][l1] = min(dis[l1][l2], v[i][j] + v[i][k]);
            }
        }
    }
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
    while(q--) {
        int xr, yr;
        cin >> xr >> yr;
        int ans = 1e18;
        for (int i = 0; i < g[xr].size(); ++i) {
            for (int j = 0; j < g[yr].size(); ++j) {
                ans = min(ans, w[xr] + w[yr] + v[xr][i] + v[yr][j] + dis[g[xr][i]][g[yr][j]]);
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
