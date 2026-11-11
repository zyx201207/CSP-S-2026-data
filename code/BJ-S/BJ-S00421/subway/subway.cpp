#include <bits/stdc++.h>
using namespace std;
const int N=5e5+600;
struct edge
{
    int v,w;
};
vector <edge> a[N];
int w[600],cntnode;
bool vis[N];
long long dis[N];
priority_queue <pair<long long,int> > pq;
void dijkstra(int s)
{
    //memset(dis,2e18,sizeof(dis));
    while(!pq.empty())
    {
        pq.pop();
    }
    memset(vis,false,sizeof(vis));
    dis[s]=0;
    vis[s]=true;
    pq.push({0,s});
    while(!pq.empty())
    {
        auto x=pq.top();
        pq.pop();
        for(edge e:a[x.second])
        {
            int y=e.v,w=e.w;
            if(!vis[y])
            {
                vis[y]=true;
                dis[y]=dis[x.second]+w;
                pq.push({-dis[x.second]-w,y});
            }
        }
    }
    return ;
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
    {
        cin>>w[i];
    }
    cntnode=m;
    for(int i=1;i<=n;i++)
    {
        int k;
        cin>>k;
        cntnode++;
        for(int j=1;j<=k;j++)
        {
            int node,t;
            cin>>node>>t;
            a[cntnode].push_back({node,t});
            a[node].push_back({cntnode,t});
        }
    }
    /*for(int i=1;i<=m;i++)
    {
        for(auto j:a[i])
        {
            cout<<i<<' '<<j.v<<' '<<j.w<<'\n';
        }
    }*/
    while(q--)
    {
        int s,t;
        cin>>s>>t;
        for(int i=1;i<=cntnode;i++)
        {
            dis[i]=2e18;
        }
        dijkstra(s);
        cout<<dis[t]+w[s]+w[t]<<'\n';
    }
    return 0;
}

