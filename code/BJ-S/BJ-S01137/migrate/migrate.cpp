#include <bits/stdc++.h>

using i64 = long long;
auto& IG = std::ignore;
const i64 MAXN = 2e6 + 10, INF = 0x3f3f3f3f3f3f3f3f;
i64 c, n, xr[MAXN], d;

namespace sol_bf {
    i64 fr[MAXN], cnt[MAXN];
    void solve(void) {
        i64 ans = 0;
        for (i64 u = 1; u <= n; ++u) {
            for (i64 v = u; v <= n; ++v) {
                fr[v] = INF;
                cnt[v] = 0;
            }
            fr[u] = 0;
            cnt[u] = 1;
            i64 last = u - 1;
            for (i64 v = u + 1; v <= n; ++v) {
                while (last < n && xr[v] - xr[last + 1] > d) ++last;
                // (last, v]
                fr[v] = fr[last + 1] + 1;
                cnt[v] = cnt[last + 1];
                if (last + 2 < v && fr[last + 2] + 1 == fr[v]) {
                    cnt[v] += cnt[last + 2];
                }
                if (last + 3 < v && fr[last + 3] + 1 == fr[v]) {
                    cnt[v] += cnt[last + 3];
                }
                cnt[v] = std::min(cnt[v], 3ll);
                if (cnt[v] == 2) {
                    ++ans;
                }
            }
        }
        std::cout << ans << '\n';
    }
}

namespace sol_a {
    void solve(void) {
        if (n == 1) {
            std::cout << "0\n";
            return;
        }
        d /= (xr[2] - xr[1]);
        if (!d || d == 1) {
            std::cout << "0\n";
            return;
        }
        std::cout << std::max(0ll, n - (d << 1) + 1) << '\n';
    }
}

namespace sol_b {
    void solve(void) {
        i64 p = 0;
        for (i64 i = 1; i <= n; ++i) {
            if (xr[i] - xr[1] <= d && xr[n] - xr[i] <= d) {
                p = i;
                break;
            }
        }
        i64 ni = 0, ans = 0, p2 = p - 2, p1 = p - 1;
        if (p >= 3) {
            while (p2 < n && xr[p2 + 1] - xr[p - 2] <= d) ++p2;
            while (p1 < n && xr[p1 + 1] - xr[p - 1] <= d) ++p1;
        }
        for (i64 i = 1; i < p; ++i) {
            while (ni < n && xr[ni + 1] - xr[i] <= d) ++ni;
            if (ni - p + 1 > 2) continue;
            if (ni == p + 1) {
                // x[j] > x[p - 1] + d
                i64 j = std::upper_bound(xr + 1, xr + n + 1, xr[p - 1] + d) - xr;
                // [j, n]
                ans += n - j + 1;
            }
            else {
                // ni == p
                // i <= p - 1
                // i = p - 1: no solution
                if (i < p - 1) {
                    // p - 2 p - 1 p
                    // p - 2 no
                    // p - 1 yes
                    // (p2, p1]
                    ans += p1 - p2;
                }
            }
        }
        std::cout << ans << '\n';
    }
}

namespace sol_c {
    void solve(void) {
        
    }
}

void solve(void) {
    std::cin >> n >> d;
    for (i64 i = 1; i <= n; ++i) {
        std::cin >> xr[i];
    }
    if (c <= 10) {
        sol_bf::solve();
    }
    else if (11 <= c && c <= 12) {
        sol_a::solve();
    }
    else if (13 <= c && c <= 14) {
        sol_b::solve();
    }
    else if (15 <= c && c <= 18) {
        sol_c::solve();
    }
    else {
        sol_bf::solve();
    }
}

int main() {
    IG = freopen("migrate.in", "r", stdin);
    IG = freopen("migrate.out", "w", stdout);

    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    i64 t = 0;
    std::cin >> c >> t;
    while (t--) solve();

    return 0;
}
