#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, m;
int a[200005];
int ans = 0;

void dfs(int now, int res, int cnt) {
    if (cnt > m) return;
    if (n - now + 1 + cnt < m) return;
    if (now > n || cnt == m) {
        ans = max(ans, res);
        return;
    }
    dfs(now + 1, res & a[now], cnt + 1);
    dfs(now + 1, res, cnt);
}

signed main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    int mx = 0;
    bool fA = 1;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        mx = max(mx, a[i]);
        if (__lg(a[i] + 1) != (int)(__lg(a[i] + 1))) fA = 0;
    }
    if (fA) {
        sort(a + 1, a + n + 1);
        cout << a[m] << "\n";
        return 0;
    }
    if (mx <= 1048576) {
        for (int res = mx; res >= 0; res--) {
            int cnt = 0;
            for (int i = 1; i <= n; i++) {
                bool f = 1;
                for (int t = 0; (1 << t) <= res; t++) {
                    if ((res & (1 << t)) == (1 << t) && (a[i] & (1 << t)) != (1 << t)) {
                        f = 0;
                        break;
                    }
                }
                cnt += f;
                if (cnt >= m) {
                    cout << res << "\n";
                    return 0;
                }
            }
            if (cnt >= m) {
                cout << res << "\n";
                return 0;
            }
        }
        cout << 0 <<"\n";
        return 0;
    }
    dfs(1, LLONG_MAX, 0);
    cout << ans << "\n";
    return 0;
}
