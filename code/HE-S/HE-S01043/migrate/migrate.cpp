#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

inline long long read()
{
    long long f = 1, x = 0;
    char ch = getchar();
    while (ch < '0' || '9' < ch)
    {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while ('0' <= ch && ch <= '9')
    {
        x = x * 10 + (ch - '0');
        ch = getchar();
    }
    return f * x;
}

const int NR = 2e6 + 10;
int n;
long long d;
long long a[NR];
int pre[NR], suf[NR];

int get_prv(int i)
{
    int res = lower_bound(a + 1, a + n + 1, a[i] - d) - a;
    if (res >= i) res = 0;
    return res;
}

int get_nxt(int i)
{
    int res = upper_bound(a + 1, a + n + 1, a[i] + d) - a - 1;
    if (res <= i) res = n + 1;
    return res;
}

int main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    int tcase = read(), T = read();
    while (T --)
    {
        n = read();
        d = read();
        for (int i = 1; i <= n; i ++)
        {
            a[i] = read();
        }
        for (int i = 1; i <= n; i ++)
        {
            pre[i] = 1;
            int l = get_prv(i);
            if (l < 1) continue;
            if (get_nxt(l) == i)
            {
                pre[i] = pre[l] + 1;
                int j = i - 1;
                if (i < n)
                {
                    int p = get_prv(i + 1);
                    if (p != 0) j = min(j, p - 1);
                }
                pre[i] += j - l;
            }
            //printf("pre[%d] = %d\n", i, pre[i]);
        }
        for (int i = n; i >= 1; i --)
        {
            suf[i] = 1;
            int r = get_nxt(i);
            if (r > n) continue;
            if (get_prv(r) == i)
            {
                suf[i] = suf[r] + 1;
                int j = i + 1;
                if (i > 1)
                {
                    int p = get_nxt(i - 1);
                    if (p != n + 1) j = max(j, p + 1);
                }
                suf[i] += r - j;
            }
            //printf("suf[%d] = %d\n", i, suf[i]);
        }
        long long ans = 0;
        for (int i = 1; i < n; i ++)
        {
            int l = get_prv(i);
            if (l < 1) continue;
            if (get_nxt(l) > i + 1) continue;
            int r = get_nxt(i + 1);
            if (r > n) continue;
            if (get_prv(r) < i) continue;
            int resl = 0;
            if (get_nxt(l) == i + 1)
            {
                resl += pre[l];
                int j = i - 1;
                if (i + 2 <= n)
                {
                    int p = get_prv(i + 2);
                    if (p != 0) j = min(j, p - 1);
                }
                resl += j - l;
            }
            else
            {
                int j1 = i - 1;
                int p = get_prv(i + 1);
                if (p == 0) continue;
                j1 = min(j1, p - 1);
                int j2 = i - 1;
                if (i + 2 <= n)
                {
                    int p = get_prv(i + 2);
                    if (p != 0) j2 = min(j2, p - 1);
                }
                resl += j2 - j1;
            }
            int resr = 0;
            if (get_prv(r) == i)
            {
                resr += suf[r];
                int j = i + 2;
                if (i - 1 >= 1)
                {
                    int p = get_nxt(i - 1);
                    if (p != n + 1) j = max(j, p + 1);
                }
                resr += r - j;
            }
            else
            {
                int j1 = i + 2;
                int p = get_nxt(i);
                if (p == n + 1) continue;
                j1 = max(j1, p + 1);
                int j2 = i + 2;
                if (i - 1 >= 1)
                {
                    int p = get_nxt(i - 1);
                    if (p != n + 1) j2 = max(j2, p + 1);
                }
                resr += j1 - j2;
            }
            //printf("i = %d, resl = %d, resr = %d\n", i, resl, resr);
            ans += 1ll * resl * resr;
        }
        printf("%lld\n", ans);
    }
    return 0;
}