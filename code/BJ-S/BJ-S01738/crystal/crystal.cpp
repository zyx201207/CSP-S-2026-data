#include <bits/stdc++.h>
#define int long long
using namespace std;

inline int read()
{
    register char c = getchar();
    register int x = 0, f = 1;
    while(c < '0' || c > '9')
    {
        if(c == '-')f = -1;
        c = getchar();
    }
    while(c <= '9' && c >= '0')
    {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x * f;
}

inline void _write(int x)
{
    if(!x)return;
    _write(x / 10);
    putchar(x % 10 + '0');
    return;
}

inline void write(int x)
{
    if(x < 0)putchar('-'), x = -x;
    if(x == 0)putchar('0');
    else _write(x);
}

int n, m;

int a[500010];

signed main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    n = read(), m = read();
    for(int i = 1;i <= n;i++)a[i] = read();
    sort(a + 1, a + n + 1);
    int ans = 1, pos = n, cur = m, tot = 1;
    for(int i = n;i >= 1;i--)
    {
        tot--;
        cur += tot * (a[i + 1] - a[i]);
        while(pos > 0 && a[i] - a[pos] <= cur)cur -= (a[i] - a[pos]), pos--, tot++;
        ans = max(ans, tot);
    }
    cout << ans << "\n";
    return 0;
}