#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e3+7,oo=2e18;

int c,n,m,t,d,ans;
int x[N];
int sum[N][N],dp[N][N];

void init(){
    ans=0;
    memset(sum,0,sizeof(sum));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            dp[i][j]=oo;
            sum[i][j]=1;
        }
    }
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        init();
        for(int i=1;i<=n;i++)cin>>x[i];
        for(int i=2;i<=n;i++){
            if(x[i]-x[i-1]<=d){
                dp[i-1][i]=sum[i-1][i]=1;
            } else dp[i-1][i]=-1;
        }
        for(int l=3;l<=n;l++){
            for(int i=1;l+i-1<=n;i++){
                int j=l+i-1;
                if(x[j]-x[i]<=d){
                    dp[i][j]=sum[i][j]=1;
                    continue;
                }
                for(int k=i+1;k<=j-1;k++){
                    if(dp[i][k]==-1||dp[k][j]==-1)continue;
                    if(dp[i][k]+dp[k][j]<dp[i][j]){
                       dp[i][j]=dp[i][k]+dp[k][j];
                       sum[i][j]=1;
                    }
                    else if(dp[i][j]==dp[i][k]+dp[k][j])sum[i][j]++;
                }
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(sum[i][j]==2)ans++;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}