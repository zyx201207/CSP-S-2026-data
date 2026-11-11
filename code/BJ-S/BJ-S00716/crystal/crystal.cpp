#include <bits/stdc++.h>
using namespace std;

#define int long long

int n, m, a[500005], sum[500005];

signed main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; ++i) sum[i] = sum[i - 1] + a[i];
    int ans = 1;
    for (int i = 1; i <= n; ++i) {
        int l = 1, r = i - 1, ans1 = i;
        while(l <= r) {
            int mid = (l + r) >> 1;
            if((i - mid) * a[i] - sum[i - 1] + sum[mid - 1] <= m) {
                ans1 = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        ans = max(ans, i - ans1 + 1);
    }
    cout << ans;
    return 0;
}
