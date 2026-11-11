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

const int NR = 5e5 + 10;
long long a[NR];

int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    int n = read();
    long long m = read();
    for (int i = 1; i <= n; i ++)
    {
        a[i] = read();
    }
    sort(a + 1, a + n + 1);
    long long sum = 0;
    int ans = 0;
    for (int i = n, j = n; i >= 1; i --)
    {
        while (j >= 1 && sum + a[i] - a[j] <= m)
        {
            sum += a[i] - a[j];
            j --;
        }
        ans = max(ans, i - j);
        sum -= (a[i] - a[i - 1]) * (i - j - 1);
    }
    printf("%d\n", ans);
    return 0;
}