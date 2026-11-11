#include <iostream>
#include <algorithm>
#define int long long
using namespace std;
int a[500005], pre[500005];
int n, m;
bool check(int x) {
    for (int i = x; i <= n; i++) {
        if (pre[i] - pre[i - x] - (i - x) * (a[i] - a[i - x]) <= m) {
            return true;
        }
    }
    return false;
}
signed main() {
    #ifndef SELFTEST
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    #endif // SELFTEST
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for (int i = 2; i <= n; i++) {
        pre[i] = pre[i - 1] + (a[i] - a[i - 1]) * (i - 1);
    }
    int l = 0, r = n, ans = 0;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (check(mid)) {
            l = mid + 1;
            ans = mid;
        }
        else r = mid - 1;
    }
    cout << ans << endl;
    return 0;
}
// 100pts
