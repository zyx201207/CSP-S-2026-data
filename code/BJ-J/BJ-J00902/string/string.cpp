#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, a[200005];
    long long lo = 0;
    char c[200005];
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i] >> c[i];
        lo += a[i];
    }
    long long cnt = 0, l1 = 0, r1 = lo - 1, l2 = 1, r2 = n;
    while (l1 < r1)
    {
        if (c[l2] != c[r2])
            cnt += min(a[l2], a[r2]);
        l1 += min(a[l2], a[r2]);
        r1 -= min(a[l2], a[r2]);
        if (a[l2] >= a[r2])
        {
            a[l2] -= a[r2];
            r2--;
        }
        else
        {
            a[r2] -= a[l2];
            l2++;
        }
    }
    cout << cnt;
    return 0;
}
