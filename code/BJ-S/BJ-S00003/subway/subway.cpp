#include <bits/stdc++.h>
using namespace std;
#define int long long

int w[500010];
struct stu
{
    int v, w;
};
vector<stu> adj[500010];
int dis[1010][2010], vis[2010], dist[202600], vist[202600];
map<int, int> mp1, mp2;
struct node
{
    int u, d;
    bool operator<(const node &a) const{
        return d > a.d;
    }
};
signed main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int c, n, m, d, q;
    cin >> c >> n >> m >> d >> q;
    for(int i = 1; i <= m; i++)
        cin >> w[i];
    if(c == 20 || c == 21)
    {
        int k;
        cin >> k;
        for(int i = 1; i <= k; i++)
        {
            int a, t;
            cin >> a >> t;
            mp1[a] = t;
        }
        cin >> k;
        for(int i = 1; i <= k; i++)
        {
            int a, t;
            cin >> a >> t;
            mp2[a] = t;
        }
        int minn = 1e18;
        for(int i = 1; i <= m; i++)
        {
            if(mp1.count(i) && mp2.count(i))
                minn = min(minn, mp1[i] + mp2[i]);
        }
        while(q--)
        {
            int x, y;
            cin >> x >> y;
            int ans = 1e18;
            if(mp1.count(x) && mp1.count(y))
                ans = min(ans, mp1[x] + mp1[y]);
            if(mp2.count(x) && mp2.count(y))
                ans = min(ans, mp2[x] + mp2[y]);
            if(mp1.count(x) && mp2.count(y))
                ans = min(ans, mp1[x] + mp2[y] + minn);
            if(mp2.count(x) && mp1.count(y))
                ans = min(ans, mp2[x] + mp1[y] + minn);
            cout << ans + w[x] + w[y] << "\n";
        }
        return 0;
    }
    int cur = m;
    for(int i = 1; i <= n; i++)
    {
        int k;
        cin >> k;
        int a, t;
        for(int j = 1; j <= k; j++)
        {
            cin >> a >> t;
            cur++;
            adj[a].push_back({cur, t});
            adj[cur].push_back({a, t});
            if(j > 1)
            {
                adj[cur - 1].push_back({cur, 0ll});
                adj[cur].push_back({cur - 1, 0ll});
            }
        }
    }
    if(c >= 12 && c <= 15)
    {
        while(q--)
        {
            int x, y;
            cin >> x >> y;
            priority_queue<node> q;
            for(int i = 1; i <= cur; i++)
                dist[i] = 1e18, vist[i] = 0;
            q.push({x, 0});
            dist[x] = 0;
            while(q.size())
            {
                int u = q.top().u;
                q.pop();
                if(vist[u])
                    continue;
                vist[u] = 1;
                for(int i = 0; i < adj[u].size(); i++)
                {
                    int v = adj[u][i].v, w = adj[u][i].w;
                    if(dist[v] > dist[u] + w)
                    {
                        dist[v] = dist[u] + w;
                        if(!vist[v])
                            q.push({v, dist[v]});
                    }
                }
            }
            cout << dist[y] + w[x] + w[y] << "\n";
        }
        return 0;
    }
    memset(dis, 0x3f, sizeof(dis));
    for(int i = 1; i <= m; i++)
    {
        priority_queue<node> q;
        for(int j = 1; j <= cur; j++)
            vis[j] = 0;
        q.push({i, 0});
        dis[i][i] = 0;
        while(q.size())
        {
            int u = q.top().u;
            q.pop();
            if(vis[u])
                continue;
            vis[u] = 1;
            for(int j = 0; j < adj[u].size(); j++)
            {
                int v = adj[u][j].v, w = adj[u][j].w;
                if(dis[i][v] > dis[i][u] + w)
                {
                    dis[i][v] = dis[i][u] + w;
                    if(!vis[v])
                        q.push({v, dis[i][v]});
                }
            }
        }
    }
    while(q--)
    {
        int x, y;
        cin >> x >> y;
        cout << dis[x][y] + w[x] + w[y] << "\n";
    }
    return 0;
}
//T2 52pts
