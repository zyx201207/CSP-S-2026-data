#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll N=5e5+5;
ll n,m,gc,mi=INT64_MAX,ma=INT64_MIN,s[N<<2];
bool B=true;
vector<ll>a;
inline void pushup(ll rt){s[rt]=s[rt<<1]+s[rt<<1|1];}
inline void build(ll rt,ll l,ll r)
{
	if(l==r)
	{
		s[rt]=a[l-1];
		return;
	}
	ll mid=(l+r)>>1;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
	pushup(rt);
}
inline ll query(ll L,ll R,ll rt,ll l,ll r)
{
	if(L<=l&&r<=R)
		return s[rt];
	ll mid=(l+r)>>1;
	ll ans=0;
	if(L<=mid)ans+=query(L,R,rt<<1,l,mid);
	if(R>mid)ans+=query(L,R,rt<<1|1,mid+1,r);
	return ans;
}
ll find(ll x)
{
	ll id=upper_bound(a.begin(),a.end(),x)-a.begin();
	ll l=1,r=id;
	while(l<r)
	{
		ll mid=(l+r)>>1;
		ll num=(id-mid+1)*x-query(mid,id,1,1,n);
		if(m==num)
			return id-mid+1;
		if(m<num)
			l=mid+1;
		else
			r=mid;
	}
	return id-l+1;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	a.resize(n);
	for(ll i=0;i<n;i++)
	{
		cin>>a[i];
		mi=min(a[i],mi);
		ma=max(a[i],ma);
		if(i==1)
			gc=a[i]-a[i-1];
		if(a[i]-a[i-1]!=gc&&i>1)
			B=false;
	}
	if(B)
	{
		ll x=m/gc;
		ll i=1;
		while(i*(i+1)<=x*2)
			i++;
		i--;
		cout<<i+1<<endl;
		return 0;
	}
	sort(a.begin(),a.end());
	build(1,1,n);
	ll ans=0;
	for(ll i=mi;i<=ma;i++)
	{
		ll x=find(i);
		ans=max(ans,x);
	}
	cout<<ans<<endl;
	return 0;
}
