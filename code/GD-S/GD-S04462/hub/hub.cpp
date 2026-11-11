#include <bits/stdc++.h>
#define int long long 
using namespace std;

int _C,_T;

int n,k;

struct edge
{
    int u,v;
};
vector<edge>G[15];

void add(int u,int v)
{
    G[u].push_back({u,v});
}

bool ins[15];

int cnt,bl[15];

void fillltk(int u,int fa,int id)
{
    bl[u]=id;
    for(int i=0;i<G[u].size();i++)
    {
        int v=G[u][i].v;
        if(v!=fa&&ins[v])
        {
            fillltk(v,u,id);
        }
    }
}

int dis[15];
bool vis[15];
queue<int>q;

void bfs()
{
    for(int i=1;i<=n;i++)
    {
        dis[i]=0;
        vis[i]=0;
    }
    for(int i=1;i<=n;i++)
    {
        if(ins[i])
        {
            dis[i]=0;
            vis[i]=1;
            q.push(i);
        }
    }
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int i=0;i<G[u].size();i++)
        {
            int v=G[u][i].v;
            if(!vis[v])
            {
                vis[v]=1;
                dis[v]=dis[u]+1;
                q.push(v);
            }
        }
    }
}

int calc(int s)
{
    cnt=0;
    for(int i=1;i<=n;i++)
    {
        bl[i]=0;
        ins[i]=0;
    }
    for(int i=1;i<=n;i++)
    {
        if((s>>(i-1))&1)
        {
            ins[i]=1;
            cnt++;
        }
    }
    if(cnt!=k)
    {
        return -2;
    }
    cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(ins[i])
        {
            if(!bl[i])
            {
                fillltk(i,0,++cnt);
            }
        }
    }
    if(cnt>2)
    {
        return -1;
    }
    bfs();
    int res=0;
    for(int i=1;i<=n;i++)
    {
        res=max(res,dis[i]);
    }
    return res;
}

void solve()
{
    scanf("%lld%lld",&n,&k);
    for(int i=1;i<=n;i++)G[i].clear();
    for(int i=1,u,v;i<n;i++)
    {
        scanf("%lld%lld",&u,&v);
        add(u,v);
        add(v,u);
    }
    int ans=1e18;
    for(int i=0;i<(1ll<<n);i++)
    {
        int tmp=calc(i);
        if(tmp>=0)
        {
            ans=min(ans,tmp);
        }
    }
    printf("%lld\n",ans);
}

signed main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);

    scanf("%lld%lld",&_C,&_T);
    while(_T--)
    {
        solve();
    }

    return 0;
}