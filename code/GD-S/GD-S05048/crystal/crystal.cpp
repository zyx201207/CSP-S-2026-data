#include <iostream>
using namespace std;
long long n, m;
long long a[500005];
long long check(long long x)
{
    long long need = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] <= x)
        {
            need += x - a[i];
            if (need > m)
            {
                return 0;
            }
        }
    }
    return need;
}
int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    long long l = LLONG_MAX, r = LLONG_MIN;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        l = min(l, a[i]);
        r = max(r, a[i]);
    }
    while (l < r)
    {
        long long mid = (l + r + 1) / 2;
        if (check(mid))
        {
            l = mid;
        }
        else
        {
            r = mid - 1;
        }
        // cout << l << ' ' << r << ' ' << check(mid) << endl;
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] <= l)
            ans++;
    }
    cout << ans;
}
