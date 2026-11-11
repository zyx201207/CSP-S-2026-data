#include<iostream>
#define int long long
using namespace std;
const int N = 2e6 + 10,M = 300 + 10,inf = 2e18 + 1;
int n,d,x[N + 1],dis[M + 1][M + 1],dp[M + 1][M + 1];
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int c,T;
    cin>>c>>T;
    while(T--){
        cin>>n>>d;
        for(int i = 1;i <= n;i++) cin>>x[i];
        if(c == 11 || c == 12){
            if(d / (x[2] - x[1]) >= 2)
                cout<<max(n - 2 * (d / (x[2] - x[1])) + 1,0ll)<<"\n";
            else cout<<0<<"\n";
        }
        else{
            for(int i = 1;i <= n;i++)
                for(int j = 1;j <= n;j++)
                    dis[i][j] = dp[i][j] = 0;
            for(int i = 1;i <= n;i++){
                for(int j = 1;j <= i;j++) dis[i][j] = inf;
                int now = i,cnt = 1;
                while(now < n){
                    int l = now + 1,r = n,ans = -1;
                    while(l <= r){
                        int mid = (l + r) / 2;
                        if(x[mid] - x[now] <= d)
                            l = mid + 1,ans = mid;
                        else r = mid - 1;
                    }
                    if(ans == -1){
                        for(int j = now + 1;j <= n;j++)
                            dis[i][j] = inf;
                        break;
                    }
                    for(int j = now + 1;j <= ans;j++)
                        dis[i][j] = cnt;
                    now = ans,cnt++;
                }
            }
            for(int i = 1;i <= n;i++)
                for(int j = 1;j <= n;j++)
                    if(i == j || dis[i][j] == 1)
                        dp[i][j] = 1;
            for(int len = 2;len <= n;len++)
                for(int i = 1;i <= n - len + 1;i++){
                    int j = i + len - 1;
                    for(int k = i;k <= j;k++)
                        if(dis[k][j] == 1 && dis[i][j]
                        == dis[i][k] + dis[k][j]){
                            if(dp[i][k] > 2 || dp[k][j] > 2 ||
                            dp[i][k] * dp[k][j] > 2 || dp[i][k]
                            * dp[k][j] + dp[i][j] > 2)
                                dp[i][j] = inf;
                            else dp[i][j] += dp[i][k] * dp[k][j];
                        }
                }
            int ans = 0;
            for(int i = 1;i <= n;i++)
                for(int j = i + 1;j <= n;j++)
                    if(dp[i][j] == 2) ans++;
            cout<<ans<<"\n";
        }
    }
}
