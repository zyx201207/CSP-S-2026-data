#include <bits/stdc++.h>
using namespace std;
#define int long long

int a[200020];
char c[200020];

signed main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i] >> c[i];
    }
    int l = 1, r = n, ans = 0;
    while (l < r)
    {
        if (a[l] < a[r])
        {
            if (c[l] != c[r])
            {
                ans += a[l];
            }
            a[r] -= a[l];
            a[l] = 0;
            l++;
        }
        else if (a[l] == a[r])
        {
            if (c[l] != c[r])
            {
                ans += a[l];
            }
            a[l] = 0;
            a[r] = 0;
            l++;
            r--;
        }
        else
        {
            if (c[l] != c[r])
            {
                ans += a[r];
            }
            a[l] -= a[r];
            a[r] = 0;
            r--;
        }
    }
    cout << ans << '\n';
    return 0;
}
