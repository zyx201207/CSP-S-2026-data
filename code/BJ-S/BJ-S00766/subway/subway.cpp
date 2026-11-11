#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=1e3+11;
const ll inf=1e18;
int c,n,m,d,q;
int a[maxn];
ll t[maxn];
ll ext[maxn];
ll id(int x,int y)
{
    return (ll)x*m+y;
}
struct edge
{
    int v;
    ll w;
    edge(int av=0,ll aw=0)
    {
        v=av,w=aw;
    }
};
vector<edge> to[maxn*maxn];
ll dis[maxn*maxn];
int vis[maxn*maxn];
struct stu
{
    int u;
    ll w;
    stu(int au=0,ll aw=0)
    {
        u=au,w=aw;
    }
    friend bool operator <(stu xx,stu yy)
    {
        return xx.w>yy.w;
    }
};
ll dij(int st,int ed)
{
    priority_queue<stu> q1;
    dis[st]=0;q1.push(stu(st,0));
    while(!q1.empty())
    {
        int u=q1.top().u;
        q1.pop();
        if(vis[u])
            continue;
        vis[u]=1;
        for(int i=0;i<to[u].size();++i)
        {
            int v=to[u][i].v;ll w=to[u][i].w;
            if(dis[v]>dis[u]+w)
            {
                dis[v]=dis[u]+w;
                q1.push(stu(v,dis[v]));
            }
        }
    }
    return dis[ed];
}
void init()
{
    for(int i=0;i<=n;++i)
        for(int j=1;j<=m;++j)
            dis[id(i,j)]=inf,vis[id(i,j)]=0;
}
void add(int u,int v,int w)
{
    to[u].push_back(edge(v,w));
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;++i)
        cin>>ext[i];
    for(int i=1;i<=n;++i)
    {
        int k;
        cin>>k;
        for(int j=1;j<=k;++j)
            cin>>a[j]>>t[j];
        for(int j=1;j<=k;++j)
        {
            if(j<k)
            {
                add(id(i,a[j]),id(i,a[j+1]),0);
                add(id(i,a[j+1]),id(i,a[j]),0);
            }
            add(a[j],id(i,a[j]),t[j]);
            add(id(i,a[j]),a[j],t[j]);
        }
    }
    while(q--)
    {
        int x,y;
        cin>>x>>y;
        init();
        cout<<ext[x]+ext[y]+dij(x,y)<<"\n";
    }
    return 0;
}