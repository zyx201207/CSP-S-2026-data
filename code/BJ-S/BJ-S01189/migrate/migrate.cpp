# include <bits/stdc++.h>
using namespace std;
# define int long long
const int MAXN = 2e6 + 10;
int n, d, a[MAXN];
int nxt[MAXN], pre[MAXN];
// int f[MAXN], g[MAXN];
int f[MAXN][2][2], cnt[MAXN], cnt2[MAXN];
void solve(){
    cin >> n >> d;
    for (int i = 1;i <= n; i++) {
        f[i][0][0] = f[i][0][1] = f[i][1][1] = cnt[i] = cnt2[i] = 0;
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        nxt[i] = upper_bound(a + 1, a + n + 1, a[i] + d) - a - 1;
        pre[i] = lower_bound(a + 1, a + n + 1, a[i] - d) - a;
        if (nxt[i] > i) cnt2[nxt[i]]++;
    }
    // for (int i = 1; i <= n; i++) {
    //     cout << nxt[i] << " " ;
    // }
    // cout << endl ;
    int ans = 0;


    for (int i = n; i >= 1; i--) {
        f[i][0][0] += cnt[i];
        f[i][1][1] += cnt[i - 1];
        // 0, ? -> 0
        if (pre[i] < i && nxt[pre[i]] == i) {
            f[pre[i]][0][0] += f[i][0][0];
            f[pre[i]][0][1] += f[i][0][1];
        }
        // 0, 0 -> 1
        if (pre[i] + 1 < i && nxt[pre[i] + 1] == i) {
            f[pre[i] + 1][1][1] += f[i][0][0];
        }
        // 1, 1 -> 0
        if (i > 1 && pre[i - 1] < i - 1 && nxt[pre[i - 1]] == i) {
            f[pre[i - 1]][0][1] += f[i][1][1];
        }

        ans += cnt2[i] * (f[i][0][1] + f[i][1][1]);
        cnt[pre[i]]++;
    }
    // cout << f[5][0][1] << endl ;
    cout << ans << endl ;

    // for (int i = n; i >= 1; i--) {
    //     dep[i] = 0;
    //     for (int j = 1; j <= n; j++) nxt[j] = min(nxt[j], i);
    //     for (int j = i - 1; j >= 1; j--) dep[j] = dep[nxt[j]] + 1; 
    //     t[i] = 0;
    //     for (int j = 1; j < i; j++) {
    //         if (nxt[j - 1] == nxt[j]) {
    //             t[j] = 1;
    //             if (nxt[j - 2] == nxt[j]) t[j] = 2;
    //         } else {
    //             if (dep[j - 1] == dep[j]) t[j] = 2;
    //             else t[j] = 0;
    //         }
    //     }
    //     for (int j = 1; j <= i; j++) f[j] = g[j] = 0;
    //     for (int j = 1; j < i; j++) {
    //         f[j]++;
    //         // if (nxt[j] == j) continue;
    //         if (t[nxt[j]] == 0) f[nxt[j]] += f[j], g[nxt[j]] += g[j];
    //         else if (t[nxt[j]] == 1) g[nxt[j]] += f[j];
    //     }
    //     ans += g[i];
    //     // if (i == 4) cout << g[i] << " " << f[2] << " " << g[3] << endl ;
    //     // if (i == n) cout << g[i] << " " << f[2] << " " << g[3] << endl ;
    //     // cout << g[i] << endl ;
    // }
    // cout << ans << endl ;
}  
signed main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int c , t;
    cin >> c >> t;
    while (t--) {
        solve();
    }
    return 0;
}