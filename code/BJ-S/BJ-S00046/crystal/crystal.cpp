#include <bits/stdc++.h>

typedef long long ll;
const int MAXN = 5000005;

int n, m;
ll a[MAXN];

ll jd(int a) {
    return a >= 0 ? a : a * -1;
}

int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    std::cin >> n >> m;
    for (int i = 1; i <= n; i++) std::cin >> a[i];

    std::sort(a + 1, a + n + 1);

    int ans = 1;

    for (int i = 2; i <= n; i++) {
        int nowA = a[i];
        int currM = m;
        int tempAns = 1;

        int j = i - 1;
        while (currM >= 0 && j >= 1) {
            ll chaju = nowA - a[j];
            currM -= chaju;
            if (currM >= 0) tempAns++;
            j--;
        }

        ans = std::max(tempAns, ans);
    }

    std::cout << ans;

    return 0;
}
