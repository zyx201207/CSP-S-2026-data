#include<iostream>
using ll = long long;

const ll N = 5e2 + 2, M = 5e5 + 5, INF = 1e18;
int m, n, a[N][M], t[N][M], w[M], d, q, c, kk[N];
ll g[N][N];
int e[M][22], cnt[M], u, v;
ll ans, mn, ww[M][22];

void init() {
    for (int i = 1; i < N; i ++) {
        for (int j = 1; j < N; j ++) {
            if (i == j) continue;
            g[i][j] = INF;
        }
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    init();

    std::cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i ++) std::cin >> w[i];
    for (int i = 1; i <= n; i ++) {
        std::cin >> kk[i];
        for (int j = 1; j <= kk[i]; j ++) std::cin >> a[i][j] >> t[i][j];
        for (int j = 1; j <= kk[i]; j ++) {
            e[a[i][j]][++cnt[a[i][j]]] = i;
            ww[a[i][j]][cnt[a[i][j]]] = t[i][j];
        }
    }
    for (int i = 1; i <= m; i ++) {
        for (int j = 1; j <= cnt[i]; j ++) {
            for (int k = 1; k <= cnt[i]; k ++) {
                if (j == k) break;
                u = e[i][j], v = e[i][k];
                ll w = ww[i][j] + ww[i][k];
                g[u][v] = std::min(w, g[u][v]);
                g[v][u] = std::min(w, g[v][u]);
            }
        }
    }
    for (int k = 1; k <= n; k ++) {
        for (int i = 1; i <= n; i ++) {
            for (int j = 1; j <= n; j ++) {
                g[i][j] = std::min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }
    for (int i = 1, x, y; i <= q; i ++) {
        std::cin >> x >> y;
        ans = w[x] + w[y], mn = INF;
        for (int j = 1; j <= cnt[x]; j ++) {
            for (int k = 1; k <= cnt[y]; k ++) {
                u = e[x][j], v = e[y][k];
                mn = std::min(mn, g[u][v] + ww[x][j] + ww[y][k]);
            }
        }
        ans += mn;
        std::cout << ans << '\n';
    }
    return 0;
}
