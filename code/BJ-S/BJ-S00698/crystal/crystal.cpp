#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
ll m;
const int N = 500005;

ll a[N];

ll read()
{
    ll x = 0;
    int f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = (x << 3) + (x << 1) + ch - '0';
        ch = getchar();
    }
    return f * x;
}

bool check(int x)
{
    ll sm = 0;
    for (int i = 1; i <= x; i++)
        sm += a[i];
    for (int l = 1, r = x; r <= n; l++, r++)
    {
        if (a[r] * x - sm <= m)
            return true;
        sm += a[r + 1] - a[l];
    }
    return false;
}

void solve()
{
    n = read(), m = read();
    for (int i = 1; i <= n; i++)
        a[i] = read();
    sort(a + 1, a + n + 1);
    int l = 1, r = n, ans = -1;
    while (l <= r)
    {
        int mid = l + r >> 1;
        if (check(mid))
        {
            ans = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }
    printf("%d", ans);
}

int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    solve();
    return 0;
}
//O(n*log(n)), O(n), 100pts
