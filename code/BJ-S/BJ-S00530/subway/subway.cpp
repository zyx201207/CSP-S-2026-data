#include<bits/stdc++.h>

#define lowbit(x) (x&-x)
#define int long long

using namespace std;

namespace cyan
{
    constexpr int N=5e2+2;
    constexpr int M=2e3+5;

    int to[M<<1];
    int head[M<<1];
    int nxt[M<<1];
    int t[M<<1];
    int num=0;

    inline int read()
    {
        int x=0;bool f=0;
        char ch=getchar();
        while(ch<'0' || ch>'9') f^=ch=='-',ch=getchar();
        while(ch<='9' && ch>='0') x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
        return f?-x:x;
    }

    inline int min(int a, int b) {return a<b?a:b;}

    inline int max(int a, int b) {return a>b?a:b;}

    inline void add(int u, int v, int w)
    {
        t[++num]=w;to[num]=v;
        nxt[num]=head[u];head[u]=num;return ;
    }

    inline void insert(int u, int v, int w)
    {
        add(u, v, w);add(v, u, w);return ;
    }
}

using namespace cyan;

priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;

int c,n,m,d,Q;
int wt[N];
int tot=0;
int dis[M][M];
bool vis[N];

void Dijkstra(int st)
{
    memset(dis[st], 0x3f, sizeof(dis[st]));
    memset(vis, 0, sizeof(vis));
    q.emplace(dis[st][st]=0, st);
    int p;
    while(!q.empty())
    {
        p=q.top().second;q.pop();
        if(vis[p]) continue;
        vis[p]=1;
        for(int i=head[p];i;i=nxt[i])
            if(dis[st][p]+t[i]<dis[st][to[i]]) q.emplace(dis[st][to[i]]=dis[st][p]+t[i], to[i]);
    }
    return ;
}

signed main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    c=read();n=read();m=read();d=read();Q=read();
    for(int i=1;i<=m;i++) wt[i]=read();
    int sz;
    int u,v;
    for(int i=1;i<=n;i++)
    {
        sz=read();
        for(int j=1;j<=sz;j++) u=read(),v=read(),insert(u, m+i, v);
    }
    for(int i=1;i<=m;i++) Dijkstra(i);
    while(Q--)
    {
        u=read();v=read();cout<<dis[u][v]+wt[u]+wt[v]<<'\n';
    }

    return 0;
}
