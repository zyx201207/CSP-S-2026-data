#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inl __attribute((always_inline)) inline
const int N = 5e5 + 10, inf = 1e18;
inl int read()
{
    int x = 0, f = 1;
    char c = getchar();
    while (!isdigit(c))
    {
        if (c == '-')
            f = -1;
        c = getchar();
    }
    while (isdigit(c))
    {
        x = x * 10 + (c - '0');
        c = getchar();
    }
    return x * f;
}
int n, m;
int a[N], d[N], pre[N];
bool check(int mid)
{
    int sum = inf;
    for (int i = mid; i <= n; i++)
    {
        sum = min(sum, a[i] * mid - pre[i - 1]);
        // cout << sum << ' ';
    }
    if (sum > m)
        return false;
    return true;
}
signed main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    n = read(), m = read();
    for (int i = 1; i <= n; i++)
        a[i] = read();
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++)
        pre[i] = pre[i - 1] + a[i];
    int l = 0, r = n, mid;
    while (l <= r)
    {
        mid = l + r >> 1;
        if (check(mid))
            l = mid + 1;
        else
            r = mid - 1;
    }
    cout << l << '\n';
    return 0;
}
