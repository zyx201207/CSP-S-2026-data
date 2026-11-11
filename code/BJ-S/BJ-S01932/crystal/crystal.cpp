#include <bits/stdc++.h>
using namespace std;

long long read()
{
    long long x = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch > '9') { if (ch == '-') f = -f; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { x = x * 10 + ch - 48; ch = getchar(); }
    return x * f;
}

long long n, m, a[500010], ans = 0, sa[500010];

int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    n = read(), m = read();
    for (int i = 1; i <= n; i++) a[i] = read();
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) sa[i] = sa[i - 1] + a[i];
    for (int i = 1; i <= n; i++)
    {
        while (m - ans * a[i] + sa[i - 1] - sa[i - ans - 1] >= 0 && i - ans >= 1) ans++;
    }
    printf("%lld", ans);
    return 0;
}
