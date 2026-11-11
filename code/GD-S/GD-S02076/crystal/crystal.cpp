#include<bits/stdc++.h>
#define ll long long 
#define ygkg putchar(' ')
#define endl putchar('\n')
const ll mod=998244353;
const ll inf=1e16;
namespace io
{
	template<typename L>
	void in(L &x)
	{
		x=0;bool p=0;char ch=getchar();
		while(!isdigit(ch)) p=ch=='-',ch=getchar();
		do{x=(x<<3)+(x<<1)+(ch^48),ch=getchar();}while(isdigit(ch));
		x=p?-x:x;
	}
	template<typename L>
	void _out(L x){if(x) _out(x/10),putchar((x%10)^48);}
	template<typename L>
	void out(L x){_out(x>0?x:(x?(putchar('-'),-x):(putchar('0'),0))),endl;}	
}
using namespace io;
using namespace std;
ll n,m;
ll a[500015],sum[500015];
ll calc(ll l,ll r)
{
	return (r-l+1)*a[r]-(sum[r]-sum[l-1]);
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	in(n),in(m);
	for(ll i=1;i<=n;++i) in(a[i]);
	sort(a+1,a+n+1);
	for(ll i=1;i<=n;++i) sum[i]=sum[i-1]+a[i];
	ll ans=0;
	for(ll r=1,l=1;r<=n;++r)
	{
		while(calc(l,r)>m) ++l;
		ans=max(ans,r-l+1);
	}
	out(ans);
	return 0;
}
