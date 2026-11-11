#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 5e5 + 5;
int n;
int a[maxn];
ll m, ans;
int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    bool flag = 1;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (i >= 3 && a[i] - a[i - 1] != a[i - 1] - a[i - 2]) flag = 0;
    }
    if (flag) {
        int res = 0;
        while (m >= 0) {
            res++;
            m -= res * (a[n] - a[n - 1]);
        }
        cout << res;
        return 0;
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) {
        ll d = m;
        for (int j = i - 1; j >= 0; j--) {
            if (j == 0) {
                ans = max(ans, (ll)i);
                break;
            }
            if (d >= a[i] - a[j]) d -= a[i] - a[j];
            else {
                ans = max(ans, (ll)(i - j));
                break;
            }
        }
    }
    cout << ans;
    return 0;
}
