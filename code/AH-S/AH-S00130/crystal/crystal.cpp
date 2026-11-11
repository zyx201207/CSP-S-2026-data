#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    int n;
    long long m;
    cin >> n >> m;
    if (n == 1)
    {
        cout << 1;
        return 0;
    }
    long long a[n + 1];
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    int z[2 * a[n] + 2], ans = 0, sum;
    for (long long i = -a[n]; i <= a[n]; i++)
    {
        z[i] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        z[a[i]]++;
        if (z[a[i]] > ans)
        {
            ans = z[a[i]];
            sum = i;
        }
    }
    sort(z + 1, z + a[n] + 1);
    if ((m == 0) || (z[a[n]] == n))
    {
        cout << z[a[n]];
        return 0;
    }
    if (z[a[n]] >= 2)
    {
        long long h = 0;
        int d = ans;
        for (int i = sum - 1; i >= 1; i--)
        {
            h += (a[sum] - a[i]);
            if (h > m)
            {
                break;
            }
            else if (h != 0)
            {
                d++;
            }
        }
        cout << d;
        return 0;
    }
    int maxn = 1;
    for (int i = 2; i <= n; i++)
    {
        for (int k = 1; k < i; k++)
        {
            long long s = 0;
            for (int j = k; j <= i; j++)
            {
                s += (a[i] - a[j]);
            }
            if ((s <= m) && ((i - k + 1) > maxn))
            {
                maxn = i - k + 1;
            }
        }
    }
    cout << maxn;
    return 0;
}
