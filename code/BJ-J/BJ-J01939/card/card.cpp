#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<int> g[300030];
int a[500050], last[300030], ans[300030];

void dfs(int x, int fa)
{
    for (auto v : g[x])
    {
        if (v == fa)
        {
            continue;
        }
        dfs(v, x);
        ans[x] += ans[v];
    }
}

signed main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        last[a[i]] = i;
        ans[a[i]]++;
    }
    int rt;
    for (int i = 1; i <= m; i++)
    {
        if (last[i] != n)
        {
            g[i].push_back(a[last[i] + 1]);
            g[a[last[i] + 1]].push_back(i);
        }
        else
        {
            rt = i;
        }
    }
    dfs(rt, 0);
    for (int i = 1; i <= m; i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}
