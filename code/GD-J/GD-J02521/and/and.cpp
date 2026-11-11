#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inl __attribute((always_inline)) inline
#define gc() getchar()
const int N = 2e5 + 10;
inl char gc()
{
    static char buf[1 << 20], *p1 = buf, *p2 = buf;
    return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 20, stdin), p1 == p2) : EOF ? *p1++;
}
inl int read()
{
    int x = 0, f = 1;
    char c = gc();
    while(!isdigit(c))
    {
        if(c == '-') f = -1;
        c = gc();
    }
    while(isdigit(c))
    {
        x = x * 10 + (c - '0');
        c = gc();
    }
    return x * f;
}
int n, m, ans;
int a[N], bit[N];
set<int> S;
signed main()
{
    cin >> n >> m;
    int maxn = -1;
    for (int i = 1; i <= n; i ++){
        cin >> a[i];
        S.insert(a[i]);
    }
    int top = 0;
    for (int i = 1; i <= m; i ++)
    {
        int sum = 0;

        for (int j = 1; j <= n; j ++)
        {
            for (int k = 0; k <= top; k ++)
            {
                if((a[i] >> k) & 1)
                    sum++;
                else
                    S.reverse(a[i]);
            }
        }
        if (sum >= m)
        {
            ans += (1 << )
        }
    }
        return 0;
}
