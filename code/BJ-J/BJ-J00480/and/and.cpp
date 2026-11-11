#include<bits/stdc++.h>

std::vector<long long> a;

int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    int n, m;
    std::cin >> n >> m;
    for (int i = 1;i <= n;i++) {
        int x;
        std::cin >> x;
        a.push_back(x);
    }
    std::sort(a.begin(), a.end());
    long long ans = a.back();
    for (int i = 1;i < m;i++) {
        ans &= a[a.size() - i - 1];
    }
    if (ans == 0) {
        ans = a.back() & a[a.size() - 3];
        for (int i = 3;i < m;i++) {
            ans &= a[a.size() - i - 1];
        }
    }
    std::cout << ans;
    return 0;
}