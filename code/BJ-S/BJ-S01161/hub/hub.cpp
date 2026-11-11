#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1000 + 5;
const int inf = 3e18 + 7;
int n, k, ans, dis[N];
bool box[N], vis[N];
vector<int> e[N];
void dfs(int u)
{
    vis[u] = 1;
    for(auto v : e[u])
    {
        if(box[v] && !vis[v])
            dfs(v);
    }
}
void dfs(int d, int num)
{
    if(d > n || num == k)
    {
        if(num != k)    return ;
        for(int i = 1; i <= n; i++) vis[i] = 0;
        int cnt = 0, tot = 0;
        for(int i = 1; i <= n; i++)
        {
            if(box[i])
            {
                tot++;
                if(vis[i])  continue;
                cnt++;
                dfs(i);
            }
        }
        if(cnt > 2 || tot != k) return ;
        queue<int> q;
        for(int i = 1; i <= n; i++)
        {
            dis[i] = -1;
            if(box[i])  q.push(i), dis[i] = 0;
        }
        while(!q.empty())
        {
            int u = q.front();
            q.pop();
            for(auto v : e[u])
            {
                if(dis[v] != -1)    continue;
                dis[v] = dis[u] + 1;
                q.push(v);
            }
        }
        int res = 0;
        for(int i = 1; i <= n; i++) res = max(res, dis[i]);
        ans = min(ans, res);
        return ;
    }
    box[d] = 1;
    dfs(d + 1, num + 1);
    box[d] = 0;
    dfs(d + 1, num);
}
signed main()
{
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    int _, t;
    cin >> _ >> t;
    while(t--)
    {
        for(int i = 1; i <= n; i++) e[i].clear();
        cin >> n >> k;
        for(int i = 1; i < n; i++)
        {
            int u, v;
            cin >> u >> v;
            e[u].push_back(v);
            e[v].push_back(u);
        }
        ans = inf;
        dfs(1, 0);
        cout << ans <<endl;
    }
    return 0;
}
