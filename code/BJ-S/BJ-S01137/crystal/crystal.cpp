#include <bits/stdc++.h>

using i64 = long long;
auto& IG = std::ignore;
const i64 MAXN = 1e6 + 10;
i64 n, m, ar[MAXN], sum[MAXN];

void solve(void) {
    std::cin >> n >> m;
    for (i64 i = 1; i <= n; ++i) {
        std::cin >> ar[i];
    }
    std::sort(ar + 1, ar + n + 1);
    for (i64 i = 1; i <= n; ++i) {
        sum[i] = sum[i - 1] + ar[i];
    }
    i64 maxn = 0;
    for (i64 i = 1; i <= n; ++i) {
        i64 l = 1, r = i;
        while (l < r) {
            i64 mid = (l + r) >> 1;
            if ((i - mid + 1) * ar[i] - sum[i] + sum[mid - 1] <= m) r = mid;
            else l = mid + 1;
        }
        maxn = std::max(maxn, i - l + 1);
    }
    std::cout << maxn << '\n';
}

int main() {
    IG = freopen("crystal.in", "r", stdin);
    IG = freopen("crystal.out", "w", stdout);

    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    solve();

    return 0;
}
