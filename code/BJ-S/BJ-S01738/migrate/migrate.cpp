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

int n, d;

int a[2000100], l[2000100], r[2000100], z[2000100];

inline int findmin(int x, int y)
{
    int l = 1, r = n, ansl = n;
    while(l <= r)
    {
        int mid = (l + r) / 2;
        if(a[mid] >= x)ansl = mid, r = mid - 1;
        else l = mid + 1;
    }
    return ansl;
}

inline int findmax(int x, int y)
{
    int l = 1, r = n, ansr = 1;
    while(l <= r)
    {
        int mid = (l + r) / 2;
        if(a[mid] <= y)ansr = mid, l = mid + 1;
        else r = mid - 1;
    }
    return ansr;
}

inline int count(int x, int y)//number of a in [x,y]
{
    if(x > a[n] || y < a[1])return 0;
    // assert(x <= y);
    return findmax(x, y) - findmin(x, y) + 1;
}

signed main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    int c = read(), T = read();
    while(T--)
    {
        n = read(), d = read();
        for(int i = 1;i <= n;i++)a[i] = read();
        int ls = 0, rs = 0;
        a[n + 1] = 4000000000000000000ll;
        a[0] = -4000000000000000000ll;
        for(int i = 2;i <= n;i++)
        {
            l[i] = count(a[i] - d, min(a[i] - 1, a[i + 1] - d - 1));
            // cout << i << ' ' << l[i] << '\n';
            if(l[i] != 0)l[i] += l[findmin(a[i] - d, min(a[i] - 1, a[i + 1] - d - 1))];
        }
        for(int i = n - 1;i >= 1;i--)
        {
            r[i] = count(max(a[i] + 1, a[i - 1] + d + 1), a[i] + d);
            if(r[i] != 0)r[i] += r[findmax(max(a[i] + 1, a[i - 1] + d + 1), a[i] + d)];
        }
        for(int i = 1;i <= n;i++)
        {
            z[i] = z[i - 1];
            while(z[i] < n && a[z[i] + 1] - a[i] <= d)z[i]++;
        }
        // if(n <= 10)for(int i = 1;i <= n;i++)cout << l[i] << ' ' << r[i] << ' ' << z[i] << "\n";
        int ans = 0;
        for(int i = 1;i < n - 2;i++)
        {
            if(z[i] < i + 2)continue;
            int cur = 0;
            // if(z[i] == i + 2)
            // {
            //     int cnt = count(a[i] + d + 1, a[i + 1] + d);
            //     cout << i << ' ' << z[i] << ' ' << r[z[i]] << ' ' << a[z[i] - 2] + d + 1 << ' ' << a[z[i] - 1] + d << ' ' << cnt << '\n';
            //     cur += cnt;
            //     // if(cnt > 1 || !rl[i + 2])ans += cnt;
            //     // else if(cnt)ans += r[i + 2] * (ll[i + 1] ? l[i + 1] : 1);
            // }
            // else
            // {
            int cnt = count(a[z[i] - 2] + d + 1, a[z[i] - 1] + d);
            // if(n <= 10)cout << i << ' ' << z[i] << ' ' << r[z[i]] << ' ' << a[z[i] - 2] + d + 1 << ' ' << a[z[i] - 1] + d << ' ' << cnt << '\n';
            cur += cnt;
            if(cnt && !count(a[z[i] - 1] + d + 1, a[z[i]] + d))cur += r[findmax(a[z[i] - 2] + d + 1, a[z[i] - 1] + d)];
            // if(n <= 10)cout << "cur : " << cur << '\n';
            // if(cnt > 1 || !rl[z[i]])ans += cnt;
            // else if(cnt)ans += r[z[i]];
            // }
            if(z[i] != z[i - 1] && !count(a[z[i] - 1] - d, a[z[i]] - d - 1))cur *= (l[i] + 1);
            // if(n <= 10)cout << cur << '\n';
            ans += cur;
        }
        write(ans);
        putchar('\n');
        for(int i = 1;i <= n;i++)a[i] = l[i] = r[i] = z[i] = 0;
    }
    return 0;
}