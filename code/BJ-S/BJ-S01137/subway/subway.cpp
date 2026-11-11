#include <bits/stdc++.h>

using i64 = long long;
using PLL = std::pair<i64, i64>;
auto& IG = std::ignore;
const i64 MAXN = 510, MAXM = 5e5 + 10, MAXD = 22, INF = 1e18;
i64 c, n, m, d, q, wr[MAXM], gr[MAXN][MAXN], dist[MAXN][MAXN];
uint8_t vis[MAXN][MAXN];
std::vector<PLL> tr[MAXM];

void init_g(void) {
    for (i64 i = 1; i <= n; ++i) {
        for (i64 j = 1; j <= n; ++j) {
            if (i == j) gr[i][j] = 0;
            else gr[i][j] = INF;
        }
    }
    for (i64 s = 1; s <= m; ++s) if (tr[s].size() > 1) {
        i64 sz = (i64) tr[s].size();
        for (i64 i = 0; i < sz; ++i) {
            i64 x1 = tr[s][i].first, t1 = tr[s][i].second;
            for (i64 j = i + 1; j < sz; ++j) {
                i64 x2 = tr[s][j].first, t2 = tr[s][j].second;
                gr[x1][x2] = gr[x2][x1] = std::min(gr[x1][x2], t1 + t2);
            }
        }
    }
}

void dijkstra(i64 s) {
    for (i64 i = 0; i <= n; ++i) {
        dist[s][i] = INF;
    }
    dist[s][s] = 0;
    for (i64 ct = 1; ct <= n; ++ct) {
        i64 u = 0;
        for (i64 i = 1; i <= n; ++i) {
            if (!vis[s][i] && dist[s][i] < dist[s][u]) {
                u = i;
            }
        }
        if (!u) return;
        vis[s][u] = 1;
        for (i64 v = 1; v <= n; ++v) if (gr[u][v] < INF) {
            if (dist[s][v] > dist[s][u] + gr[u][v]) {
                dist[s][v] = dist[s][u] + gr[u][v];
            }
        }
    }
}

void solve(void) {
    std::cin >> c >> n >> m >> d >> q;
    for (i64 i = 1; i <= m; ++i) {
        std::cin >> wr[i];
    }
    for (i64 t = 1; t <= n; ++t) {
        i64 cnt = 0;
        std::cin >> cnt;
        while (cnt--) {
            i64 a = 0, x = 0;
            std::cin >> a >> x;
            tr[a].emplace_back(t, x);
        }
    }
    init_g();
    for (i64 i = 1; i <= n; ++i) {
        dijkstra(i);
    }
    while (q--) {
        i64 x = 0, y = 0;
        std::cin >> x >> y;
        i64 minn = INF;
        for (const PLL& tx : tr[x]) {
            for (const PLL& ty : tr[y]) {
                minn = std::min(minn, wr[x] + tx.second + dist[tx.first][ty.first] + ty.second + wr[y]);
            }
        }
        std::cout << minn << '\n';
    }
}

int main() {
    IG = freopen("subway.in", "r", stdin);
    IG = freopen("subway.out", "w", stdout);

    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    solve();

    return 0;
}
