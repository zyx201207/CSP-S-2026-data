#include <bits/stdc++.h>
using namespace std;

struct node
{
    int num, dis;
} a[5010][5010];

int c, t, n;
long long d, X[2000010];

node dfs(int x, int y)
{
    if(a[x][y].num != 0) return a[x][y];
    if(X[y] - X[x] <= d) return {a[x][y].num = 1, a[x][y].dis = 1};
    int ret1 = 0, ret2 = 1e9;
    for(int i = x + 1;i <= y - 1; i++)
        ret2 = min(ret2, dfs(x, i).dis + dfs(i, y).dis);
    for(int i = x + 1;i <= y - 1; i++)
        ret1 += (ret2 == dfs(x, i).dis + dfs(i, y).dis) * dfs(x, i).num * dfs(i, y).num;
    return a[x][y] = {ret1, ret2};
}

int main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin >> c >> t;
    while(t--)
    {
        cin >> n >> d;
        for(int i = 1;i <= n; i++)
        {
            cin >> X[i];
            for(int j = i;j <= n; j++)
                a[i][j].num = a[i][j].dis = 0;
        }
        int ans = 0;
        for(int i = 1;i <= n; i++)
            for(int j = i;j <= n; j++)
            {
                if(dfs(i, j).num == 2) ans++;
            }
        cout << ans << endl;
    }
    return 0;
}
