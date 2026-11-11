#include<iostream>
#include<algorithm>
#define int long long

const int N = 5e5 + 5;
int n, m, a[N], ans = -N, l = 1, r, tot, len;

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    std::cin >> n >> m;
    for (int i = 1; i <= n; i ++) {
        std::cin >> a[i];
    }
    std::sort(a + 1, a + 1 + n);
    for (r = 1; r <= n; r ++) {
        tot += len * (a[r] - a[r - 1]);
        while (l < r && tot > m) {
            tot -= a[r] - a[l ++];
        }
        len = r - l + 1;
        ans = std::max(ans, len);
    }
    std::cout << ans;
    return 0;
}
