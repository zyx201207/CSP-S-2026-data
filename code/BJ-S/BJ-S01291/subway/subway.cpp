//zhantai 1~m  xianlu  m+1~n+m
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,x,y) for(int i=x;i<=y;i++)
#define per(i,x,y) for(int i=x;i>=y;i--)
const int N=505;
const int M=5e5+5;
int c,n,m,d,q;
int w[M];
struct edge
{
    int v,w;
};
vector<edge>e[N+M];
struct nod
{
    int to,val;
    bool operator<(const nod&o)const
    {
        return val>o.val;
    }
};
int dis[N+M],vis[N+M];
struct ask
{
    int x,y,idx;
    bool operator<(const ask&o) const
    {
        return x<o.x;
    }
};
vector<ask>v;
int ans[100005];
void dijkstra(int st)
{
    rep(i,1,n+m) dis[i]=1e18,vis[i]=0;
    priority_queue<nod>q;
    q.push({st,0});
    dis[st]=0;
    while(!q.empty())
    {
        auto [u,satori]=q.top();
        q.pop();
        if(vis[u]) continue;
        vis[u]=1;
        for(auto [v,w]:e[u])
        {
            if(dis[v]>dis[u]+w)
            {
                dis[v]=dis[u]+w;
                q.push({v,dis[v]});
            }
        }
    }
}
void solve2()
{
    rep(i,1,m) cin>>w[i];
    rep(i,1,n)
    {
        int x;
        cin>>x;
        rep(j,1,x)
        {
            int idx,val;
            cin>>idx>>val;
            e[m+i].push_back({idx,val});
            e[idx].push_back({m+i,val});
        }
    }
    rep(i,1,q)
    {
        int x,y;
        cin>>x>>y;
        v.push_back({x,y,i});
    }
    sort(v.begin(),v.end());
    rep(i,0,v.size()-1)
    {
        int j=i;
        dijkstra(v[i].x);
        while(j<v.size()&&v[j].x==v[i].x)
        {
            ans[v[j].idx]=dis[v[j].y]+w[v[j].x]+w[v[j].y];
            j++;
        }
        i=j-1;
    }
    rep(i,1,q) cout<<ans[i]<<"\n";
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    solve2();

    return 0;

}

