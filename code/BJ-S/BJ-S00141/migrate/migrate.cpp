#include <iostream>
#include <algorithm>
#define int long long
using namespace std;
constexpr int N=5003;
int a[N];
int dis[N][N],g[N][N];
int c;
void solve()
{
    int n,d;
    cin>>n>>d;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    if (c==13||c==14) // c==13/14
    {
        int x=a[n]-a[1];
        if (x&1)
        {
            if (d==(x+1)/2) return cout<<"1\n",void();
        }
        else if (d==x/2) return cout<<"2\n",void();
        cout<<"0\n";
        return;
    }
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=n;j++)
        {
            g[i][j]=0;
            dis[i][j]=1e18;
        }
        g[i][i]=1;
        dis[i][i]=0;
    }
    int ans=0;
    for (int k=1;k<=n;k++)
    {
        for (int j=1;j<=n;j++)
        {
            for (int i=j+1;i<=n;i++)
            {
                if (a[i]-d>a[k]) break;
                if (dis[j][k]+1<dis[j][i])
                {
                    g[j][i]=g[j][k];
                    dis[j][i]=dis[j][k]+1;
                }
                else if (dis[j][k]+1==dis[j][i])
                {
                    g[j][i]+=g[j][k];
                }
            }
            // cout<<j<<" "<<i<<" "<<g[j][i]<<'\n';
        }
    }
    for (int i=1;i<=n;i++)
    {
        for (int j=i+1;j<=n;j++)
        {
            if (g[i][j]==2) ans++;
        }
    }
    cout<<ans<<'\n';
}
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>c>>t;
    while (t--)
    {
        solve();
    }
}
