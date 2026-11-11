#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<int>g[2000005];
int x[2000005];
int dis[2000005],cnt[2000005];
int vis[2000005];
void solve()
{
    int n,d,ans=0;
    cin>>n>>d;
    for(int i=1;i<=n;i++)cin>>x[i],g[i].clear();
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            if(x[j]-x[i]<=d)g[i].push_back(j),g[j].push_back(i);
        }
    }
    for(int yd=1;yd<=n;yd++)
    {
        for(int i=1;i<=n;i++)dis[i]=1e18,cnt[i]=0,vis[i]=0;
        vis[yd]=1;
        dis[yd]=0;
        cnt[yd]=1;
        queue<int>q;
        q.push(yd);
        while(!q.empty())
        {
            int u=q.front();
            q.pop();
            for(int v:g[u])
            {
                if(dis[v]==dis[u]+1)cnt[v]+=cnt[u];
                if(!vis[v])
                {
                    q.push(v);
                    vis[v]=1;
                    cnt[v]=cnt[u];
                    dis[v]=dis[u]+1;
                }
            }
        }
        for(int k=yd+1;k<=n;k++)ans+=cnt[k]==2;
    }
    cout<<ans<<'\n';
}
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int c,T;
    cin>>c>>T;
    while(T--)solve();
    return 0;
}
