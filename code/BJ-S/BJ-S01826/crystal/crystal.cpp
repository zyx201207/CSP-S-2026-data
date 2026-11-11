#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 5;
int n, m, ans, a[N], sum[N];
signed main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
    int l = 1, sum = 0;
    for (int i = 1; i <= n; i++) {
        while (l <= i && sum > m) sum -= a[i] - a[l++];
        ans = max(ans, i - l + 1);
        if (i < n) sum += (a[i + 1] - a[i]) * (i - l + 1);
    }
    cout << ans;
    return 0;
}
