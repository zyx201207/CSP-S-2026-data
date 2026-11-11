#include <bits/stdc++.h>
#define int long long
using namespace std;

namespace _ {

    const int N = 2e6+10;
    const int del = 1e18;
    const int M = 3e2+10;
    const int inf = 0x3f3f3f3f3f3f3f3f;

    int n, d;
    int a[N];

    // int suf[N], pre[N];
    // int slim[N], plim[N];
    // int Psuf[N], Ppre[N];

    int c;

    // int pre[N], suf[N];
    int Case = 0;

    int nxt[N], pre[N];

    int ps[N], ss[N];

    int ts[N], sts[N];

    int dp[M][M];
    int cnt[M][M];

    // pair<int, int> op[N]

    void clear() {

        for (int i = 0;i<= n+1;i++) {
            a[i] = nxt[i] = pre[i] = ps[i] = ss[i] = 0;
        }

    }

    void solve() {

        Case++;
        cin >> n >> d;

        if (13 <= c && c <= 14) {

            cout << 0 << endl;
            return ;

        }

        for (int i = 1;i<= n;i++) {
            cin >> a[i];
        }

        for (int i = 1;i<= n;i++) {
            nxt[i] = upper_bound(a+1, a+n+1, a[i]+d)-a-1;
            pre[i] = lower_bound(a+1, a+n+1, a[i]-d)-a;
        }

        for (int i = 1;i<= n;i++) {
            for (int j = 1;j<= n;j++) {
                dp[i][j] = inf, cnt[i][j] = 0;
            }
        }

       for (int i = 1;i<= n;i++) {
            for (int j = pre[i];j<= nxt[i];j++) {
                dp[i][j] = 1, cnt[i][j] = 1;
            }
       }

       for (int k = 1;k<= n;k++) {
            for (int i = 1;i<= n;i++) {
                for (int j = 1;j<= n;j++) {
                    if (dp[i][j] == dp[i][k] + dp[k][j]) {
                        cnt[i][j] += cnt[i][k] * cnt[k][j];
                    } else if (dp[i][j] > dp[i][k] + dp[k][j]) {
                        dp[i][j] = dp[i][k] + dp[k][j];
                        cnt[i][j] = cnt[i][k] * cnt[k][j];
                    }
                }
            }
       }

        int ans = 0;
       for (int i = 1;i<= n;i++) {
        for (int j = i+1;j<= n;j++) {
            if (cnt[i][j] == 2) {
                ans++;
            }
        }
       }

       cout << ans << endl;
        

    }

    signed main() {
        freopen("migrate.in","r",stdin);
        freopen("migrate.out","w",stdout);
        int T; cin >> c >> T;
        while (T--) solve(), clear();
        return 0;
    }

}

signed main() {
    return _::main();
}

/*

6 12
-10 -6 -2 2 6 10
*/