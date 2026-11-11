#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q;
int a[505005];
bool vis[505005];
int dis[505005];
int to[505][505];
vector<pair<int,int>> e[505005];
vector<pair<int,int>> g[505005];
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> p;
void shortcut(int S)
{
    for(int i = 1; i <= n; i++) dis[i] = 1e18,vis[i] = 0;
    dis[S] = 0; 
    p.push({0,S});
    while(p.size())
    {
        int u = p.top().second;
        p.pop();
        if(vis[u]) continue;
        vis[u] = 1;
        for(pair<int,int> x : e[u])
        {
            int v = x.first,w = x.second;
            if(dis[v] > dis[u] + w)
            {
                dis[v] = dis[u] + w;
                p.push({dis[v],v});
            }
        }
    }
    for(int i = 1; i <= n; i++)
        to[S][i] = dis[i];
}
main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> c >> n >> m >> d >> q;
    for(int i = 1; i <= m; i++)
        cin >> a[i];
    for(int u = 1; u <= n; u++)
    {
        int k;
        cin >> k;
        while(k--)
        {
            int v,w;
            cin >> v >> w;
            v += n;
            g[v].emplace_back(u,w);
        }
    }
    for(int i = 1; i <= m; i++)
    {
        for(pair<int,int> x : g[i + n])
        {
            for(pair<int,int> y : g[i + n])
            {
                int u = x.first,uu = x.second;
                int v = y.first,vv = y.second;
                if(u == v) continue;
                e[u].emplace_back(v,uu + vv);
            }
        }
    }
    for(int i = 1; i <= n; i++)
        shortcut(i);
    while(q--)
    {
        int aa,bb;
        cin >> aa >> bb;
        int ans = 1e18;
        for(pair<int,int> x : g[aa + n])
        {
            for(pair<int,int> y : g[bb + n])
            {
                int u = x.first,uu = x.second;
                int v = y.first,vv = y.second;
                ans = min(ans,to[u][v] + a[aa] + a[bb] + uu + vv);
            }
        }
        cout << ans << '\n';
    }
}
