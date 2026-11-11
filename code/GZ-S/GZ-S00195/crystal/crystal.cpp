//GZ-S00195 玉屏民族中学 何子涵
#include <bits/stdc++.h>

using namespace std;
long long n,m,cnt=1;
long long a[500005];

int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for(long long i=1;i<=n;i++)
    {
     cin >> a[i];
    }
    sort(a+1,a+1+n);
    for(long long i=1;i<n;i++)
    {
        if (a[i]==a[i+1])
        {
         cnt++;
         continue;
        }
     long long x=a[i];
        if (m>0)
        {
            for(long long y=m;y>0;y-=cnt)
            {
             x++;
                if (x==a[i+1])
                {
                 cnt++;
                 m=y;
                 break;
                }
            }
        }
    }
    if (cnt==1)
    {
     cout << n;
     return 0;
    }
    cout << cnt;
    return 0;
}
