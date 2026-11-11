#include <bits/stdc++.h>

#define FI
#define FO

int main() {
#define int long long
    constexpr int inf = 0x3f3f3f3f3f3f3f3f;
#ifdef FI
    std::ifstream fin("crystal.in");
#else
#define fin std::cin
#endif
#ifdef FO
    std::ofstream fout("crystal.out");
#else
#define fout std::cout
#endif
    int n, m;
    fin >> n >> m;
    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        fin >> a.at(i);
    }
    std::sort(a.begin() + 1, a.end());
    int sum = a.at(1);
    int ans = 1;
    int left = 1, right = 1;
    while (right < n) {
        while (right < n && a.at(right) * (right - left + 1) - sum <= m) {
            sum += a.at(++right);
        }
        ans = std::max(ans, right - left);
        while (left <= right + 1 && a.at(right) * (right - left + 1) - sum > m) {
            sum -= a.at(left++);
        }
    }
    fout << ans << "\n";
    return 0;
}
