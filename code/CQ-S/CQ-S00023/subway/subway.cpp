#include <bits/stdc++.h>
using namespace std;
const long long MA = LLONG_MAX / 2;
struct node
{
    int to;
    long long w;
};
int c, n, m, d, q;
long long w[500005];
vector<node> bian[550005];
long long xian[505][505];
unordered_map<int, long long> ma[505];
long long  vis[505], ans;
int x, y;
void dfs(int u)
{
    if (ma[u].find(y) != ma[u].end())
    {
        ans = min(ans, vis[u] + ma[u][y]);
    }
    for (int v = 1; v <= n; v++)
    {
        if (vis[v] > vis[u] + xian[u][v])
        {
            vis[v] = vis[u] + xian[u][v];
            dfs(v);
        }
    }
}
int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++)
    {
        cin >> w[i];
    }

    for (int i = 1; i <= n; i++)
    {
        int k;
        cin >> k;
        for (int j = 1; j <= k; j++)
        {
            int aaa, ttt;
            cin >> aaa >> ttt;
            bian[aaa].push_back({m + i, ttt});
            bian[m + i].push_back({aaa, ttt});
            ma[i][aaa] = ttt;
        }
    }
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            xian[i][j] = MA;
        }
    }

    for (int i = 1; i <= m; i++)
    {
        for (node u : bian[i])
        {
            int uu = u.to - m;
            for (node v : bian[i])
            {
                int vv = v.to - m;
                if (uu == vv)
                {
                    continue;
                }
                long long ss = u.w + v.w;
                xian[uu][vv] = min(xian[uu][vv], ss);
                xian[vv][uu] = min(xian[vv][uu], ss);
            }
        }
    }
    while (q--)
    {
        ans = MA;
        memset(vis, 0x3f3f, sizeof vis);
        cin >> x >> y;
        for (node s : bian[x])
        {
            if (vis[s.to - m] > s.w)
            {
                vis[s.to - m] = s.w;
                dfs(s.to - m);
            }
        }
        cout << ans + w[x] + w[y] << "\n";
    }
    return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

16:50
*/