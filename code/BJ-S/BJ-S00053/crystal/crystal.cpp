#include <bits/stdc++.h>
#define int long long
using namespace std;

int a[500010];

signed main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    int l = 1, r = n;
    int ans = 0;
    while (l <= r)
    {
        int i = (l + r) >> 1;
        int sum1 = 0, sum2 = 0;
        for (int j = l; j <= i; j++)
        {
            sum1 += (a[i] - a[j]);
        }
        for (int j = i + 1; j <= r; j++)
        {
            sum2 += (a[j] - a[i]);
        }
        if (abs(sum1 - m) > abs(sum2 - m))
        {
            //cout << 0 << endl;
            if (i + 1 > r) break;
            ans = max(ans, r - i + 1);
            l = i + 1;
        }
        else
        {
            //cout << 1 << endl;
            if (i - 1 < l) break;
            ans = max(ans, i - l + 1);
            r = i - 1;
        }
    }
    for (int i = ans + 1; a[i] == a[ans]; i++)
    {
        ans++;
    }
    cout << ans;
    return 0;
}
