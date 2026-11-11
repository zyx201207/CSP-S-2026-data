#include <bits/stdc++.h>
using namespace std;
int gcd(int n,int m)
{
    if (m==0)  return n;
    return gcd(m,n%m);
}
int a[200005];
char b[200005];
string c,d;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin >> n;
    for (int i=1;i<=n;i++)
    {
        cin >> a[i] >> b[i];
    }
    int kk=a[1];
    for (int i=2;i<=n;i++)
    {
        kk=gcd(kk,a[i]);
    }
    for (int i=1;i<=n;i++)
    {
        a[i]/=kk;
    }
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=a[i];j++)
        {
            c+=b[i];
        }
    }
    for (int i=n;i>=1;i--)
    {
        for (int j=1;j<=a[i];j++)
        {
            d+=b[i];
        }
    }
    long long ans=0;
    int m=c.size();
    for (int i=0;i<m;i++)
    {
        if (c[i]!=d[i])
        {
            ans++;
        }
    }
    cout << ans*kk/2;
    return 0;
}
