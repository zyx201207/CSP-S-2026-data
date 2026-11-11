#include <bits/stdc++.h>
using namespace std;
#define int long long

int c;
int a[2000020], mx[2000020];

void solve()
{
    int n, d;
    cin >> n >> d;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    int r = 1;
    for (int l = 1; l <= n; l++)
    {
        while (r < n && a[r + 1] - a[l] <= d)
        {
            r++;
        }
        mx[l] = r;
    }
    int ans = 0;
    for (int l = 1; l <= n; l++)
    {
        for (int r = l + 3; r <= n; r++)
        {
            int now = l, dis = 0;
            while (now < r)
            {
                if (now == mx[now])
                {
                    dis = 0;
                    break;
                }
                now = mx[now];
                dis++;
            }
            if (!dis)
            {
                break;
            }
            int sum = 0;
            for (int k = l + 1; k < r; k++)
            {
                int cnt = 0;
                now = l;
                while (now < k)
                {
                    now = mx[now];
                    cnt++;
                }
                now = k;
                while (now < r)
                {
                    now = mx[now];
                    cnt++;
                }
                sum += (dis == cnt);
                if (sum >= 3)
                {
                    break;
                }
            }
            ans += (sum == 2);
        }
    }
    cout << ans << '\n';
}

signed main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> c >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
