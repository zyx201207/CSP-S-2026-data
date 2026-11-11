#include <bits/stdc++.h>
using namespace std;
long long a[200005], n, m, ans;
bool A = 1, C = 0, D = 0;
int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    if (m == 1)
    {
        C = 1;
    }
    if (m == 2) D = 1;
    for (int i=1;i<=n;i++)
    {
        cin >> a[i];
        long long d1 = log2(a[i] + 1);
        double d2 = log2(a[i] + 1);
        if (d1 != d2) A = 0;
    }
    if (A)
    {
        sort(a+1, a+n+1);
        cout << a[n - m + 1];
        return 0;
    }
    if (C)
    {
        sort(a+1, a+n+1);
        cout << a[n];
        return 0;
    }
    if (D)
    {
        for (int i=1;i<=n;i++)
        {
            for (int j=i+1;j<=n;j++)
            {
                ans = max(ans, a[i] & a[j]);
            }
        }
        cout << ans;
        return 0;
    }
    sort(a+1, a+n+1);
    ans = a[n];
    for (int i=2;i<=m;i++)
    {
        ans &= a[n - i + 1];
    }
    cout << ans;
    return 0;
}

