#include<bits/stdc++.h>
#define ll long long 
#define ygkg putchar(' ')
#define endl putchar('\n')
#define fi first
#define se second
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
ll n,d,x[2000015],t[2000015],r[2000015],l[2000015],ls[2000015],rs[2000015],sl[2000015],sr[2000015];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ll c,T;in(c),in(T);
	while(T--)
	{
		in(n),in(d);
		for(ll i=1;i<=n;++i) in(x[i]),ls[i]=rs[i]=sl[i]=sr[i]=0;
		for(ll rt=n,lf=n+1;rt>=1;--rt)
			while(lf&&x[rt]-x[lf-1]<=d) r[--lf]=rt;
		for(ll lf=1,rt=0;lf<=n;++lf)
			while(rt<=n&&x[rt+1]-x[lf]<=d) l[++rt]=lf;
		for(ll i=1;i<=n;++i) ++ls[r[i]],++rs[l[i]];
		ll ans=0;
		for(ll i=1;i<n;++i)
		{
			sl[i]=ls[i];
			if(r[l[i]]==i) sl[i]+=sl[l[i]];
		}
		for(ll i=n;i>1;--i)
		{
			sr[i]=rs[i];
			if(l[r[i]]==i) sr[i]+=sr[r[i]];
		}
		for(ll i=1;i<n;++i)
		{
			if(l[i]==i||r[i+1]==i+1) continue;
			ll lf=0,rt=0;
			if(r[l[i]]==i+1) lf=sl[l[i]];
			if(l[r[i+1]]==i) rt=sr[r[i+1]];
			ll lp=ls[i+1]-(r[i]==i+1),rp=rs[i]-(l[i+1]==i);
			if(r[l[i]]==i+1&&l[r[i+1]]==i) ans+=lf*rt;
			if(r[l[i]]==i+1) ans+=lf*rp;
			if(l[r[i+1]]==i) ans+=lp*rt;
			ans+=lp*rp;
		}
		out(ans);
	}
	return 0;
}
