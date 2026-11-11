#include <bits/stdc++.h>
using namespace std;
long long a[500010], ans, num[500010];
int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    long long n, m, tot = 0;
    bool flag = 1;
    cin>>n>>m;
    for(int i = 1;i <= n;i++)
    {
        cin>>a[i];
    }
    a[0] = 10000000000000;
    sort(a + 1, a + n + 1);
    int d = a[2] - a[1];
    for(int i = 1;i <= n;i++)
    {
        if(i != 1)
        {
            if(a[i] - a[i - 1] != d)flag = 0;
        }
        if(a[i] != a[i - 1])num[++tot] = a[i];
    }
    if(flag)
    {
        int t = 0;
        while(m - t >= 0)
        {
            m -= t;
            t += d;
            ans++;
        }
        cout<<min(ans, n);
        return 0;
    }
    for(int j = 1;j <= tot;j++)
    {
        long long i = num[j];
        long long cnt = 0, t = m;
        long long pos = upper_bound(a + 1, a + n + 1, i) - a - 1;
        long long l = pos;
        while(1)
        {
            if(l < 1)
            {
                break;
            }
            if(abs(a[l] - i) <= t)
            {
                t -= abs(a[l] - i);
                cnt++;
                l--;
            }
            else break;
            
        }
        ans = max(ans, cnt);
    }
    cout<<ans;
    return 0;
}