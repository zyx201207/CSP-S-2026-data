#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef char ch;
typedef string str;
const ll maxn=5010,inf=1e18;
ll c,t,n,d,a[maxn],dis[maxn][maxn],cnt[maxn][maxn],ans;
struct edge
{
    ll to,nxt;
}e[maxn*maxn];
ll head[maxn],cnte;
void add(ll u,ll v)
{
    e[++cnte]={v,head[u]},head[u]=cnte;
}
struct node
{
    ll to,w;
    bool operator<(node nd) const
    {
        return w>nd.w;
    }
};
priority_queue<node> pq;
bitset<maxn> vis;
void dijkstra(ll u)
{
    dis[u][u]=0,cnt[u][u]=1,pq.push({u,0}),vis.reset();
    while(pq.size())
    {
        node tp=pq.top();
        pq.pop();
        if(vis[tp.to]) continue;
        vis[tp.to]=1;
        for(int i=head[tp.to];i;i=e[i].nxt)
        {
            ll v=e[i].to;
            if(dis[u][v]>dis[u][tp.to]+1) cnt[u][v]=cnt[u][tp.to],dis[u][v]=dis[u][tp.to]+1,pq.push({v,dis[u][v]});
            else if(dis[u][v]==dis[u][tp.to]+1) cnt[u][v]+=cnt[u][tp.to];
        }
    }
}
void solve()
{
    cin>>n>>d,ans=cnte=0;
    for(int i=1;i<=n;i++) cin>>a[i],head[i]=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i!=j&&abs(a[i]-a[j])<=d) add(i,j);
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++) dis[i][j]=inf,cnt[i][j]=0;
        dijkstra(i);
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++) ans+=(cnt[i][j]==2);
    }
    cout<<ans/2<<"\n";
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>t;
    while(t--) solve();
}
