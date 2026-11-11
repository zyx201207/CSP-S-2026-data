#include <bits/stdc++.h>

typedef long long ll;
const int MAXN = 200005;

int n, m;
int a[MAXN];

int main() {
    std::freopen("and.in", "r", stdin);
    std::freopen("and.out", "w", stdout);

    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    std::cin >> n >> m;
    for (int i = 1; i <= n; i++) std::cin >> a[i];

    int ans = 0;

    if (m == 2) {
        for (int i = 1; i < n; i++) {
            for (int j = i + 1; j <= n; j++) {
                ans = std::max(int(a[i] & a[j]), ans);
            }
        }
        std::cout << ans;
    } else if (m == 1) {
        std::sort(a + 1, a + n + 1);
        std::cout << a[n];
    } else if (m == n) {
        ans = a[1];
        for (int i = 2; i <= n; i++) {
            ans += int(ans & a[i]);
        }
        std::cout << ans;
    }

    return 0;
}
