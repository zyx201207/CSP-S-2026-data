#include<bits/stdc++.h>
#define int ll
#define ll long long
#define ull unsigned long long
using namespace std;
const int maxq=1e5+5;
struct node
{
    ll x,w;
};
ll c,n,m,d,q,w[505],a[505][505],t[505][505],x[maxq],y[maxq];
vector<node> g[505];
int bfs(int u,int v)
{
    priority_queue<pair<int,int>> q;
    q.push({0,u});
    while(!q.empty())
    {
        auto now=q.top();
        if(now.second==v) return now.first;
        q.pop();
        for(auto son:g[now.second])
        {
            q.push({now.first+son.w,son.x});
        }
    }
    return -1;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=n;i++)cin>>w[i];
    for(int i=1;i<=n;i++)
    {
        int r;cin>>r;
        int u,v,wu,wv;
        cin>>u>>wu>>v>>wv;
        g[u].push_back({v,wu+wv});
        g[v].push_back({u,wu+wv});
        for(int j=1;j<=r;j++)
        {
            cin>>a[i][j];
            cin>>t[i][j];
        }
    }
    for(int i=1;i<=q;i++)
        cin>>x[i]>>y[i];
    for(int i=1;i<=q;i++)
    {
        cout<<bfs(x[i],y[i])<<'\n';
    }
    return 0;
}
