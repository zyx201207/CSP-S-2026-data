#include <iostream>
#include <cstdio>
#include <array>

using ll = long long;

constexpr int MAXN{5010};

int n;
ll d;
std::array<ll, MAXN> a;

std::array<std::array<ll, MAXN>, MAXN> dis, cnt;

void clear() {
    for (int i{1}; i <= n; i++) a[i] = 0;
    for (int i{1}; i <= n; i++) {
        for (int j{1}; j <= n; j++) {
            cnt[i][j] = 0;
            dis[i][j] = 1e9;
        }
    }
}

void input() {
    std::cin >> n >> d;
    clear();
    for (int i{1}; i <= n; i++) {
        std::cin >> a[i];
        dis[i][i] = 0;
    }
}

void init() {
    for (int i{1}; i <= n; i++) {
        for (int j{1}; j <= n; j++) {
            if (i != j) {
                if (std::abs(a[i] - a[j]) <= d) {
                    cnt[i][j]++;
                    dis[i][j] = 1;
                }
            }
            // std::cout << (dis[i][j] == 1e9 ? '?' : dis[i][j]) << " ";
        }
        // std::cout << "\n";
    }
}

void work() {
    init();
    for (int k{1}; k <= n; k++) {
        for (int i{1}; i <= n; i++) if (std::llabs(a[i] - a[k]) <= d) {
            for (int j{1}; j <= n; j++) if (std::llabs(a[k] - a[j]) <= d) {
                if (dis[i][j] > dis[i][k] + dis[k][j]) {
                    dis[i][j] = dis[i][k] + dis[k][j];
                    cnt[i][j] = 1;
                } else if (dis[i][j] == dis[i][k] + dis[k][j]) {
                    cnt[i][j] += cnt[i][k] * cnt[k][j];
                }
                // std::cout << (dis[i][j] == 1e9 ? '?' : dis[i][j]) << " ";
            }
            // std::cout << "\n";
        }
    }

    // std::cout << dis[8][10] << ' ' << cnt[8][10] << "\n";

    int ans{0};
    for (int i{1}; i <= n; i++) {
        for (int j{i+1}; j <= n; j++) {
            if (cnt[i][j] == 2) ans++;
            // std::cout << cnt[i][j] << ' ';
        }
        // std::cout << "\n";
    }
    std::cout << ans << "\n";
}

auto main() -> int {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out","w",stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int c, t;
    std::cin >> c >> t;
    while (t--) {
        input();
        work();
    }
    return 0;
}

/*

0 1
10 3
-1000000000000000000 -999999999999999997 -999999999999999994 -999999999999999993 -999999999999999992 -999999999999999991 -999999999999999990 -999999999999999989 -999999999999999986 -999999999999999983

0 1
7 3
0 3 4 5 6 7 10

0 1
10 3
0 3 6 8 10 11 12 13 15 18 

*/