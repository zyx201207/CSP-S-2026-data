#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q;
int w[1005],k[1005],a[1005][1005],t[1005][1005],l[1005],r[1005],idx[1005][1005];
struct edge
{
    int v,w;
};
vector<pair<int,int>> v[500005];
vector<edge> g[500005];
priority_queue<pair<int,int>> qq;
bool vis[500005];
int dis[500005];
void dijkstra(int s)
{
    qq.push({0,s});
    vis[s]=1;
    dis[s]=0;
    while(!qq.empty())
    {
        int uu=qq.top().second;
        qq.pop();
        for(edge e:g[uu])
        {
            int vv=e.v,ww=e.w;
            if(vis[vv]) continue;
            if(dis[vv]>dis[uu]+ww)
            {
                dis[vv]=dis[uu]+ww;
                vis[vv]=1;
                qq.push({dis[vv],vv});
            }
        }
    }
}
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++)
    {
        cin>>k[i];
        for(int j=1;j<=k[i];j++)
        {
            cin>>a[i][j]>>t[i][j];
            v[a[i][j]].push_back({i,t[i][j]});
        }
    }
    int cnt=0;
    for(int i=1;i<=m;i++)
    {
        l[i]=r[i-1]+1;
        r[i]=l[i]+v[i].size();
        for(int j=0;j<v[i].size();j++)
        {
            idx[v[i][j].first][i]=l[i]+j+1;
            g[l[i]].push_back({l[i]+j+1,v[i][j].second});
            g[l[i]+j+1].push_back({l[i],v[i][j].second});
        }
    }

    for(int i=1;i<=n;i++)
    {

        for(int j=1;j<k[i];j++)
        {
            g[idx[i][a[i][j]]].push_back({idx[i][a[i][j+1]],0});
            g[idx[i][a[i][j+1]]].push_back({idx[i][a[i][j]],0});
        }
    }

    while(q--)
    {
        int s,t;
        cin>>s>>t;
        int ss=l[s];
        int tt=l[t];
        for(int i=1;i<=r[m];i++)
        {
            vis[i]=false;
            dis[i]=1e18;
        }
        dijkstra(ss);
        cout<<dis[tt]+w[s]+w[t]<<endl;
    }
    return 0;
}
