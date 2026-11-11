#include <iostream>
#include <cstdio>
#include <array>
#include <algorithm>

using ll = long long;

constexpr int MAXN{500010};

int n; ll m;
std::array<ll, MAXN> a;

std::array<ll, MAXN> sum;

void input() {
    std::cin >> n >> m;
    for (int i{1}; i <= n; i++) {
        std::cin >> a[i];
    }
}

void init() {
    std::sort(a.begin()+1, a.begin()+n+1);
    for (int i{1}; i <= n; i++) {
        sum[i] = sum[i-1] + a[i];
    }
}

void work() {
    init();
    int l{1}, r{0}, ans{0};
    while (l <= n) {
        while (r+1 <= n && m >= a[r+1]*(r-l+2)-(sum[r+1]-sum[l-1])) {
            r++;
        }
        ans = std::max(ans, r - l + 1);
        l++;
    }
    std::cout << ans << "\n";
}

auto main() -> int {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out","w",stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    input();
    work();
    return 0;
}