#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<int>g[1000005];
int fa[1000005],dis[1000005],U[1000005],V[1000005],b[1000005],vis[1000005];
int getfa(int x){return x==fa[x]?x:fa[x]=getfa(fa[x]);}
void solve()
{
    int n,k;
    cin>>n>>k;
    if(n<=10)
    {
        for(int i=1;i<=n;i++)g[i].clear();
        for(int i=1;i<n;i++)
        {
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
            U[i]=u;
            V[i]=v;
        }
        int ans=1e18;
        for(int i=1;i<(1<<n);i++)
        {
            if(__builtin_popcount(i)==k)
            {
                for(int j=1;j<=n;j++)b[j]=vis[j]=0,fa[j]=j,dis[i]=1e9;
                for(int j=1;j<=n;j++)if(i>>(j-1)&1)b[j]=1;
                for(int j=1;j<n;j++)
                {
                    if(b[U[j]]&&b[V[j]])
                    {
                        int x=getfa(U[j]),y=getfa(V[j]);
                        if(x!=y)
                        {
                            fa[x]=y;
                        }
                    }
                }
                int yu=0;
                for(int j=1;j<=n;j++)yu+=fa[j]==j&&b[j];
                if(yu<=2)
                {
                    queue<int>q;
                    for(int j=1;j<=n;j++)if(b[j])dis[j]=0,q.push(j),vis[j]=1;
                    while(!q.empty())
                    {
                        int fr=q.front();
                        q.pop();
                        for(int v:g[fr])
                        {
                            if(!vis[v])
                            {
                                q.push(v);
                                dis[v]=dis[fr]+1;
                                vis[v]=1;
                            }
                        }
                    }
                    int yop=0;
                    for(int j=1;j<=n;j++)yop=max(yop,dis[j]);
                    ans=min(ans,yop);
                }
            }
        }
        cout<<ans<<'\n';
    }
    else
    {
    }
}
signed main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int c,T;
    cin>>c>>T;
    while(T--)solve();
    return 0;
}
