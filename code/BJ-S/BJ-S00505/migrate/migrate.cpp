#include<bits/stdc++.h>
const long long N=2e6+5;
long long x[N],c,t,n,d,ans,vis[N],dis[N];
void solve()
{
    std::cin >> n >> d;
    for(int i=1;i<=n;++i)
        std::cin >> x[i];
    ans=0;
    for(int i=1;i<n;++i)
    {
        std::memset(vis,0,sizeof vis);
        std::memset(dis,0,sizeof dis);
        for(int j=i+1;j<=n;++j)
        {
            if(x[j]-x[i]<=d)
                vis[j]=dis[j]=1;
            else
            {
                if(x[j]-x[j-1]>d)break;
                long long sum=0,dt=1e18;
                for(int i=j-1;x[j]-x[i]<=d&&i>=1;i--)
                {
                    if(dis[i]<dt)
                    {
                        dt=dis[i];
                        sum=vis[i];
                    }
                    else sum+=vis[i];
                }
                vis[j]=sum;
                dis[j]=dt+1;
            }
            if(vis[j]==2)
                ans++;
        }
    }
    std::cout << ans << '\n';
    return ;
}
int main()
{
    std::freopen("migrate.in","r",stdin);
    std::freopen("migrate.out","w",stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);std::cout.tie(0);
    std::cin >> c >> t;
    while(t--)
        solve();
    return 0;
}
