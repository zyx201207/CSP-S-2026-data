#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fo(i,a,b) for(ll i=a;i<=b;i++)
#define fd(i,a,b) for(ll i=a;i>=b;i--)
const ll N=2e5+5;
ll n,l,r,lw,rw,ans,x;
struct xx
{
	ll a,s;
	char c;
}a[N];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	fo(i,1,n)
	{
		cin>>a[i].a>>a[i].c;
		a[i].s=a[i].a+a[i-1].s;
	}
//	fo(i,1,n)
//	{
//		cout<<a[i].s<<endl;
//	}
	l=1;
	lw=1;
	r=a[n].s;
	rw=n;
//	cout<<l<<" "<<r<<" "<<lw<<" "<<rw<<" "<<ans<<endl;
	while(l<r)
	{
		x=min(a[lw].s-l+1,r-a[rw-1].s);
		if(a[lw].c!=a[rw].c)ans+=x;
		if(a[lw].s-l+1==x)lw++;
		else rw--;
		l+=x;
		r-=x;
//		cout<<l<<" "<<r<<" "<<lw<<" "<<rw<<" "<<ans<<endl;
	}
	cout<<ans<<endl;
}
