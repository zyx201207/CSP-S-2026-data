#include <bits/stdc++.h>
using namespace std;

long long n, m, ans = 1;
long long a[500005], sum[500005];

int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    sort(&a[1], &a[n + 1]);

    for (int i = 1; i <= n; i++) {
        sum[i] = sum[i - 1] + a[i];
    }

    for (int i = 2; i <= n; i++) {
        long long L = 0, R = i - 1;

        while (L < R) {
            long long mid = (L + R) / 2;

            if (a[i] * (i - mid + 1ll) - (sum[i - 1] - sum[mid]) <= m) {
                R = mid;
            } else {
                L = mid + 1;
            }
        }

        ans = max(ans, i - L + 1ll);
    }

    cout << ans << endl;

    return 0;
}