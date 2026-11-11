#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int c, t, n, d, x[2000010], r[2000010], cc = 0, sum = 0, ans = 0;
bool flag = false;

void dfs(int step, int cntc, int rr, int maxn)
{
    if (sum > 2) return ;
    if (cntc > maxn) return ;
    if (step == rr)
    {
        sum++;
        return ;
    }
    for (int i = step + 1; i <= r[step]; i++)
        dfs(i, cntc + 1, rr, maxn);
}

int main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin >> c >> t;
    while (t--)
    {
        ans = 0;
        cin >> n >> d;
        for (int i = 1; i <= n; i++) scanf("%d", &x[i]);
        for (int i = 1; i <= n; i++)
            r[i] = upper_bound(x + 1, x + n + 1, x[i] + d) - x - 1;
        for (int i = 1; i <= n; i++)
            for (int j = i + 2; j <= n; j++)
            {
                int w = i, cnt = 0;
                cc = 0;
                while (w < j)
                {
                    if (r[w] == w)
                    {
                        cc = 1;
                        break;
                    }
                    w = r[w];
                    cnt++;
                }

                if (cc) continue;
                sum = 0;
                dfs(i, 0, j, cnt);
                if (sum == 2)
                    ans++;
            }
        cout << ans << endl;
    }
    return 0;
}
