#include <bits/stdc++.h>
using namespace std;
int n;
long long m, mx = -1e18, mn = 1e18;
long long a[500010], b[500010];

inline int check(long long x)
{
    int sz = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (x >= a[i])
        {
            b[++sz] = x-a[i];
        }
    }
    sort(b+1, b+sz+1);
    int sum = 0;
    for (int i = 1; i <= sz; ++i)
    {
        sum += b[i];
        if (sum > m)
        {
            return i-1; 
        }
    }
    return sz;
}

inline void maxin(int &a, int b)
{
    if (a < b)
    {
        a = b;
    }
}

int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    // cout << 5000 * 5000 * (1.0 * log(5000) / log(2));
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        scanf("%lld", &a[i]);
        mx = max(mx, abs(a[i]));
        mn = min(mn, a[i]);
    }
    if (n <= 5000)
    {
        int ans = 0;
        for (int i = 1; i <= n; ++i)
        {
            // ans = max(ans, check(i));
            maxin(ans, check(a[i]));
        }
        cout << ans << endl;
    }
    else if (mx <= 100)
    {
        // cout << mx << " " << mn << "\n";
        int ans = 0;
        for (int i = mn; i <= mx; ++i)
        {
            // ans = max(ans, check(i));
            maxin(ans, check(a[i]));
        }
        cout << ans << endl;
    }
    else
    {
        cout << check(mx) << endl;
    }
    // int bestans = 0;
    // long long l = mn, r = mx;
    // while (l <= r)
    // {
    //     long long mid = (l + r) >> 1;
    //     int ans = check(mid);
    //     if (ans == n)
    //     {
    //         cout << n << endl;
    //         return 0;
    //     }
    //     if (ans < bestans)
    //     {

    //     }
    // }
    return 0;
}
    // freopen("cristal.in", "R", stdin);
    // freopen("crystal.out", "W", stdout);