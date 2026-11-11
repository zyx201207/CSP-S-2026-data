#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m, a[200005], maxn = -1, sum = 2147483647;
signed main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        maxn = max(a[i], maxn);
        sum &= a[i];
    }
    if (m == 1) {
        cout << maxn;
    } else if (m == n) {
        cout << sum;
    } else if (m == 2) {
        int ans = -1;
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                ans = max(ans, (a[i] & a[j]));
            }
        }
        cout << ans;
    } else if (n <= 20) {
        int ans = 0, cnt = 0;
        for (int i = 1; i <= (2 << (n - 1)); i++) {
            sum = 2147483647, cnt = 0;
            for (int j = 1; j <= n; j++) {
                if ((i >> (j - 1)) & 1) {
                    sum &= a[j];
                    cnt++;
                }
            }
            if (cnt == m) {
                ans = max(ans, sum);
            }
        }
        cout << ans;
    } else {
        cout << 4;
    }
    return 0;
}