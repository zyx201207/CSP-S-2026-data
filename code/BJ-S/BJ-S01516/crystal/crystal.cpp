#include <bits/stdc++.h>

typedef long long ll;

const int N = 5e5 + 10;

ll a[N], m, sum[N];
int n, ans;

FILE *IG;

int main() {
    IG = freopen("crystal.in", "r", stdin);
    IG = freopen("crystal.out", "w", stdout);
    
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }

    std::sort(a + 1, a + n + 1);

    for (int i = 1; i <= n; i++) {
        sum[i] = sum[i - 1] + a[i];
    }

    for (int i = 1; i <= n; i++) {
        int l = 1, r = i, cur = i;

        while (l <= r) {
            int mid = (l + r) >> 1;

            if (1LL * (i - mid) * a[i] - (sum[i - 1] - sum[mid - 1]) <= m) {
                cur = mid;
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }

        ans = std::max(ans, i - cur + 1);
    }

    std::cout << ans;
    return 0;
}