#include <bits/stdc++.h>
using namespace std;
long long a[500005],s[500005],t[500005];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m,ans = 0,maxn = -2e9;
    cin >> n >> m;
    for(int i = 1;i<=n;i++)
    {
        cin >> a[i];
        maxn = max(maxn,abs(a[i]));
    }
    int flag = 0;
    for(int i = 3;i<=n;i++)
    {
        if(a[i]-a[i-1]!=a[i-1]-a[i-2])
        {
            flag = 1;
        }
    }
    if(flag == 0)
    {
        if(a[2]-a[1]<0)
        {
            flag = 2;
        }
    }
    if(flag == 1)
    {
        sort(a+1,a+n+1);
        for(int i = 1;i<=n;i++)
        {
            long long cnt = 1,k = m;
            for(int j = i-1;j>=1;j--)
            {
                if(a[i]>=a[j]&& k >= (a[i]-a[j]))
                {
                    cnt++;
                    k = k - a[i] + a[j];
                }
            }
            ans = max(ans,cnt);
        }
        cout << ans << endl;
    }
    else if(flag == 0)
    {
        long long k = m;
        a[0] = a[1];
        for(int i = 1;i<=n;i++)
        {
            if(k>(i-1)*(a[i]-a[i-1]))
            {
                k-=(i-1)*(a[i]-a[i-1]);
            }
            else
            {
                cout << i << endl;
                break;
            }
        }
    }
    else if(flag == 2)
    {
        long long k = m;
        a[n+1] = a[n];
        for(int i = n;i>=1;i--)
        {
            if(k>(n-i)*(a[i]-a[i+1]))
            {
                k-=(n-i)*(a[i]-a[i+1]);
            }
            else
            {
                cout << n-i+1 << endl;
                break;
            }
        }
    }
    return 0;
}
