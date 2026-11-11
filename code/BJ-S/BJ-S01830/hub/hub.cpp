#include <bits/stdc++.h>
#define ll long long

using namespace std;

int c,T;
int n,k;
int dis[1010][1010];
vector <int> G[1010];
bool vis[1010];
bool vis_c[1010];
bool chose[1010];

void dfs(int u, int t)
{
    vis[u] = 1;

    for(int v : G[u])
    {
        if(vis[v])
            continue;

        dis[t][v] = dis[t][u] + 1;
        dfs(v, t);
    }
}

void dfs_check(int u)
{
    vis_c[u] = 1;

    for(int v : G[u])
    {
        if(vis_c[v] || !chose[v])
            continue;

        dfs_check(v);
    }
}

void solve()
{
    cin >> n >> k;

    for(int i = 1; i <= n; i++)
        G[i].clear();

    for(int i = 1; i <= n - 1; i++)
    {
        int u,v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
            vis[j] = 0;

        dis[i][i] = 0;
        dfs(i, i);
    }
    
    int ans = 1010;
    for(int mask = 1; mask < (1 << n); mask++)
    {
        int cnt = 0;
        for(int i = 1; i <= n; i++)
        {
            chose[i] = 0;
            if(mask & (1 << (i - 1)))
                chose[i] = 1, cnt += 1;
        }

        if(cnt != k)
            continue;

        for(int i = 1; i <= n; i++)
            vis_c[i] = 0;

        int num = 0;
        for(int i = 1; i <= n; i++)
        {
            if(!chose[i])
                continue;

            if(!vis_c[i])
            {
                dfs_check(i);
                num += 1;
            }
        }

        if(num > 2)
            continue;

        int maxn = 0;
        for(int i = 1; i <= n; i++)
        {
            if(chose[i])
                continue;
            
            int minn = 1010;
            for(int j = 1; j <= n; j++)
            {
                if(!chose[j])
                    continue;

                minn = min(minn, dis[i][j]);
            }

            maxn = max(maxn, minn);
        }

        ans = min(ans, maxn);
    }

    cout << ans << "\n";
}

int main()
{
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);

    cin >> c >> T;

    while(T--)
        solve();

    return 0;
}