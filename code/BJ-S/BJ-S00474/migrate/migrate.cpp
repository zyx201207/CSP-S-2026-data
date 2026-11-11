#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
const int maxn = 2e6 + 10;
const int inf = 0x3f3f3f3f3f3f3f3f;
int c, t, n, d, a[maxn], ans;
pii f[maxn]; // first -> min  second -> times
inline void init() {
    for (int i = 1; i <= n; i++) a[i] = 0;
    ans = 0;
}
signed main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> c >> t;
    while (t--) {
        init();
        cin >> n >> d;
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int k = 1; k <= n; k++) {
            f[k] = {0, 1};
            for (int i = k + 1; i <= n; i++) {
                f[i] = {inf, 0};
                int lst = i;
                while (lst > k) {
                    if (a[i] - a[lst - 1] <= d) {
                        lst--;
                        if (f[lst].first + 1 < f[i].first) f[i] = f[lst], f[i].first++;
                        else if (f[lst].first + 1 == f[i].first) f[i].second += f[lst].second;
                    } else break;
                }
                // cout << f[i].first << "." << f[i].second << " ";
                if (f[i].second == 2) ans++;
            }
            // cout << "\n";
        }
        cout << ans << "\n";
    }
    return 0;
}