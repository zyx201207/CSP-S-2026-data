#include <bits/stdc++.h>
using namespace std;
const int N=5e2+7;
const int M=2e4+7;
int c,n,m,d,qs;
int add[M];
int k[N];
long long dis[M+N];
vector<pair<int,long long> > g[M+N];
priority_queue<pair<long long,int> > q;
void dijkstra(int s)
{
    memset(dis,0x3f,sizeof dis);
    dis[s]=0;
    q.push({0,s});
    while(!q.empty())
    {
        int u=q.top().second;
        q.pop();
        for(pair<int,int> x : g[u])
        {
            int v=x.first,w=x.second;
            if(dis[u]+w<dis[v])
            {
                dis[v]=dis[u]+w;
                q.push({-dis[v],v});
            }
        }
    }
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>qs;
    for(int i=1;i<=m;i++)
    {
        cin>>add[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>k[i];
        for(int j=1;j<=k[i];j++)
        {
            int x,y;
            cin>>x>>y;
            g[x].push_back({m+i,y});
            g[m+i].push_back({x,y});
        }
    }
    while(qs--)
    {
        int x,y;
        cin>>x>>y;
        dijkstra(x);
        cout<<dis[y]+add[x]+add[y]<<'\n';
    }
    return 0;
}
