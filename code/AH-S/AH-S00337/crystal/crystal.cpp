#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 55;
int n, m, a[N], sum[N];
signed main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int L = 1, R = i, s = i;
        while (L <= R) {
            int mid = (L + R) / 2;
            int u = sum[i] - sum[mid - 1];
            int len = i - mid + 1;
            int tot = len * a[i] - u;
            if (tot <= m) {
                s = mid;
                R = mid - 1;
            } else L = mid + 1;
        }
        ans = max(ans, i - s + 1);
    }
    cout << ans;
    return 0;
}
