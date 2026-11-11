#include<bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
using namespace std;
ll c,n,m,d,Q,w[1005],dis[1005][1005];
vector<pll> e[1005];
priority_queue<pll,vector<pll>,greater<pll> > q;
void dijkstra(int x)
{
    q.push(make_pair(0,x));
    dis[x][x]=0;
    while(!q.empty())
    {
        ll len=q.top().first,u=q.top().second;
        q.pop();
        if(dis[x][u]!=len) continue;
        for(auto t:e[u])
            if(len+t.second<dis[x][t.first])
            {
                dis[x][t.first]=len+t.second;
                q.push(make_pair(dis[x][t.first],t.first));
            }
    }
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>c>>n>>m>>d>>Q;
    memset(dis,0x3f,sizeof(dis));
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++)
    {
        int k;cin>>k;
        for(int j=1;j<=k;j++)
        {
            int a,t;cin>>a>>t;
            e[a].push_back(make_pair(m+i,t));
            e[m+i].push_back(make_pair(a,t));
        }
    }
    for(int i=1;i<=m;i++)
        dijkstra(i);
    while(Q--)
    {
        int x,y;cin>>x>>y;
        cout<<dis[x][y]+w[x]+w[y]<<endl;
    }
    return 0;
}
