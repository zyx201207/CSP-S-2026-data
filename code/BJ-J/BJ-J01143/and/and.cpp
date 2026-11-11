#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m;
    cin >> n >> m;
    long long a[n];
    for(int i=0;i<n;i++)
    {
       cin >> a[i];
    }
    long long b[n];
    long long ma=0;
    for(long long k=0;k<n;k++)
    {
    for(long long i=0;i<n;i++)
    {
        for(long long j=i;j<n;j++)
        {
            b[i] = max(m,(a[i]&a[j]));
        }
    }
    for(long long i=0;i<n;i++)
    {
        a[i]=b[i];
    }
    }
    for(long long i=0;i<n;i++)
    {
        ma = max(ma,b[i]);
    }
    cout << ma;
    return 0;
}
