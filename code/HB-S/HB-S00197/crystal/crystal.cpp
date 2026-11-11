#include <bits/stdc++.h>
using namespace std;
using LL = long long;

LL n,m;
LL a[500005];
LL sum = 0,cnt = 0;
LL maxn = 1e7;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);

    for (int i=1;i<=n;i++)
    {
        if (a[i] == a[i+1])
        {
            cnt+=2;
            if ((a[i] - a[i-1]) > (a[i+2] - a[i+1]))
            {
                m-=(a[i+2] - a[i+1]);
                if (m >= 0)
                {
                    a[i+2] = a[i+1];
                    cnt+=2;
                }
                else
                {

                    break;
                }
            }
            if ((a[i] - a[i-1]) < (a[i+2] - a[i+1]))
            {

                m -= (a[i] - a[i-1]);
                if (m >= 0)
                {

                    a[i-1] = a[i];
                    cnt+=2;
                }
                else
                {
                    break;
                }
            }

        }

    }

   if (n % 2 != 0)
    {
        for (int i=1;i<=n;i++)
        {

            LL c = a[n/2+1] - a[1];
            LL v = a[n] - a[n/2+1];
            if (c < v)
            {
                for (int j=1;j<=n/2+1;j++)
                {
                    if (m >= 0)
                    {
                        m -= (a[j+1] - a[j]);
                        cnt++;
                    }
                }
            }
            else if (v < c)
            {

                for (int j=n/2+1;j<=n;j++)
                {
                    if (m >= 0)
                    {
                        m -= (a[j+1] - a[j]);
                        cnt++;
                    }
                }
            }
        }

    }




    cout<<cnt;
    return 0;
}
//RP++;
