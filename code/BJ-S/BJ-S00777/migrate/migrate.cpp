#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
const int INF = 0x3f3f3f3f;
int c , T;
namespace  Target1 {
    const int N = 5e3 + 5;
    struct Node {
        int dis , cnt;
    } dp[N][N];
    int n , d , a[N];
    void Solve() {
        while(T--) {
            cin >> n >> d;
            for(int i = 1;i <= n;i++) cin >> a[i];
            for(int i = 1;i <= n;i++) {
                for(int j = i + 1;j <= n;j++) {
                    dp[i][j] = {INF , 0};
                }
            }
            for(int len = 1;len <= n;len++) {
                for(int i = 1;i <= n;i++) {
                    int j = i + len - 1;
                    if(j > n) break;
                    if(a[j] - a[i] <= d) {
                        dp[i][j] = {1 , 1};
                        continue;
                    }
                    for(int k = i + 1;k < j;k++) {
                        if(dp[i][k].dis + dp[k][j].dis < dp[i][j].dis) {
                            dp[i][j].dis = dp[i][k].dis + dp[k][j].dis;
                            dp[i][j].cnt = dp[i][k].cnt * dp[k][j].cnt;
                        }
                        else if(dp[i][k].dis + dp[k][j].dis == dp[i][j].dis) {
                            dp[i][j].cnt += dp[i][k].cnt * dp[k][j].cnt;
                        }
                    }
                }
            }
            // for(int i = 1;i <= n;i++) {
            //     for(int j = 1;j <= n;j++) {
            //         if(j < i) cout << "NON ";
            //         else cout << dp[i][j].dis << "/" << dp[i][j].cnt << " ";
            //     }
            //     cout << endl;
            // }
            int ans = 0;
            for(int i = 1;i <= n;i++) {
                for(int j = i + 1;j <= n;j++) {
                    if(dp[i][j].dis != 1 && dp[i][j].cnt / (dp[i][j].dis - 1) == 2) ans++;
                }
            }
            cout << ans << endl;
        }
    }
}
signed main() {
    freopen("migrate.in" , "r" , stdin);
    freopen("migrate.out" , "w" , stdout);
    ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
    cin >> c >> T;
    if(c <= 10) Target1::Solve();
    return 0;
}