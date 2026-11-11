#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 510, M = 5e5 + 10;
int c, n, m, d, q;
int t[M], a[M], w[M], prek[N];
ll f[N][N];
vector<pair<int, int>> g[M];

int F(int i, int j) {
    return prek[i - 1] + j;
}

int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++) {
        cin >> w[i];
    }
    for (int i = 1, k; i <= n; i++) {
        cin >> k;
        prek[i] = prek[i - 1] + k;
        for (int j = 1; j <= k; j++) {
            cin >> a[F(i, j)] >> t[F(i, j)];
            g[a[F(i, j)]].push_back(make_pair(i, j));
        }
    }
    memset(f, 0x3f3f3f3f, sizeof f);
    for (int i = 1; i <= n; i++) {
        f[i][i] = 0;
    }
    for (int st = 1; st <= m; st++) {
        for (int i = 1; i < g[st].size(); i++) {
            for (int j = 0; j < i; j++) {
                int u = g[st][i].first, v = g[st][j].first;
                int ku = g[st][i].second, kv = g[st][j].second;
                f[v][u] = f[u][v] = min(f[u][v], 1ll * t[F(u, ku)] + t[F(v, kv)]);
            }
        }
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
            }
        }
    }
    while (q--) {
        int x, y;
        cin >> x >> y;
        ll ans = 9e18;
        for (int i = 0; i < g[x].size(); i++) {
            for (int j = 0; j < g[y].size(); j++) {
                int u = g[x][i].first, v = g[y][j].first;
                int ku = g[x][i].second, kv = g[y][j].second;
                ans = min(ans, 1ll * w[x] + w[y] + t[F(u, ku)] + t[F(v, kv)] + f[u][v]);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
