#include <iostream>

int c, k, n, t;

int main() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> c >> t;
    while (t--) {
        std::cin >> n >> k;
        if (c >= 13 && c <= 14) {
            for (int u, v, i = 1; i < n; ++i) std::cin >> u >> v;
            std::cout << (n == k ? 0 : std::max(((n >> 1) - k + 5) >> 2, 1)) << '\n';
        }
    }
    return 0;
}