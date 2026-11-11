#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<int> adj[1010];
int vis[1010], vist[1010], dep[1010], ans = 1e18;
int n, k;
bool check()
{
    int c = 0;
    for(int i = 1; i <= n; i++)
        vist[i] = 0;
    for(int i = 1; i <= n; i++)
    {
        if(vis[i] && !vist[i])
        {
            c++;
            if(c > 2)
                return false;
            queue<int> q;
            q.push(i);
            vist[i] = 1;
            while(q.size())
            {
                int u = q.front();
                q.pop();
                for(int j = 0; j < adj[u].size(); j++)
                {
                    int v = adj[u][j];
                    if(vist[v] || !vis[v])
                        continue;
                    vist[v] = 1;
                    q.push(v);
                }
            }
        }
    }
    return true;
}
void dfs(int u, int f)
{
    dep[u] = dep[f] + 1;
    for(int i = 0; i < adj[u].size(); i++)
    {
        int v = adj[u][i];
        if(v == f)
            continue;
        dfs(v, u);
    }
}
int getval()
{
    int maxn = 0, minn = 1e18;
    for(int i = 1; i <= n; i++)
    {
        dep[i] = 0;
        dfs(i, 0);
        minn = 1e18;
        for(int j = 1; j <= n; j++)
        {
            if(vis[j])
                minn = min(minn, dep[j] - 1);
        }
        maxn = max(maxn, minn);
    }
    return maxn;
}
void dfst(int step, int cnt)
{
    if(cnt > k || cnt + n - step + 1 < k)
        return;
    if(step > n)
    {
        if(cnt == k && check())
        {
            ans = min(ans, getval());
        }
        return;
    }
    vis[step] = 0;
    dfst(step + 1, cnt);
    vis[step] = 1;
    dfst(step + 1, cnt + 1);
}
signed main()
{
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int c, t;
    cin >> c >> t;
    while(t--)
    {
        cin >> n >> k;
        for(int i = 1; i <= n; i++)
        {
            adj[i].clear();
            vis[i] = 0;
        }
        for(int i = 1; i < n; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        ans = 1e18;
        dfst(1, 0);
        cout << ans << "\n";
    }
    return 0;
}
//T4 15pts
