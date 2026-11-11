#include <bits/stdc++.h>
using namespace std;

long long n;
long long m,a[500001],c[500001],p[500001];

int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    long long ans=0;
    for(long long i=2;i<=n;i++)
    {
        long long t=a[i]-a[i-1];
        for(long long j=1;j<i;j++)
        {
            c[j]+=t;
        }
        long long total=0;
        long long j=i-1;
        for(;j>=1;j--)
        {
            total+=c[j];
            if(total>m) break;
        }
        ans=max(ans,i-j);
    }
    cout<<ans;
    return 0;
}
