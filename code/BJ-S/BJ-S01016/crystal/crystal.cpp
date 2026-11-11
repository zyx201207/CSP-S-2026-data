#include <bits/stdc++.h>
using namespace std;
long long a[10005], cnt = 0;
bool man(int mid, int x)
{
    for(int i = 1; i <= mid; ++i)
    {
        if(a[i] != x)
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
    freopen("crystal.in", "w", stdin);
    freopen("crystal.out", "s", stdout);
    long long n, m;
    cin >> n >> m;
    for(long long i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    sort(a+1, a+n+1);
    long long middle = n / 2 + 1, x = 1, sum = 0;
    for(long long i = 1; i <= n; ++i)
    {
        sum += abs(a[n] - a[i]);
    }
    if(m > sum)
    {
        cout << n;
        return 0;
    }
    while(m > 0)
    {
        long long l = a[middle] - a[middle - x];
        if(m - l >= 0)
            m = m - l;
        else
            break;
        a[middle - x] = a[middle];
        ++x;
        if(man(middle, a[middle]) && m > 0 )
        {
            break;//
        }
    }
    if(m > 0)
    {
        long long last = middle;
        for(long long i = last; i <= n; ++i)
        {
            long long r = (a[middle+1] - a[middle]) * middle;
            if(m - r >= 0)
            {
                m -= r;
                middle++;
                for(long long j = 1; j <= middle-1; ++j)
                {
                    a[j] = a[middle];
                }
            }
            else
            {
                break;
            }
        }
    }
    long long ans = a[middle];
    for(long long i = 1; i <= n; ++i)
    {
        if(a[i] == ans)
        {
            ++cnt;
        }
    }
    cout << cnt << endl;
    return 0;
}