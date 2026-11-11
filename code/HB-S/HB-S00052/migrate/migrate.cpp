#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll a[2000005];
pair<ll,int> dp[5005][5005];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int c,t;
    cin>>c>>t;
    while(t--){
        int n,ans=0;
        ll d;
        cin>>n>>d;
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++) dp[i][j].first=1e8;
        }
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
                int r=j+1;
                dp[i][j].first=0;
                while(a[j]+d>a[r]&&r<=n){
                    if(dp[i][r].first>dp[i][j].first+1){
                        dp[i][r].first=dp[i][j].first+1;
                        dp[i][r].second=1;
                    }else if(dp[i][r].first==dp[i][j].first+1) dp[i][r].second++;
                    r++;
                }
            }
        }
        cout<<ans<<'\n';
        memset(dp,0,sizeof(dp));
    }
    return 0;
}
