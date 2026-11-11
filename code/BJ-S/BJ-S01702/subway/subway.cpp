#include <bits/stdc++.h>
#define fi first
#define se second
typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::pair<ll, ll> pll;
typedef double db;
typedef __int128 LL;
typedef unsigned long long ull;

ll w[500500];
ll k[550];
std::vector<int> a[550], t[550];

int main() {
    #ifndef LOCAL
        freopen("subway.in", "r", stdin);
        freopen("subway.out", "w", stdout);
    #endif
    int c, n, m, d, q;
    std::cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++) {
        std::cin >> w[i];
    }
    for (int i = 1; i <= n; i++) {
        std::cin >> k[i];
        for (int j = 1; j <= k[i]; j++) {
            ll na, nt;
            std::cin >> na >> nt;
            a[i].push_back(na);
            t[i].push_back(nb);
        }
    }
    while (q--) {
        ll x, y;
        std::cin >> x >> y;
        ll sum = 1e12;
        for (int i = 1; i <= n; i++) {
            if (k[i] < 2) {
                continue;
            }
            for (int j = 0; j < k[i]; j++) {
                if (a[i][j] == x) {
                    for (int l = 0; l < k[i]; l++) {
                        if (a[i][l] == y) {
                            sum = std::min(t[i][j] + t[i][l], sum);
                        }
                    }
                }
            }
        }
        std::cout << sum << '\n';
    }
    return 0;
}