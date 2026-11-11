#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,dis[1010];
bool f[1010];
vector<int> g[1000010];
void dfs1(int x,int fa)
{
    f[x]=false;
    for(int to:g[x])
    {
        if(to==fa) continue;
        if(f[to]) dfs1(to,x);
    }
}
void dfs2(int x,int fa)
{
    for(int to:g[x])
    {
        if(to==fa) continue;
        dis[to]=dis[x]+1;
        dfs2(to,x);
    }
}
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>c>>t;
    while(t--)
    {
        cin>>n>>k;
        for(int i=1;i<=n;i++)
            g[i].clear();
        for(int i=1;i<n;i++)
        {
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        if(n<=10)
        {
            int ans=1e9;
            for(int msk=0;msk<(1<<n);msk++)
            {
                int c=0;
                for(int j=1;j<=n;j++)
                    if((msk>>j-1)&1) c++;
                if(c!=k) continue;
                memset(f,0,sizeof(f));
                for(int j=1;j<=n;j++)
                    if((msk>>j)&1) f[j]=true;
                c=0;
                for(int j=1;j<=n;j++)
                    if(f[j])
                    {
                        dfs1(j,0);
                        c++;
                    }
                if(c>2) continue;
                int ma=0;
                for(int j=1;j<=n;j++)
                {
                    dis[j]=0;
                    dfs2(j,0);
                    int mi=1e9;
                    for(int x=1;x<=n;x++)
                        if((msk>>x)&1)
                            mi=min(mi,dis[x]);
                    ma=max(ma,mi);
                }
                ans=min(ans,ma);
            }
            cout<<ans<<"\n";
            continue;
        }
    }
    return 0;
}
