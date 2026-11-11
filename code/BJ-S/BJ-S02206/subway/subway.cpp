#include <bits/stdc++.h>
using namespace std;
int c, n, m, d, q, x, y, cmp, ans = INT_MAX, T;
int check[500100], w[500100];
struct node
{
    int to, cost1, cost2, flag;
};
vector <node> edge[500100];
void dfs(int step, int past)
{
    if (step == y)
    {
        ans = min(ans, cmp);
        return;
    }
    check[step] = 1;
    for (int i = 0; i < edge[step].size(); i++)
    {
        if (check[edge[step][i].to] == 0)
        {
            if (edge[step][i].flag != past)
            {
                cmp += 2;
                dfs(edge[step][i].to, edge[step][i].flag);
                cmp -= 2;
            }
            else dfs(edge[step][i].to, edge[step][i].flag);
            check[edge[step][i].to] = 0;
        }
    }
}
int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++) cin >> w[i];
    for (int i = 1; i <= n; i++)
    {
        int k, a1, t1, a2, t2;
        cin >> k >> a1 >> t1;
        T = t1;
        for (int j = 1; j < k; j++)
        {
            cin >> a2 >> t2;
            edge[a1].push_back({a2, t1, t2, i});
            edge[a2].push_back({a1, t2, t1, i});
            a1 = a2, t1 = t2;
        }
    }
    while (q--)
    {
        for (int i = 1; i <= n; i++) check[i] = 0;
        cmp = 0, ans = INT_MAX;
        cin >> x >> y;
        dfs(x, 0);
        cout << ans * T + w[x] + w[y] << endl;
    }
    return 0;
}
