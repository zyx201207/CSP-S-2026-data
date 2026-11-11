#include <bits/stdc++.h>
using namespace std;
#define int long long
int w[500005];
struct node
{
    int v,w;
};
bool operator <(node x,node y)
{
    return x.w>y.w;
}
vector<node> g[505];
int dis[505][505];
vector<pair<int,int>> in[500005];
int k[505];
vector<int> a[505];
vector<int> t[505];
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
    {
        cin>>w[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>k[i];
        a[i].resize(k[i]+1);
        t[i].resize(k[i]+1);
        for(int j=1;j<=k[i];j++)
        {
            cin>>a[i][j]>>t[i][j];
            in[a[i][j]].push_back({i,t[i][j]});
        }
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=0;j<in[i].size();j++)
        {
            for(int k=j+1;k<in[i].size();k++)
            {
                g[in[i][j].first].push_back({in[i][k].first,in[i][j].second+in[i][k].second});
                g[in[i][k].first].push_back({in[i][j].first,in[i][j].second+in[i][k].second});
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        priority_queue<node> q;
        q.push({i,0});
        for(int j=1;j<=n;j++)
        {
            dis[i][j]=1e18;
        }
        dis[i][i]=0;
        while(!q.empty())
        {
            int u=q.top().v,d=q.top().w;
            q.pop();
            if(d>dis[i][u]) continue;
            for(auto v:g[u])
            {
                if(dis[i][u]+v.w<dis[i][v.v])
                {
                    dis[i][v.v]=dis[i][u]+v.w;
                    q.push({v.v,dis[i][v.v]});
                }
            }
        }
    }
    while(q--)
    {
        int x,y;
        cin>>x>>y;
        int ans=1e18;
        for(auto i:in[x])
        {
            for(auto j:in[y])
            {
                if(i.first==j.first)
                {
                    ans=min(ans,i.second+j.second);
                }
                else
                {
                    ans=min(ans,dis[i.first][j.first]+i.second+j.second);
                }
            }
        }
        cout<<ans+w[x]+w[y]<<'\n';
    }
}//15:14