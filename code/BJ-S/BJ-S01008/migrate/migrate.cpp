#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
long long ans,n,m,a[500001],b[500001];
int c,t;
long long dp[5001][5001],cnt[5001][5001];
bool vis[5001][5001];
void solve(){
    cin>>n>>m;
    memset(dp,0x3f3f3f,sizeof(dp));
    memset(cnt,0,sizeof(cnt));
    for (int i=1;i<=n;i++){
        cin>>a[i];dp[i][i]=0;
        cnt[i][i]=1;
    }
    for (int i=1;i<=n;i++){
        for (int j=i+1;j<=n;j++){
            if (a[j]-a[i]<=m){
                dp[i][j]=1;cnt[i][j]=1;vis[i][j]=1;
            }
        }
    }
    for (int k=1;k<=n;k++){
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){

                if (dp[i][j]>dp[i][k]+dp[k][j]&&i!=j&&!vis[i][j]){
                    dp[i][j]=dp[i][k]+dp[k][j];
                    cnt[i][j]=1;
                }
            }
        }
    }
    for (int k=1;k<=n;k++){
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){

                if (dp[i][j]==dp[i][k]+dp[j][k]&&!vis[i][j]){
                    cnt[i][j]+=cnt[i][k]*cnt[j][k];
                }
            }
        }
    }
    ans=0;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
                cout<<cnt[i][j]<<" ";
            if (cnt[i][j]==2)ans++;
        }
        cout<<endl;
    }
    cout<<ans<<endl;
    return ;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while (t--)solve();
    return 0;
}
