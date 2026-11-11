#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int n, k, c, t, ans = 2e9, vis[10010], fa[10010], x[10010], viss[10010], dis[10010], visit[10010];
vector<int>e[10010];
void bfs(int x)
{
    queue<int>q;
    q.push(x);
    while(q.size())
    {
        int s = q.front();
        q.pop();
        for(auto i : e[s])
        {
            if(vis[i] && !viss[i])
            {
                viss[i] = 1;
                q.push(i);
            }
        }
    }
}
void bfss(int x)
{
    queue<int>q;
    q.push(x);
    while(q.size())
    {
        int s = q.front();
        q.pop();
        for(auto i : e[s])
        {
            if(dis[i] <= dis[s] + 1)
            {
                continue;
            }
            dis[i] = dis[s] + 1;
            q.push(i);
        }
    }
}
bool check()
{
    int cnt = 0;
    for(int i = 1; i <= n; ++i)
    {
        viss[i] = 0;
    }
    for(int i = 1; i <= n; ++i)
    {
        if(vis[i] && !viss[i])
        {
            ++cnt;
            bfs(i);
        }
    }
    return cnt <= 2;
}
int get()
{
    for(int i = 1; i <= n; ++i)
    {
        dis[i] = 0x3f3f3f3f;
    }
    for(int i = 1; i <= n; ++i)
    {
        if(vis[i])
        {
            dis[i] = 0;
            bfss(i);
        }
    }
    int maxn = 0;
    for(int i = 1; i <= n; ++i)
    {
        maxn = max(maxn, dis[i]);
    }
    return maxn;
}
void dfs(int x, int cnt)
{
    if(cnt > k)
    {
        return;
    }
    if(x == n)
    {
        if(cnt != k)
        {
            return;
        }
        if(check())
        {
            ans = min(ans, get());
        }
        return;
    }
    for(int i = x + 1; i <= n; ++i)
    {
        vis[i] = 1;
        dfs(i, cnt + 1);
        vis[i] = 0;
        dfs(i, cnt);
    }
}
void solve()
{
    cin >> n >> k;
    ans = 2e9;
    for(int i = 1; i <= n; ++i)
    {
        e[i].clear();
        fa[i] = 0;
        vis[i] = 0;
    }
    for(int i = 1; i < n; ++i)
    {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1, 0);
    cout << ans << endl;
}
int main()
{
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    cin >> c >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}
