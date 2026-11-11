#include <bits/stdc++.h>
#define ll long long
#define endl putchar(10)
#define spc putchar(32)
using namespace std;

ll read()
{
	ll x=0,f=1; char c=getchar(); while(c<48 || c>57)
	f=(c=='-'?-1:1), c=getchar(); while(c>47 && c<58)
	x=(x<<1)+(x<<3)+c-48, c=getchar(); return x*f;
}

void write(ll x)
{
	ll st[41],tp=0; if(x<0) putchar('-'), x=-x; do st[tp++]=x%10,
	x/=10; while(x); while(tp) putchar(st[--tp]+48);
}

ll n,m,a[500001],sum[500001],l,r,mid,ans;

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(); m=read(); for(int i=1; i<=n; ++i)
	a[i]=read(); sort(a+1,a+n+1);
	for(int i=1; i<=n; ++i) sum[i]=sum[i-1]+a[i];
	for(int i=1; i<=n; ++i) {l=0; r=i+1; while(l<r-1)
	mid=l+r>>1, (i-mid+1)*a[i]-sum[i]+sum[mid-1]>m?
	l=mid:r=mid; ans=max(ans,i-r+1);} write(ans); return 0;
}
