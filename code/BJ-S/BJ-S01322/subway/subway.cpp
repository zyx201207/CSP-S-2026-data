#include <bits/stdc++.h>
using namespace std;
int c, n, m, d, q, w[5005], ans = 1e9, f[5005], t[505][5005];
int vis[5005];
struct node
{
    int y, l;
};
vector <node> v[5005];
void dfs(int step, int e, int sum, int ls, int lw)
{
    if (step == e)
    {
        ans = min(ans, sum) + lw;
        return ;
    }
    for (auto i : v[step])
    {
        if (vis[i.y]) continue;
        if (f[step] == -1 && ls != 0)
        {
            if (f[ls] == f[i.y])
            {
                vis[i.y] = 1;
                dfs(i.y, e, sum, step, i.l);
                vis[i.y] = 0;
            }
            else
            {
                vis[i.y] = 1;
                dfs(i.y, e, sum + t[f[i.y]][step] + lw, step, i.l);
                vis[i.y] = 0;
            }
        }
        else if (f[step] == f[i.y] || f[i.y] == -1)
        {
            vis[i.y] = 1;
            if (ls == 0 && f[step] != -1) dfs(i.y, e, sum + t[f[step]][step], step, i.l);
            else if (ls == 0 && f[i.y] != -1) dfs(i.y, e, sum + t[f[i.y]][step], step, i.l);
            else dfs(i.y, e, sum, step, i.l);
            vis[i.y] = 0;
        }
    }
}
int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++) cin >> w[i];
    for (int i = 0; i <= m; i++) f[i] = -2;
    for (int i = 1; i <= n; i++)
    {
        int k;
        cin >> k;
        int l1 = 0;
        for (int j = 1; j <= k; j++)
        {
            int x, b;
            cin >> x >> b;
            t[i][x] = b;
            if (j != 1)
            {
                v[l1].push_back({x, b});
                v[x].push_back({l1, b});
            }
            else
            {
                l1 = x;
                continue;
            }
            if (f[x] != -2 && f[x] != i) f[x] = -1;
            if (f[l1] != -2 && f[l1] != i) f[l1] = -1;
            if (f[x] == -2) f[x] = i;
            if (f[l1] == -2) f[l1] = i;
            l1 = x;
        }
    }
    while (q--)
    {
        int s, e;
        cin >> s >> e;
        memset(vis, 0, sizeof(vis));
        vis[s] = 1;
        ans = 1e9;
        dfs(s, e, w[s] + w[e], 0, 0);
        cout << ans << endl;
    }
    return 0;
}