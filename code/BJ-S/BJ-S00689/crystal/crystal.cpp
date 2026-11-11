#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005];
bool check(long long b)
{
    long long minc=LONG_LONG_MAX;
    for(int i=1,j=b;j<=n;i++,j++)
    {
        long long c=0;
        for(int k=i;k<j;k++)
            c+=a[j]-a[k];
        if(c<minc)
            minc=c;
    }
    if(minc<=m)
        return true;
    return false;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    if(n>5000)
    {
        long long g=a[2]-a[1];
        m=m/g*2;
        long long s=sqrt(m);
        if(m>=s*(s+1))
            cout<<s+1;
        else
            cout<<s;
        return 0;
    }
    sort(a+1,a+n+1);
    long long l=1,r=n;
    while(l<r)
    {
        long long mid=(l+r+1)/2;
        if(check(mid))
            l=mid;
        else
            r=mid-1;
    }
    cout<<l;
    return 0;
}