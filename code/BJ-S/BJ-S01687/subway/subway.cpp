#include<bits/stdc++.h>
using namespace std;
#define int long long
#define F(i,x,y) for(i=x;i<=y;i++)
#define rF(i,x,y) for(i=x;i>=y;i--)
const int N=50000+5;
int n,m,d,q,w[N],a[N],t[N],dis[1005][2005],idx,T,C,ds[N],qq[2*N],hd,tl;
bool vis[N];
struct node
{
    int u,dis;
    bool operator <(const node b) const {return dis>b.dis;}
};
struct Node
{
    int v,w;
};
vector<Node> v[N];
void dij(int x)
{
    priority_queue<node> q;
    q.push({x,0});
    int i;
    F(i,1,idx) dis[x][i]=1e18,vis[i]=0;
    dis[x][x]=0;
    while(!q.empty())
    {
        int u=q.top().u;
        q.pop();
        if(vis[u]) continue;
        vis[u]=1;
        for(auto to:v[u]) 
        {
            if(dis[x][to.v]>dis[x][u]+to.w) 
            {
                dis[x][to.v]=dis[x][u]+to.w;
                q.push({to.v,dis[x][to.v]});
            }
        }
    }
    return;
}
void bfs(int x)
{
    hd=tl=N;
    qq[N]=x;
    memset(ds,-1,sizeof ds);
    ds[x]=0;
    while(hd<=tl)
    {
        int u=qq[hd];
        hd++;
        for(auto nw:v[u])
        {
            int to=nw.v;
            if(ds[to]==-1) 
            {
                if(!nw.w) 
                {
                    qq[--hd]=to;
                    ds[to]=ds[u];
                }
                else
                {
                    qq[++tl]=to;
                    ds[to]=ds[u]+1;
                }
            }
        }
    }
    return;
}
void solve()
{
    cin>>n>>m>>d>>q;
    int i,j,ttt;
    idx=m;
    F(i,1,m) cin>>w[i];
    F(i,1,n)
    {
        int k;
        cin>>k;
        F(j,1,k) 
        {
            idx++;
            cin>>a[i]>>t[i];
            ttt=t[i];
            v[a[i]].push_back({idx,t[i]});
            v[idx].push_back({a[i],t[i]});
            if(j!=1) v[idx-1].push_back({idx,0}),v[idx].push_back({idx-1,0});
        }
    }
    if(C<=11)
    {
        F(i,1,m) dij(i);
        F(i,1,q)
        {
            int x,y;
            cin>>x>>y;
            cout<<w[x]+w[y]+dis[x][y]<<'\n';
        }
    }
    else if(C<=15)
    {
        F(i,1,q)
        {
            int x,y;
            cin>>x>>y;
            bfs(x);
            cout<<w[x]+w[y]+ds[y]*ttt<<'\n';
        }
    }
    else
    {
        F(i,1,q)
        {
            int x,y;
            cin>>x>>y;
            cout<<w[x]+w[y]<<'\n';
        }
    }
    return;
}
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cout.tie(0),cin.tie(0);
    T=1;
    cin>>C;
    while(T--) {solve();}
}