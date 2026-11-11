#include <bits/stdc++.h>

typedef long long ll;

const int N = 5e2 + 10;
const int M = 5e5 + 10;

ll dis[N][N];
int c, n, m, d, q;
ll w[M];
std::vector<std::pair<int, ll>> g[M];

FILE *IG;

int main() {
    IG = freopen("subway.in", "r", stdin);
    IG = freopen("subway.out", "w", stdout);
    
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> c >> n >> m >> d >> q;

    for (int i = 1; i <= m; i++) {
        std::cin >> w[i];
    }

    for (int i = 1; i <= n; i++) {
        int k;
        std::cin >> k;

        while (k--) {
            int a;
            ll t;
            std::cin >> a >> t;
            g[a].emplace_back(i, t);
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dis[i][j] = LLONG_MAX / 4;
        }

        dis[i][i] = 0;
    }

    for (int i = 1; i <= m; i++) {
        for (auto p1 : g[i]) {
            for (auto p2 : g[i]) {
                if (p1.first != p2.first) {
                    dis[p1.first][p2.first] = std::min(dis[p1.first][p2.first], p1.second + p2.second);
                }
            }
        }
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            if (i != k) {
                for (int j = 1; j <= n; j++) {
                    dis[i][j] = std::min(dis[i][j], dis[i][k] + dis[k][j]);
                }
            }
        }
    }

    while (q--) {
        int s, t;
        std::cin >> s >> t;
        ll ans = LLONG_MAX / 2;

        for (auto p1 : g[s]) {
            for (auto p2 : g[t]) {
                ans = std::min(ans, dis[p1.first][p2.first] + p1.second + p2.second);
            }
        }

        std::cout << ans + w[s] + w[t] << '\n';
    }

    return 0;
}