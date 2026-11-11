#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[200005];
int ans = -1e9;
int n;
int m;
bool vis[200005];
void dfs(int step, int x, int sum, int m, int n)
{
    vis[x] = 1;
    if (step >= m)
    {
        ans = max(ans, sum);
        return ;
    }
    int num = 0, maxn = -1e9;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            if ((a[i] & sum) > maxn)
            {
                maxn = (a[i] & sum);
                num = i;
            }
        }
    }
    dfs(step + 1, num, maxn, m, n);
}
signed main()
{
    freopen("and.in", "r", stdin);
    freopen("ans.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        memset(vis, 0, sizeof vis);
        dfs(1, i, a[i], m, n);
    }
    cout << ans << '\n';
    return 0;
}
