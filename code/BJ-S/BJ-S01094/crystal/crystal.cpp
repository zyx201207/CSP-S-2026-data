#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[500005],sum,maxn=-1e9,f;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=n;i>2;i--)
    {
        if(a[i]-a[i-1]!=a[i-1]-a[i-2])
        {
            f=1;
            break;
        }
    }
    if(f==0)
    {
        long long k=a[(n+1)/2];
        for(long long i=1;i<=n;i++)
        {
            b[i]=abs(a[i]-k);
        }
        sort(b+1,b+n+1);
        for(long long i=1;i<=n;i++)
        {
            sum+=b[i];
            if(sum>m)
            {
                cout<<i-1;
                return 0;
            }
        }
    }
    for(long long i=1;i<=n;i++)
    {
        sum=0;
        for(long long j=1;j<=n;j++)
        {
            b[j]=abs(a[j]-a[i]);
        }
        sort(b+1,b+n+1);
        for(long long j=1;j<=n;j++)
        {
            sum+=b[j];
            if(sum>m)
            {
                if(maxn<j-1)maxn=j-1;
                break;
            }
        }
    }
    cout<<maxn;
    return 0;
}
