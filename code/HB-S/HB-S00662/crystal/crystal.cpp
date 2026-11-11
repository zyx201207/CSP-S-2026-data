#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 5e5 + 2;

ll read()
{
    ll tot = 0, f = 1;
    char ch = getchar_unlocked();
    while(ch < '0' || ch > '9')
    {
        if(ch == '-')
            f = -1;
        ch = getchar_unlocked();
    }
    while(ch >= '0' && ch <= '9')
    {
        tot = (tot << 3) + (tot << 1);
        tot += ch - '0';
        ch = getchar_unlocked();
    }
    return tot * f;
}

ll n, m, a[N], ans;

int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    n = read();
    m = read();
    for(int i = 1; i <= n; i++)
        a[i] = read();
    sort(a + 1, a + n + 1);
    ll l = 1, r = n;
    while(l <= r)
    {
        ll mid = (l + r) >> 1;
        bool flag = false;
        ll tot = 0;
        for(int i = 1; i <= n; i++)
        {
            tot += a[i];
            if(i >= mid)
            {
                tot -= a[i - mid];
                ll tmp = a[i] * mid - tot;
                if(tmp <= m)
                {
                    flag = true;
                    break;
                }
            }
        }
        if(flag)
        {
            l = mid + 1;
            ans = mid;
        }
        else
        {
            r = mid - 1;
        }
    }
    printf("%lld", ans);
    return 0;
}