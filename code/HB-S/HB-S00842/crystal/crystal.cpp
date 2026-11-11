#include <bits/stdc++.h>
#define int long long
using namespace std;

int read()
{
    char c=getchar();
    int x=0,f=1;
    while (!isdigit(c))
    {
        if (c=='-') f=-f;
        c=getchar();
    }
    while (isdigit(c))
    {
        x=(x<<1)+(x<<3)+(c^48);
        c=getchar();
    }
    return x*f;
}
//1.duo ce yao qing kong
//2.yao kai long long

int a[500010];
int sum[500010];
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    int n=read(),m=read();
    for (int i=1;i<=n;i++) a[i]=read();
    sort(a+1,a+1+n);
    sum[0]=0;
    for (int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
    int an=0;
    for (int i=1;i<=n;i++)
    {
        int l=0,r=i-1,ans;
        while (l<=r)
        {
            int mid=(l+r)>>1;
            if ((i-mid)*a[i]-(sum[i]-sum[mid])<=m) ans=mid,r=mid-1;
            else l=mid+1;
        }
        an=max(an,i-ans);
    }
    cout<<an<<"\n";
    
    return 0;
}
//14:42 AC T1
