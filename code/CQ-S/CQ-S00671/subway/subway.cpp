#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
using ll = long long;
constexpr int MAXN = 505, MAXM = 5e5 + 5;
constexpr ll INF = 1e18;
template<typename T> inline void chmin(T &x, T y) { x = x < y ? x : y; }
int n, m, d, q, a[MAXM];
int vec[MAXM][21], val[MAXM][21], siz[MAXM];
ll dist[MAXN][MAXN];
int main() {
    IOS;
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    int c; cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; ++i) cin >> a[i];
    for (int i = 1, k, x, y; i <= n; ++i) {
        cin >> k;
        while (k--) cin >> x >> y, vec[x][++siz[x]] = i, val[x][siz[x]] = y;
    }
    for (int i = 1; i <= n; ++i) fill(dist[i] + 1, dist[i] + 1 + n, INF), dist[i][i] = 0;
    for (int u = 1; u <= m; ++u) {
        for (int i = 1; i <= siz[u]; ++i) for (int j = i + 1; j <= siz[u]; ++j) {
            int x = vec[u][i], y = vec[u][j];
            ll z = val[u][i] + val[u][j];
            chmin(dist[x][y], z), chmin(dist[y][x], z);
        }
    }
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) chmin(dist[i][j], dist[i][k] + dist[k][j]);
        }
    }
    for (int u, v; q--; ) {
        cin >> u >> v;
        ll ans = INF;
        for (int i = 1; i <= siz[u]; ++i) {
            for (int j = 1; j <= siz[v]; ++j) {
                chmin(ans, dist[vec[u][i]][vec[v][j]] + val[u][i] + val[v][j]);
            }
        }
        cout << ans + a[u] + a[v] << '\n';
    }
    return 0;
}