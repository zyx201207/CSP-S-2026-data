#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define dis(i, j) (a[j] - a[i])
using namespace std;
int C, T, n;
ll d, a[2000005], f[5005][5005], g[5005][5005], ans;
int main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> C >> T;
    while (T--)
    {
        cin >> n >> d;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        if (n > 300)
        {
            int t = n - 1;
            for (int i = 1; i <= n; i++) if (dis(1, i) > d) {t = i - 2; break;}
            if (t <= 1 || n - t * 2 + 2 <= 0) cout << 0 << endl;
            else cout << n - t * 2 + 1 << endl;
            continue;
        }
        _:;
        ans = 0;
        for (int i = 1; i <= n; i++)
        {
            f[i][i] = 0;
            for (int j = i + 1; j <= n; j++)
                f[i][j] = n + 1;
        }
        for (int i = 1; i <= n; i++)
        {
            int now = i, cnt = 0;
            for (int j = i + 1; j <= n; j++)
            {
                if (dis(now, j) > d) cnt++, now = j - 1;
                if (dis(now, j) > d) break;
                f[i][j] = cnt + 1;
            }
        }
        for (int l = 1; l <= n; l++)
        {
            for (int i = 1; i <= n - l + 1; i++)
            {
                int j = i + l - 1;
                if (f[i][j] == 1)
                {
                    g[i][j] = 1;
                    continue;
                }
                g[i][j] = 0;
                if (f[i][j] == n + 1) continue;
                for (int k = j - 1; k > i; k--)
                {
                    if (dis(k, j) > d) break;
                    if (f[i][k] + f[k][j] == f[i][j]) g[i][j] += g[i][k] * g[k][j];
                }
                if (g[i][j] == 2) ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
