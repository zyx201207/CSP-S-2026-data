#include <bits/stdc++.h>
using namespace std;
int n, m;
long long a[200005];
bool vis[200005];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    long long ans = 0;
    for (int k = 30; k >= 0; k--)
    {
        int cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            if (vis[i]) continue;
            if ((a[i] & (1 << k)) > 0)
            {
                cnt++;
            }
        }
        if (cnt >= m)
        {
            for (int i = 1; i <= n; i++)
            {
                if ((a[i] & (1 << k)) == 0)
                {
                    vis[i] = 1;
                }
            }
            ans += (1 << k);
        }
        for (int i = 1; i <= n; i++)
        {
            if (vis[i]) continue;
            if ((a[i] & (1 << k)) > 0)
            {
                a[i] -= (1 << k);
            }
        }
    }
    cout << ans << endl;
    return 0;
}