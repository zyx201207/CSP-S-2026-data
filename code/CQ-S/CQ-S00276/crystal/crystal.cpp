#include <algorithm>
#include <iostream>

typedef long long ll;

template <class T>
T &cmax(T &x, T y) {
    if (x < y) x = y;
    return x;
}

int n, ans;
ll m, cur, a[500000];

int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n >> m;
    for (int i = 0; i < n; ++i) std::cin >> a[i];
    std::sort(a, a + n);
    for (int l = n - 1, r = n - 1; r >= 0; --r) {
        while (l > r || l && cur + a[r] - a[l - 1] <= m) cur += a[r] - a[--l];
        cmax(ans, r - l + 1);
        cur -= (a[r] - a[r - 1]) * (r - l);
    }
    std::cout << ans;
    return 0;
}