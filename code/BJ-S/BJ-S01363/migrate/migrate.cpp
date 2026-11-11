#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=305;
int c,t,n,d,x[N],head[N],pos,dp[N][N],lu[N][N],ans;
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>c>>t;
    while(t--)
    {
        ans=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++) dp[i][j]=0,lu[i][j]=0;
        }
        for(int i=1;i<=n;i++) cin>>x[i];
        for(int l=1;l<=n;l++)
        {
            for(int r=l+1;r<=n;r++)
            {
                if(x[r]-x[l]<=d) dp[l][r]=1;
                else dp[l][r]=1e18;
            }
        }
        for(int l=1;l<=n;l++)
        {
            for(int r=l+1;r<=n;r++)
            {
                if(dp[l][r]<=1) continue;
                for(int k=l+1;k<r;k++)
                {
                    if(dp[l][k]+dp[k][r]<dp[l][r]) dp[l][r]=dp[l][k]+dp[k][r],lu[l][r]=1;
                    if(dp[l][k]+dp[k][r]==dp[l][r]) lu[l][r]++;
                }
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++) if(lu[i][j]>=2) ans++;
        }
        cout<<ans<<"\n";
    }
    return 0;
}