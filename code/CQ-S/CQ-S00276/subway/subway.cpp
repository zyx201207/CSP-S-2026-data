#include <iostream>
#include <vector>

typedef long long ll;

constexpr ll INF = 500000000000000000;

template <class T>
T &cmin(T &x, T y) {
    if (x > y) x = y;
    return x;
}

int c, d, m, n, q, x, y, w[500000], k[500], t[500][500000];
ll ans, dis[500][500];
std::vector<int> line[500000];

int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> c >> n >> m >> d >> q;
    for (int i = 0; i < m; ++i) std::cin >> w[i];
    for (int i = 0; i < n; ++i) {
        std::cin >> k[i];
        for (int a, j = 0; j < k[i]; ++j) {
            std::cin >> a >> t[i][--a];
            line[a].push_back(i);
        }
    }
    for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) dis[i][j] = i == j ? 0 : INF;
    for (int i = 0; i < m; ++i) for (int u = 0; u + 1 < line[i].size(); ++u) for (int v = u + 1; v < line[i].size(); ++v) {
        cmin<ll>(dis[line[i][u]][line[i][v]], t[line[i][u]][i] + t[line[i][v]][i]);
        cmin<ll>(dis[line[i][v]][line[i][u]], t[line[i][u]][i] + t[line[i][v]][i]);
    }
    for (int i = 0; i < n; ++i) for (int u = 0; u < n; ++u) for (int v = 0; v < n; ++v) cmin(dis[u][v], dis[u][i] + dis[i][v]);
    while (q--) {
        std::cin >> x >> y;
        --x, --y, ans = INF;
        for (int u : line[x]) for (int v : line[y]) {
            cmin(ans, t[u][x] + t[v][y] + dis[u][v]);
        }
        std::cout << ans + w[x] + w[y] << '\n';
    }
    return 0;
}