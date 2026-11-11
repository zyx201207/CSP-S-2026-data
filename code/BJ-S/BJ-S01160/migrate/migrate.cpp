#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e6 + 5;
int c, t, n, d, x[N], minn, cnt;
void dfs(int st, int en, int step)
{
    if (st == en)
    {
        if (step < minn) minn = step, cnt = 1;
        else if (step == minn) cnt++;
        return;
    }
    for (int i = st + 1; i <= en; i++)
    {
        if (x[i] - x[st] > d) break;
        dfs(i, en, step + 1);
    }
}
signed main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin >> c >> t;
    while (t--)
    {
        int ans = 0;
        cin >> n >> d;
        for (int i = 1; i <= n; i++) cin >> x[i];
        for (int u = 1; u <= n; u++)
        {
            for (int v = u + 1; v <= n; v++)
            {
                cnt = 0, minn = 1e9;
                dfs(u, v, 0);
                ans += (cnt == 2);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
