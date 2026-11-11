#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 5e5 + 5;
int a[N], s[N], pre[N], n, m, ans = INT_MIN;

signed main(void) {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    scanf("%lld%lld", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) {
        s[i] = s[i - 1] + a[i];
        if (i != 1) pre[i] = (a[i] - a[i - 1]) * (i - 1) + pre[i - 1];
        else pre[i] = 0;
    }
    int l = 1, r = 1;
    while (l <= r && r <= n) {
        if (pre[r] - a[r] * (l - 1) + s[l - 1] <= m) {
            ans = max(ans, r - l + 1);
            r++;
        } else l++;
    }
    cout << ans;
    return 0;
}
