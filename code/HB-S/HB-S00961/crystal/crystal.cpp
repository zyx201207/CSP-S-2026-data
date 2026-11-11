#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=5e5+10;
int n,m,a[maxn],s[maxn];
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0' || ch>'9')
    {
        if(ch=='-')f=-f;
        ch=getchar();
    }
    while(ch>='0' && ch<='9')x=x*10+ch-'0',ch=getchar();
    return x*f;
}
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    n=read();m=read();
    for(int i=1;i<=n;i++)a[i]=read();
    sort(a+1,a+n+1);for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        int l=1,r=i,res=0;
        while(l<=r)
        {
            int mid=(l+r)>>1;
            if(a[i]*mid-(s[i]-s[i-mid])<=m)res=mid,l=mid+1;
            else r=mid-1;
        }
        ans=max(ans,res);
    }
    printf("%lld\n",ans);
    return 0;
}
