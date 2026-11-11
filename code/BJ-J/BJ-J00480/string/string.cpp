#include <bits/stdc++.h>

int a[200001];
char c[100001];

long long check(std::string s) {
    long long cnt = 0;
    long long l = 1, r = s.size() - 1;
    while (l < r) {
        if (s[l] != s[r]) {
            cnt++;
        }
        l++;r--;
    }
    return cnt;
}

int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    int n;
    std::string s;
    s += '0';

    std::cin >> n;
    for (int i = 1;i <= n;i++) {
        std::cin >> a[i];
        std::cin >> c[i];
    }
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= a[i];j++) {
            s += c[i];
        }
    }

    long long ans = check(s);
    std::cout << ans;
    return 0;
}
