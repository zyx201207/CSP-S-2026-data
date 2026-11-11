#include <bits/stdc++.h>
using namespace std;
int c, t, n, d, a[2000005], o[2000005], ans = 1e9, cnt = 0;
void dfs(int step, int e, int l, int last)
{
    if (step == e)
    {
        ans = min(ans, l);
        return ;
    }
    for (int i = last + 1; i <= e; i++)
    {
        if (a[i] - a[last] <= d)
        {
            dfs(i, e, l + 1, step);
        }
        else return ;
    }
}
void dfs1(int step, int e, int l, int last, int temp)
{
    if (step == e)
    {
        if (l == ans) cnt++;
        return ;
    }
    for (int i = last + 1; i <= e; i++)
    {
        if (a[i] - a[last] <= d)
        {
            dfs(i, e, l + 1, step);
        }
        else return ;
    }
}
int main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin >> c >> t;
    while (t--)
    {
        ans = 1e9;
        cin >> n >> d;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            if (i > 2) o[i] = o[i - 1] + a[i] - a[i - 1];
        }
        int ans1 = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                cnt = 0;
                dfs(i, j, 0, 0);
                dfs1(i, j, 0, 0, 0);
                if (cnt == 2) ans1++;
            }
        }
        cout << ans1 << endl;
    }
    return 0;
}