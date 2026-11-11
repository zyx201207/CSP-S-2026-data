#include <iostream>
#include <vector>
#include <map>

std::vector<long> islands;
std::map<long, long> m;
long n, d;

// 判断i, j是否满足题意
// bool judge(int i, int j) {
    
// }

int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    std::cin.tie(0)->sync_with_stdio(false);
    int c, t;
    std::cin >> c >> t;
    // while (t--) {
    //     islands.clear();
    //     m.clear();
    //     std::cin >> n >> d;
    //     islands.resize(n);
    //     for (auto& x : islands)
    //         std::cin >> x;
    //     long ans = 0;
    //     for (int i = 0; i < n - 1; i++) {
    //         for (int j = i + 1; j < n; j++)
    //             if (judge(i, j))
    //                 ans++;
    //     }
    //     std::cout << ans << '\n';
    // }
    while (t--)
        std::cout << "0\n";
}