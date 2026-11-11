#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
int a[301],dp[301][301][301],f[301][301][301];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int c,t;
    cin>>c>>t;
    while(t--)
    {
        int ans=0;
        memset(dp,0x3f,sizeof(dp));
        memset(f,0,sizeof(dp));
        int n,d;
        cin>>n>>d;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(a[i]-a[j]<=d && a[i]-a[j]>=-d)
                {
                    dp[i][j][0]=1;
                    f[i][j][0]=1;
                }
                if(i==j)
                {
                    dp[i][j][0]=0;
                }
            }
        }
        for(int k=1;k<=n;k++)
        {
            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=n;j++)
                {
                    dp[i][j][k]=min(dp[i][j][k-1],dp[i][k][k-1]+dp[k][j][k-1]);
                }
                for(int j=1;j<=n;j++)
                {
                    if(dp[i][j][k]==dp[i][j][k-1]) f[i][j][k]+=f[i][j][k-1];
                    if(dp[i][j][k]==dp[i][k][k-1]+dp[k][j][k-1] && i!=j && j!=k && i!=k) f[i][j][k]+=(f[i][k][k-1]*f[k][j][k-1]);
                }
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(f[i][j][n]==2) ans++;
                cerr<<f[i][j][n]<<" \n"[j==n];
            }
        }
        cout<<ans/2<<endl;
    }
    cout<<flush;
    return 0;
}
