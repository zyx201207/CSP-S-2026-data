#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>

namespace {
    typedef long long lnt;

    const int inf = 0x3f3f3f3f;

    const int _max_n = 20;
    const int max_n = 1 << _max_n;

}

int n, ans;
lnt sum[max_n], a[max_n], m;

void solve() {
    std::cin >> n >> m;
    for (int i = 1; i <= n; ++i) std::cin >> a[i];
    std::sort(a + 1, a + 1 + n);

    for (int i = 1; i <= n; ++i) {
        sum[i] = sum[i - 1] + a[i];
        int l = -1, r = i, res;

        while (l < r - 1) {
            int mid = (l + r) >> 1;
            lnt cost = a[i] * (i - mid) - (sum[i] - sum[mid]);
            if (cost <= m) r = res = mid;
            else           l = mid;
        }

        ans = std::max(ans, i - res);
    }

    std::printf("%d\n", ans);

}

int main() {
    std::freopen("crystal.in", "r", stdin);
    std::freopen("crystal.out", "w", stdout);

    std::cin.tie(nullptr)->sync_with_stdio(false);

    int T = 1; // std::cin >> T;
    for (int i = 0; i < T; ++i) {
        solve();
    }

    return 0;
}
