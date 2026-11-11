#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 5e5 + 10;
const int inf = 0x3f3f3f3f3f3f3f3f;
int n, m, a[maxn], pre[maxn], ans = 1;
signed main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) pre[i] = pre[i - 1] + a[i];
    for (int i = 1; i <= n; i++) {
        int l = 1, r = i - 1, res = inf;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (a[i] * (i - mid) - (pre[i - 1] - pre[mid - 1]) <= m) r = mid - 1, res = mid;
            else l = mid + 1;
        }
        if (res != inf) ans = max(ans, i - res + 1);
    }
    cout << ans << "\n";
    return 0;
}