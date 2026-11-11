#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = l; i <= r; i++)
#define OI
using namespace std;

const int N = 2e6 + 10;
int c, t, n, d, ans, minn = 2147483647, tot;
int a[N];
void dfs(int u, int ed, int cnt) {
    if (u == ed) {
        if (cnt == minn) tot++;
        if (cnt < minn) {
            minn = cnt;
            tot = 1;
        }
    }
    rep (i, u + 1, ed) {
        if (a[i] - a[u] <= d) dfs(i, ed, cnt + 1);
        else break;
    }
    return ;
}
int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
#ifdef OI
    freopen ("migrate.in", "r", stdin);
    freopen ("migrate.out", "w", stdout);
#endif
    cin >> c >> t;
    while (t--) {
        cin >> n >> d;
        rep (i, 1, n) cin >> a[i];
        ans = false;
        rep (i, 1, n) {
            rep (j, i + 1, n) {
                tot = 0;
                minn = 2147483647;
                dfs(i, j, false);
                if (tot == 2) ans++;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
