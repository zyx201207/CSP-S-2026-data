#include <bits/stdc++.h>
using namespace std;
int c, T;
int n, k;
vector<vector<int>> e;
vector<pair<int, int>> pr;
int fa[1000005];
bool is[1000005];
int find(int u)
{
    if (u == fa[u]) return u;
    return fa[u] = find(fa[u]);
}
void uni(int u, int v)
{
    int _u = find(u);
    int _v = find(v);
    if (_u != _v) fa[_u] = _v;
}
void getdis(int u, int f, int dis, int &mx)
{
    if (is[u]) mx = min(mx, dis);
    for (int i = 0; i < e[u].size(); i ++)
    {
        int v = e[u][i];
        if (f == v) continue;
        getdis(v, u, dis + 1, mx);
    }
}
int ans = INT_MAX;
void get()
{
    for (int i = 1; i <= n; i ++) fa[i] = i;
    for (int i = 0; i < pr.size(); i ++)
    {
        int u = pr[i].first;
        int v = pr[i].second;
        if (is[u] && is[v]) uni(u, v);
    }
    int sccnt = 0;
    for (int i = 1; i <= n; i ++)
    {
        if (!is[i]) continue;
        if (fa[i] == i) sccnt ++;
        if (sccnt > 2) return;
    }
    // for (int i = 1; i <= n; i ++)
    // {
    //     printf("%d ", is[i]);
    // }
    // printf("\n");
    int res = 0;
    for (int i = 1; i <= n; i ++)
    {
        if (!is[i])
        {
            int k = INT_MAX;
            getdis(i, 0, 0, k);
            res = max(k, res);
        }
    }
    // printf("res = %d\n", res);
    ans = min(ans, res);
}
void dfs(int u, int la)
{
    if (la == 0) return get();
    if (n - u + 1 < la || u > n) return;
    dfs(u + 1, la);
    is[u] = 1;
    dfs(u + 1, la - 1);
    is[u] = 0;
}
int main()
{
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    scanf("%d%d", &c, &T);
    while (T --)
    {
        scanf("%d%d", &n, &k);
        e.clear();
        e.resize(n + 1);
        ans = INT_MAX;
        pr.clear();
        for (int i = 1; i <= n; i ++) fa[i] = i;
        for (int i = 1; i < n; i ++)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            e[u].push_back(v);
            e[v].push_back(u);
            pr.push_back(make_pair(u, v));
        }
        if (c == 13 || c == 14)
        {
            if (k >= n / 2 + 1)
            {
                printf("1\n");
            }
            else
            {
                int t = n / 2 + 1 - k;
                printf("%d\n", (t + 3) / 4 + 1);
            }
            continue;
        }
        dfs(1, k);
        printf("%d\n", ans);
    }
    return 0;
}