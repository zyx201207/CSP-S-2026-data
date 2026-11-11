#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    long long a[510000],c[510000];
    for(long long i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(long long i=1;i<=n;i++)
    {
        c[i]=a[i]+c[i-1];
    }
    long long ans=0;
    for(long long i=1;i<=n;i++)
    {
        long long x=a[i]*i;
        if(x-c[i]>m)break;
        ans++;
    }
    if(ans==0)ans=1;
    cout<<ans;
    return 0;
}
