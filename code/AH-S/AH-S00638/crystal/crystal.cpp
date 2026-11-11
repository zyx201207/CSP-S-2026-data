#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline void read(int &x)
{
    x=0;
    char ch=getchar(),f=1;
    while(ch<'0'||ch>'9')f=(ch=='-')?-f:f,ch=getchar();
    while(ch>='0'&&ch<='9')x=x*10+ch-48,ch=getchar();
    x*=f;
}
inline void readl(ll &x)
{
    x=0;
    char ch=getchar(),f=1;
    while(ch<48||ch>57)f=(ch=='-')?-f:f,ch=getchar();
    while(ch>=48&&ch<=57)x=x*10+ch-48,ch=getchar();
    x*=f;
}
const int N=5e5+5;
int n,ans,cnt;
ll m,a[N],sum;
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    read(n),readl(m);
    for(int i=1;i<=n;i++)readl(a[i]);
    sort(a+1,a+1+n);
    int l=1,r=1;
    while(l<=r&&l<=n&&r<=n)
    {
        sum+=(a[r]-a[r-1])*(r-l),cnt++;
        while(sum>m)sum-=a[r]-a[l],l++,cnt--;
        ans=max(ans,cnt),r++;
    }
    cout<<ans;
    return 0;
}
