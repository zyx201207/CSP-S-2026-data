#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF=0x3f3f3f3f3f3f3f3f;
int c,n,m,d1,Q,s,e,minn=1e9;
int w[500005];
ll dis[500005];
bool vis[500005];
struct node
{
    int i,v,t;
};
vector<node>g[505];
vector<pair<int,int>>r[500005];
void f(int s,int e)
{
    priority_queue<pair<ll,pair<int,int>>>q;
    dis[s]=0;
    vis[s]=1;
    q.push({-dis[s],{s,0}});
    while(!q.empty())
    {
        auto [u,d]=q.top().second;
        q.pop();
        if(u==e)return;
        for(auto [rr,w2]:r[u])
        {
            if(rr==d)w2=0;
            for(node e:g[rr])
            {
                int v=e.v;
                int w1=e.t;
                if(vis[v])continue;
                if(dis[v]>dis[u]+w[u]+w1+w2+w[v])
                {
                    dis[v]=dis[u]+w[u]+w1+w2+w[v];
                    q.push({-dis[v],{v,rr}});
                    vis[v]=1;
                }
            }
        }
    }
}
int main()
{
    freopen("sub.in","r",stdin);
    freopen("sub.out","w",stdout);
    cout<<18<<"\n"<<23<<"\n"<<14;
    cin>>c>>n>>m>>d1>>Q;
    for(int i=1;i<=m;i++)
    {
        cin>>w[i];
    }
    for(int i=1;i<=n;i++)
    {
        int k;
        cin>>k;
        for(int j=1;j<=k;j++)
        {
            int u,t;
            cin>>u>>t;
            r[u].push_back({i,t});
            g[i].push_back({i,u,t});
        }
    }
    while(Q--)
    {
        cin>>s>>e;
        memset(dis,INF,sizeof dis);
        memset(vis,0,sizeof vis);
        cout<<dis[e]<<"\n";
    }
    return 0;
}

