#include<bits/stdc++.h>
using namespace std;
long long a[1000010];
long long n,m;
bool check(long long x)
{
    if(x==1)
    {
        return true;
    }
    long long sum=0;
    for(int i=1;i<=x-1;i++)
    {
        sum+=a[i];
    }
    for(int i=x;i<=n;i++)
    {
        sum=sum+a[i];
        sum-=a[i-x];
        long long need=a[i]*(x-1)-(sum-a[i]);
        if(need<=m)
        {
            return true;
        }
    }
    return false;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    long long l=1;
    long long r=n;
    long long best=-1;
    while(l<=r)
    {
        long long mid=(l+r)/2;
        if(check(mid))
        {
            best=mid;
            l=mid+1;
        }
        else
        {
            r=mid-1;
        }
    }
    cout<<best;
    return 0;
}
