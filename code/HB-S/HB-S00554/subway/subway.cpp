#include<bits/stdc++.h>
using namespace std;
#define int long long
vector <pair<int,int>> g[500505];
int a[500005],dis1[505005],dis[505][505],k=0;
bool vis[505][500505];
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
void dij(int s,int jj)
{
    q.push({0,s});
    dis1[s]=0;
    while(!q.empty())
    {
        pair<int,int> p=q.top();
        q.pop();
        int u=p.second;
        if(vis[jj][u]==1) continue;
        vis[jj][u]=1;
        for(int i=0;i<g[u].size();i++)
        {
            if(g[u][i].second+dis1[u]<dis1[g[u][i].first])
            {
                dis1[g[u][i].first]=g[u][i].second+dis1[u];
                q.push({dis1[g[u][i].first],g[u][i].first});
            }
        }
    }
    return ;
}
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int c,m,n,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        int k;
        cin>>k;
        for(int j=1;j<=k;j++)
        {
            int u,w;
            cin>>u>>w;
            g[u].push_back({m+i,w});
            g[m+i].push_back({u,w});
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m+n;j++) dis1[j]=1000000000000000000ll;
        dij(i+m,i);
        for(int j=1;j<=n;j++) dis[i][j]=dis1[m+j];
    }
    for(int i=1;i<=q;i++)
    {
        int aa,b,ans=1000000000000000000ll;
        cin>>aa>>b;
        for(int v=0;v<g[aa].size();v++)
            for(int vv=0;vv<g[b].size();vv++)
                ans=min(ans,g[aa][v].second+g[b][vv].second+dis[g[aa][v].first-m][g[b][vv].first-m]);
        cout<<ans+a[aa]+a[b]<<'\n';
    }
    return 0;
}