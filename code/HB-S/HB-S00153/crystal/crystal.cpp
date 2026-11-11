#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5;
int a[N + 5];
signed main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    int sum = 0, ans = 1;
    int r = 1;
    for (int l = 1; l <= n; l ++) {
        while (r <= n && sum <= m) {
            r ++;
            sum += (a[r] - a[r - 1]) * (r - l);
        }
        sum -= (a[r] - a[r - 1]) * (r - l);
        r --;
        ans = max(ans, r - l + 1);
        // cerr << l << " " << r << endl;
        sum -= a[r] - a[l];
    }
    cout << ans;
    return 0;
}