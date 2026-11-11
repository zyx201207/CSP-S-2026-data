#include<bits/stdc++.h>
#define ll long long
using namespace std;
long long int read()
{
    long long int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9')
    {
        if(c=='-') f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9') x=(x<<1)+(x<<3)+c-'0',c=getchar();
    return x*f;
}
int n;
long long m,a[500001],sum[500001];
bool check(int x)
{
    for(int i=x;i<=n;i++)
    {
        if(a[i]*x-(sum[i]-sum[i-x])<=m) return 1;
    }
    return 0;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    n=read();
    m=read();
    for(int i=1;i<=n;i++) a[i]=read();
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
    int l=1,r=n,ans;
    while(l<=r)
    {
        int mid=l+r>>1;
        if(check(mid)) l=mid+1,ans=mid;
        else r=mid-1;
    }
    cout<<ans;
    return 0;
}
