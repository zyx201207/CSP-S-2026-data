#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e3+10;
int c,T,n,d,x[N],f[N][N],dp[N][N],cnt;
signed main() {
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>c>>T;
    while(T--) {
        cin>>n>>d;
        for(int i=1;i<=n;i++)
            cin>>x[i];
        memset(f,0x3f,sizeof(f));
        memset(dp,0,sizeof(dp));
        cnt=0;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                if(i!=j && abs(x[i]-x[j])<=d)
                    dp[i][j]=f[i][j]=1;
        for(int i=1;i<=n;i++)
            f[i][i]=0;
        for(int k=1;k<=n;k++)
            for(int i=1;i<=n;i++)
                for(int j=1;j<=n;j++) {
                    if(f[i][j]>f[i][k]+f[k][j])
                        dp[i][j]=min(10ll,dp[i][k]*dp[k][j]);
                    else if(f[i][j]==f[i][k]+f[k][j])
                        dp[i][j]=min(10ll,dp[i][j]+dp[i][k]*dp[k][j]);
                    f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
                }
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
                if(dp[i][j]==2)
                    cnt++;
        cout<<cnt<<'\n';
    }
    return 0;
}