#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    std::cin.tie(0)->sync_with_stdio(false);
    long n, m;
    std::cin >> n >> m;
    std::vector<long> a(n);
    long max_abs_a = -1;
    for (auto& x : a) {
        std::cin >> x;
        max_abs_a = std::max(max_abs_a, std::abs(x));
    }
    std::sort(a.begin(), a.end());
    // 测试点1 ~ 9: 从右边起向左遍历，累加答案
    if (n <= 5000) {
        long ans = 1;
        for (long r = n - 1; r > 0; r--) {
            long cost = 0, cnt = 0;
            for (long l = r - 1; l >= 0; l--) {
                if (a[r] - a[l] <= m - cost) {
                    cost += a[r] - a[l];
                    cnt++;
                }
            }
            ans = std::max(ans, cnt);
        }
        std::cout << ans + 1 << '\n';
    }
    // 特殊性质A, B(等差数列): 从右边起向左遍历，逐个进行操作
    // else if (m > (int)1e8) {
    else {
        long ans = 1;
        for (long r = n - 1; r > 0; r--) {
            if (m >= a[r] - a[r - 1]) {
                m -= a[r] - a[r - 1];
                a[r - 1] = a[r];
                ans++;
            }
            else
                break;
        }
        std::cout << ans << '\n';
    }
    // 测试点10 ~ 12: |数列中绝对值最大的数| <= 100
    // else if (max_abs_a <= 100) {
    //     long ans = 1;
    //     for (long r = n - 1; r > 0; r--) {
    //         if (m >= a[r] - a[r - 1]) {
    //             m -= a[r] - a[r - 1];
    //             a[r - 1] = a[r];
    //             ans++;
    //         }
    //         else
    //             break;
    //     }
    //     std::cout << ans << '\n';
    // }
    // // 测试点19, 20
    // else {
    //     long ans = 1;
    //     for (long r = n - 1; r > 0; r--) {
    //         if (m >= a[r] - a[r - 1]) {
    //             m -= a[r] - a[r - 1];
    //             a[r - 1] = a[r];
    //             ans++;
    //         }
    //         else
    //             break;
    //     }
    //     std::cout << ans << '\n';
    // }
}