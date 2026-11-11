#include <bits/stdc++.h>
using namespace std;

int n, m, a[200010], ans, res[200010];

void dfs(int x, int cur)
{
    if (x >= m)
    {
        int tmp = res[1];
        for (int i = 1; i <= m; i++)
        {
            tmp = tmp & res[i];
        }
        ans = max(ans, tmp);
        return;
    }
    for (int i = cur + 1; i <= n; i++)
    {
        res[x + 1] = a[i];
        dfs(x + 1, i);
    }
}

int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    dfs(0, 0);
    cout << ans;

    return 0;
}

