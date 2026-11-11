#include <bits/stdc++.h>
using namespace std;
#define int long long

int a[500050];

signed main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1, greater<int>());
    int r = 1, ans = 0;
    for (int l = 1; l <= n; l++)
    {
        while (r < n && a[r + 1] + m >= a[l])
        {
            r++;
            m += a[r] - a[l];
        }
        ans = max(ans, r - l + 1);
        m += (r - l) * (a[l] - a[l + 1]);
    }
    cout << ans << '\n';
    return 0;
}
