#include <bits/stdc++.h>
using namespace std;

int n, m, a[200005], vis[200005], ans;

void dfs(int dep, int curans)
{
    if (dep > m)
    {
        ans = max(ans, curans);
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            vis[i] = 1;
            dfs(dep + 1, curans & a[i]);
            vis[i] = 0;
        }
    }
}

int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    dfs(1, 0b11111111111111111111111111111111);
    cout << ans << endl;
    return 0;
}