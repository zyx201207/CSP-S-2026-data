#include <bits/stdc++.h>
using namespace std;

#define EOL '\n'
#define int long long
#define double long double
#define sqrt sqrtl

int n, m, a[500010], s[500010];

bool check(int x)
{
    for (int i = x; i <= n; ++i)
    {
        if (x * a[i] - (s[i] - s[i - x]) <= m)
        {
            return true;
        }
    }
    return false;
}

signed main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; ++i)
    {
        s[i] = s[i - 1] + a[i];
    }
    int l = 1, r = n, ans = 0;
    while (l <= r)
    {
        int mid = l + (r - l >> 1);
        if (check(mid))
        {
            ans = mid;
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    cout << ans << EOL;
    return 0;
}
