#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxm = 1e3+50;
const int maxn = 500+50;
int read()
{
    int f = 1,k = 0;
    char c = getchar();
    while(c<'0'||c>'9')
    {
        if(c=='-') f = -1;
        c = getchar();
    }
    while(c>='0'&&c<='9')
    {
        k = k*10+c-'0';
        c = getchar();
    }
    return f*k;
}
struct Edge{
    int idv,ldv,nxt,w;
}edge[1000*maxm];
struct Node{
    int id,ld,d;
    bool operator <(const Node &other) const {
        return other.d < d;
    }
};
int dis[maxm][maxn],ans[maxm][maxn],head[maxm][maxn],cnt;
int c,n,m,d,q,a[maxm];
bool vis[maxm][maxn];
priority_queue <Node> pq;
void add(int idu,int ldu,int idv,int ldv,int w)
{
    edge[++cnt]={idv,ldv,head[idu][ldu],w};
    head[idu][ldu] = cnt;
}
void dij(int s)
{
    memset(dis,0x3f3f3f3f,sizeof(dis));
    memset(vis,0,sizeof(vis));
    dis[s][0] = 0;
    pq.push({s,0,0});
    while(!pq.empty())
    {
        Node S = pq.top();pq.pop();
        if(vis[S.id][S.ld]) continue;
        vis[S.id][S.ld] = 1;
        for(int i = head[S.id][S.ld];i;i=edge[i].nxt)
        {
            int idv = edge[i].idv,ldv = edge[i].ldv,w = edge[i].w;
            if(vis[idv][ldv]) continue;
            if(dis[idv][ldv]>dis[S.id][S.ld]+w);
            {
                dis[idv][ldv]=dis[S.id][S.ld]+w;
                pq.push({idv,ldv,dis[idv][ldv]});
            }
        }
    }
}
void solve()
{
    for(int i = 1;i<=q;i++)
    {
        int x=read(),y=read();
        dij(x);
        printf("%lld\n",dis[y][0]+a[x]+a[y]);
    }
}
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    c = read();n = read();m = read();d = read();q = read();
    for(int i = 1;i<=m;i++) a[i] = read();
    for(int i = 1;i<=n;i++)
    {
        int k = read();int pre = -1;
        for(int j = 1;j<=k;j++)
        {
            int X = read(), V = read();
            if(j>1)
            {
                add(pre,i,X,i,0);
                add(X,i,pre,i,0);
            }
            pre = X;
            add(X,0,X,i,V);
            add(X,i,X,0,V);
        }
    }
    if(c>11)
    {
        solve();
        return 0;
    }
    for(int i = 1;i<=m;i++)
    {
        dij(i);
        for(int j = i+1;j<=m;j++)
        {
            ans[i][j] = dis[j][0];
        }
    }
    for(int i = 1;i<=q;i++)
    {
        int x=read(),y=read();
        if(x>y) swap(x,y);
        printf("%lld\n",ans[x][y]+a[x]+a[y]);
    }
    return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2


0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
Oct31==Dec25?
*/