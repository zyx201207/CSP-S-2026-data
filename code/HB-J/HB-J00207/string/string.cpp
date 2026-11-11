#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[200005];
char c[200005];
signed main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i] >> c[i];
        if (c[i] == c[i - 1])
        {
            a[i - 1] += a[i];
            i--;
            n--;
        }
    }
    int l = 1, r = n;
    int ans = 0;
    while (l < r)
    {
        if (a[l] < a[r])
        {
            if (c[l] != c[r])
            {
                ans += a[l];
                a[r] -= a[l];
                l++;
            }
            else
            {
                a[r] -= a[l];
                l++;
            }
        }
        else if (a[l] > a[r])
        {
            if (c[l] != c[r])
            {
                ans += a[r];
                a[l] -= a[r];
                r--;
            }
            else
            {
                a[l] -= a[r];
                r--;
            }
        }
        else
        {
            if (c[l] != c[r])
            {
                ans += a[l];
                l++;
                r--;
            }
            else
            {
                l++;
                r--;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
