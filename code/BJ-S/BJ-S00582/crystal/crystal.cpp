#include <bits/stdc++.h>
#define int long long

using namespace std;

int n, m;
int a[500005];
int sum[500005];
int l;
int r;
int cnt = 0;

int func1()
{
    int x = abs(a[l] - a[n / 2 + 1]);
    int y = abs(a[r] - a[n / 2 + 1]);

    if(x > y)
    {
        cnt -= x;
        l++;
    }
    else
    {
        cnt -= y;
        r--;
    }
}

int func2()
{
    int x = abs(a[r] - a[n / 2]);
    int y = abs(a[l] - a[n / 2 + 1]);

    if(x > y)
    {
        cnt -= x;
        r--;
    }
    else
    {
        cnt -= y;
        l++;
    }
}

signed main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    scanf("%lld %lld", &n, &m);
    l = 1;
    r = n;

    for(int i = 1; i <= n; i++)
    {
        scanf("%lld", &a[i]);
    }

    sort(a + 1, a + 1 + n);

    int p = a[n / 2 + 1];

    int minx = LONG_LONG_MAX;

    for(int i = 1; i <= n; i++)
    {
        cnt += abs(a[i] - p);
        if(i != n / 2 + 1)
            minx = min(minx, abs(a[i] - p));
    }

    if(minx > m)
    {
        printf("1");
        return 0;
    }

    while(cnt > m && l <= r)
    {
        if(n % 2 == 0)
        {
            func1();
        }
        else
        {
            func2();
        }
    }
    if(cnt <= m && l <= r)
    {
        printf("%lld", r - l + 1);
    }
    else
    {
        printf("1");
    }

    return 0;
}
