#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e3+10;
int c,T,n,d;
int x[N],dp[N][N],t[N][N];
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>c>>T;
    while(T--){
        memset(dp,0,sizeof dp);
        memset(t,0x3f,sizeof t);
        cin>>n>>d;
        for(int i=1;i<=n;i++) cin>>x[i];
        int ans=0;
        for(int len=1;len<=n;len++){
            for(int i=1;i+len-1<=n;i++){
                int j=i+len-1;
                if(x[j]-x[i-1]<=d){
                    dp[i][j]=1;
                    t[i][j]=1;
                    continue;
                }
                for(int k=i+1;k<=j-1;k++) t[i][j]=min(t[i][j],t[i][k]+t[k][j]);
                for(int k=i+1;k<=j-1;k++) if(t[i][k]+t[k][j]==t[i][j]) dp[i][j]+=dp[i][k]*dp[k][j];
                ans+=(dp[i][j]==2);
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}