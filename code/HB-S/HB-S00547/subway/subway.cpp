#include<bits/stdc++.h>
using namespace std;
const int N=205,M=50005;
const long long INF=1e18;
int c,n,m,d,q1;
int w[M];
struct edge{
    int v,w;
};
vector<edge> g[M*N];
int vis[M*N];
int get(int i)
{
    return n*m+i;
}
int get1(int i)
{
    return n*m+m+i;
}
struct node{
    long long dis;
    int pos;
    bool operator<(const node &x)const{
        return dis>x.dis;
    }
};
long long dis[M*N];
void dij(int st,int now)
{
    for(int i=1;i<=m*n+m+m;i++)
        dis[i]=INF;
    priority_queue<node> q;
    dis[st]=0;
    q.push({dis[st],st});
    while(!q.empty())
    {
        node cur=q.top();
        q.pop();
        int u=cur.pos;
        if(vis[u]==now) continue;
        vis[u]=now;
        for(edge y:g[u])
        {
            int v=y.v,w=y.w;
            if(dis[v]>dis[u]+w)
            {
                dis[v]=dis[u]+w;
                if(vis[v]!=now) q.push({dis[v],v});
            }
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>q1;
    for(int i=1;i<=m;i++)
    cin>>w[i];
    for(int i=1;i<=m;i++)
        g[get1(i)].push_back({get(i),w[i]}),
        g[get(i)].push_back({get1(i),w[i]});
    for(int i=1;i<=n;i++)
    {
        int k,a,b=0,t;
        cin>>k;
        for(int j=1;j<=k;j++)
        {
            cin>>a;
            a+=(i-1)*m;
            if(b) 
                g[a].push_back({b,0}),
                g[b].push_back({a,0});
            b=a;
            cin>>t;
            g[b].push_back({get(b-(i-1)*m),t});
            g[get(b-(i-1)*m)].push_back({b,t});
        }
    }
    for(int i=1;i<=q1;i++)
    {
        int x,y;
        cin>>x>>y;
        dij(get1(x),i);
        cout<<dis[get1(y)]<<'\n';
    }
    return 0;
}