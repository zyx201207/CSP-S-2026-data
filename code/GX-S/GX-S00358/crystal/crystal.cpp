#include<bits/stdc++.h>
using namespace std;
long long a[500005];
long long c[500005];
int main ()
{
    freopen("crystal.in","w",stdin);
    freopen("crystal.out","r",stdout);
    long long n,m;
    cin >>n;
    cin >>m;
    for (int i=1;i<=n;i++)
    {
        cin >>a[i];
    }
    long long d=0;
    long long b=0;
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=n;j++)
        {
            if (a[i]+m<=a[j+1]) d++;
        }
        if (b<d)
        {
            long long x=1;
            for (int j=i;j<=d;j++)
            {
                c[x]=a[j];
                x++;
            }
        }
        b=max(b,d);
    }
    long long ans=0,an=0;
    for (int i=b;i>=1;i--)
    {
        int y=m;
        for (int j=1;j<=i;j++)
        {
            if (c[j]+y>=c[i])
            {
                ans++;
                y-=c[i]-c[j];
            }
        }
        an=max(an,ans);
        ans=0;
    }
    cout <<an;

    return 0;
}
