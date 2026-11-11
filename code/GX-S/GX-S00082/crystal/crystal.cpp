#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using u64 = unsigned long long;

constexpr i64 N = 5e5 + 6;

i64 n, m;
i64 a[N], sum[N];
i64 ans;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + 1 + n);
    sum[1] = a[1];
    for (int i = 2; i <= n; i++) sum[i] = sum[i - 1] + a[i];
    for (int i = 1; i <= n; i++) {
        i64 l = 1, r = i, mid, ret = -1;
        while (l <= r) {
            mid = (l + r) >> 1;
            if (mid * a[i] - (sum[i] - sum[i - mid]) <= m) {
                ret = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        ans = max(ans, ret);
    }
    cout << ans << '\n';

    return 0;
}