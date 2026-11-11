#include <iostream>
#include <cstdio>
#include <array>
#include <vector>

using ll = long long;

constexpr int MAXN{510};
constexpr int MAXM{500010};

int n, m, Q;
std::array<std::array<ll, MAXN>, MAXN> dis;
std::array<ll, MAXM> w;
std::array<std::array<ll, MAXM>, MAXN> t;

std::array<std::vector<int>, MAXM> bel;

void input() {
    int c, d;
    std::cin >> c >> n >> m >> d >> Q;
    for (int i{1}; i <= m; i++) {
        std::cin >> w[i];
    }
    for (int i{1}; i <= n; i++) {
    	int k;
        std::cin >> k;
        for (int j{1}; j <= k; j++) {
        	int a;
            std::cin >> a;
            std::cin >> t[i][a];
            bel[a].emplace_back(i);
        }
    }
}

void init() {
    for (int i{1}; i <= n; i++) {
        for (int j{1}; j <= n; j++) {
            dis[i][j] = 1e18;
        }
        dis[i][i] = 0;
    }
    for (int i{1}; i <= m; i++) {
        int len = bel[i].size();
        for (int j{0}; j < len; j++) {
            for (int k{j+1}; k < len; k++) {
                int u{bel[i][j]}, v{bel[i][k]};
                dis[u][v] = dis[v][u] = std::min(dis[u][v], t[u][i] + t[v][i]);
                // std::cout << i << ' ' << 
            }
        }
    }
    // for (int i{1}; i <= n; i++) {
    //     for (int j{1}; j <= n; j++) {
    //         std::cout << dis[i][j] << " ";
    //     }
    //     std::cout << "\n";
    // }
}

void work() {
    init();
    for (int k{1}; k <= n; k++) {
        for (int i{1}; i <= n; i++) {
            for (int j{1}; j <= n; j++) {
                if (dis[i][j] > dis[i][k] + dis[k][j]) {
                    dis[i][j] = dis[i][k] + dis[k][j];
                }
            }
        }
    }
    while (Q--) {
        int u, v;
        std::cin >> u >> v;
        ll ans = 1e18;
        for (int i{0}; i < bel[u].size(); i++) {
            for (int j{0}; j < bel[v].size(); j++) {
                int x{bel[u][i]}, y{bel[v][j]};
                ans = std::min(ans, dis[x][y] + t[x][u] + t[y][v] + w[u] + w[v]);
                // std::cout << dis[x][y] << ' ' << t[x][u] << ' ' << t[y][v] << ' ' << w[u] << ' ' << w[v] << "\n";
            }
        }
        std::cout << ans << "\n";
    }
}

auto main() -> int {
    freopen("subway.in", "r", stdin);
    freopen("subway.out","w",stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    input();
    work();
    return 0;
}