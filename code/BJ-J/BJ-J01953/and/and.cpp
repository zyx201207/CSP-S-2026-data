#include <bits/stdc++.h>
using namespace std;

long long read()
{
    long long x = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch > '9') { if (ch == '-') f = -f; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { x = x * 10 + ch - 48; ch = getchar(); }
    return x * f;
}

long long n, m, a[200010], b[40], cnt[1100], ans, maxn, ans7;
bool flag6 = 0, flag7 = 0, flag8 = 0, flagA = 0, flagB = 0;

long long qpow(int base, int ex)
{
    long long mul = 1;
    while (ex)
    {
        if (ex & 1) mul = mul * base;
        base = base * base;
        ex >>= 1;
    }
    return mul;
}

void dfs(int step, int cnt, long long sum)
{
    if (step > n)
    {
        if (cnt == m) ans = max(ans, sum);
        return ;
    }
    if (cnt > m) return ;
    dfs(step + 1, cnt + 1, sum & a[step]);
    dfs(step + 1, cnt, sum);
}

int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    n = read(), m = read();
    if (m == 1) flag6 = 1;
    if (n == m) flag7 = 1, ans7 = 2147483647;
    if (m == 2) flag8 = 1;
    flagA = 1;
    for (int i = 1; i <= n; i++)
    {
        a[i] = read();
        maxn = max(maxn, a[i]);
        if (flag7) ans7 = ans7 & a[i];
        if (flagA) for (int j = 0; j <= 30; j++)
        {
            if (a[i] == qpow(2, j) - 1) break;
            if (j == 30) flagA = 0;
        }
    }
    if (n <= 20) dfs(1, 0, 2147483647);
    else if (flag6) ans = maxn;
    else if (flag7) ans = ans7;
    else if (flag8)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                ans = max(ans, a[i] & a[j]);
            }
        }
    }
    else if (flagA)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= 30; j++)
            {
                if (a[i] == qpow(2, j) - 1)
                {
                    b[j]++;
                    break;
                }
            }
        }
        int sum = 0;
        for (int j = 30; j >= 0; j--)
        {
            sum += b[j];
            if (sum >= m)
            {
                ans = qpow(2, j) - 1;
                break;
            }
        }
    }
    else if (maxn < 4)
    {
        for (int i = 1; i <= n; i++)
        {
            cnt[a[i]]++;
        }
        if (cnt[3] >= m) ans = 3;
        else if (cnt[3] + cnt[2] >= m) ans = 2;
        else if (cnt[3] + cnt[1] >= m) ans = 1;
        else ans = 0;
    }
    printf("%lld\n", ans);
    return 0;
}
