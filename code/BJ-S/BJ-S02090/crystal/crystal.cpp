#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500010];
long long aa[501010];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }

    sort(a+1,a+n+1);

    long long ma=-1;
    for(int i=1;i<=n;i++)
    {
        long long k=1;
        long long u=m;
        for(int j=1;j<=n;j++)
            aa[j]=a[j];
        for(int j=i-1;j>=1;j--)
        {
            if(a[i]-a[j]<=u)
            {
                u-=a[i]-a[j];
                k++;
                aa[j]=a[i];
            }
        }
        if(k>=ma)
                ma=k;
    }
    cout<<ma;
    return 0;
}
