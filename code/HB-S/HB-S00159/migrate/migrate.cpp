#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[2000002], f[2000001], dp[2000001][2];
signed main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    int c, t, n, d, ans;
    cin >> c >> t;
    while(t--){
        cin >> n >> d;
        for(int i = 1; i <= n; i++)scanf("%lld", a + i);
        a[n + 1] = 0x7f7f7f7f7f7f7f7fll;
        for(int i = 1; i <= n; i++)a[i] = upper_bound(a + i, a + n + 2, a[i] + d) - a - 1;
        ans = dp[n][0] = dp[n][1] = 0;
        for(int i = n - 1; i >= 1; i--){
            if(a[i] == i)dp[i][0] = dp[i][1] = 0;
            else if(a[a[i] - 1] == a[a[i]]){
                dp[i][0] = 0;
                dp[i][1] = a[a[i] - 1] - max(a[a[i] - 2], a[i]);
                if(a[a[i] - 2] < a[a[i]])dp[i][1] += dp[a[i]][0];
            }else{
                dp[i][0] = dp[a[i]][0] + a[a[i]] - max(a[a[i] - 1], a[i]);
                dp[i][1] = a[a[a[i]] - 1] - max(a[max(a[a[i]] - 2, a[a[i] - 1])], a[a[i]]) + a[a[i] - 1] - max(a[a[i] - 2], a[i]);
                if(a[a[a[i] - 1]] < a[a[a[i]]])dp[i][1] += dp[a[i]][1] - a[a[a[i]] - 1] + max(a[a[a[i]] - 2], a[a[i]]);
            }
            ans += dp[i][1];
        }
        cout << ans << "\n";
    }
    return 0;
}

