#include<bits/stdc++.h>
#define ll long long
#define F for
#define W while
using namespace std;
char buf[1<<23],*p1=buf,*p2=buf;
#define gc() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<23,stdin),p1==p2)?EOF:*p1++)
static inline int read()
{
    int x=0,f=1;char ch=gc();
    W(!isdigit(ch)){if(ch=='-')f=-1;ch=gc();}
    W(isdigit(ch)) x=x*10+(ch^48),ch=gc();
    return x*f;
}
const int MAXN=5e5+5;
int n,m;
int a[MAXN],sum[MAXN];
bool check(int mid,int i)
{
    int s=sum[i]-sum[mid-1];
    s=a[i]*(i-mid+1)-s;
    return (s<=m);
}
int solve(int i)
{
    int l=1,r=i,mid,ans=i;
    W(l<=r)
    {
        mid=(l+r)/2;
        if(check(mid,i)) r=mid-1,ans=mid;
        else l=mid+1;
    }
    // cout<<ans<<'\n';
    return i-ans+1;
}
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    n=read(),m=read();
    F(int i=1;i<=n;i++) a[i]=read();
    sort(a+1,a+n+1);
    F(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
    int ans=0;
    F(int i=2;i<=n;i++)
    {
        int did=solve(i);
        ans=max(ans,did);
    }
    cout<<ans<<'\n';
    return 0;
}