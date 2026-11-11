#include<iostream>
#include<algorithm>
using namespace std;
const int N=5e5+5;
long long a[N],sum[N];
long long read()
{
    long long x=0,fu=1;
    char ch=getchar();
    while(ch<'0'||ch>'9')
    {
        if(ch=='-')
            fu=-fu;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9')
    {
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x*fu;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,ans=0;
    long long m;
    n=read();m=read();
    for(int i=1;i<=n;i++)
        a[i]=read();
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
        sum[i]=sum[i-1]+a[i];
    for(int i=1;i<=n;i++)
    {
        int l=1,r=i,mid,pos;
        while(l<=r)
        {
            mid=(l+r)/2;
            long long val=1ll*(i-mid+1)*a[i]-sum[i]+sum[mid-1];
            if(val<=m)
            {
                pos=mid;
                r=mid-1;
            }
            else
                l=mid+1;
        }
        ans=max(ans,i-pos+1);
    }
    cout<<ans;
    return 0;
}