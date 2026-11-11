#include <bits/stdc++.h>

using namespace std;
const long long NUM=5*1e5+5;
long long sum[NUM];
long long sum2[NUM];
long long a[NUM];
long long b[NUM];
long long ans=1;
long long n;
long long m;

bool judge(long long y,long long x)
{
    long long len=x-y;
    long long i=len*sum[x];
    long long j=sum2[x-1];
    long long k=sum2[y-1];
    long long num=i-j+k;
    //cout<<i<<" "<<j<<" "<<k<<" "<<num<<endl;

    if(num<=m)
        return true;
    return false;
}

long long find1(long long x)
{
    long long l=1,r=x,mid;
    while(l<r)
    {
        mid=l+(r-l)/2;
        if(judge(mid,x))
        {
            r=mid;
        }
        else
        {
            l=mid+1;
        }
    }
    return r;
}

long long max1(long long x,long long y)
{
    if(x>=y)
        return x;
    return y;
}

int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    cin>>n>>m;
    int i;
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(i=2;i<=n;i++)
    {
        sum[i]=a[i]-a[1];
    }
    for(i=2;i<=n;i++)
    {
        sum2[i]=sum2[i-1]+sum[i];
    }
    for(i=1;i<=n;i++)
    {
        int x=find1(i);
        ans=max1(ans,i-x+1);
        //cout<<i<<" "<<x<<" "<<ans<<endl;
    }
    cout<<ans<<endl;
    return 0;
}
