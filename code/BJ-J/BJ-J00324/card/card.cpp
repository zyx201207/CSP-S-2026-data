#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 10;
int a[N], g[N], ans[N], s[N];
signed main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    int n, m;cin >> n >> m;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        s[a[i]] = i;
    }
    for (int i = 1; i <= n; i ++) {
        memset(g, 0, sizeof g);
        int l = n + 1, r = 1;
        for (int j = i; j <= n; j ++) {
            if (g[a[j]] == 0) {
                g[a[j]] = j;
                continue;
            }
            if (!(l <= g[a[j]] && g[a[j]] <= r)) r = max(r, j - 1);
            l = min(l, g[a[j]]);
            g[a[j]] = j;
        }
        for (int j = 1; j <= m; j ++) {
            if (!(l <= g[j] && g[j] <= r) && s[j] >= i) ans[j] ++;
        }
    }
    for (int i = 1; i <= m; i ++) cout << ans[i] << ' ';
    return 0;
}
