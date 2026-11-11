#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define faster ios::sync_with_stdio(0);cin.tie(0)
struct sgt
{
	#define pl (p*2)
	#define pr (p*2+1)
	#define mid ((l+r)/2)
	ll sum[2000006],tag[2000006];
	void push_down(ll p,ll l,ll r)
	{
		sum[pl]+=tag[p]*(mid-l+1);
		sum[pr]+=tag[p]*(r-mid);
		tag[pl]+=tag[p];
		tag[pr]+=tag[p];
		tag[p]=0;
	}
	void add(ll p,ll l,ll r,ll x,ll y,ll d)
	{
		if (x<=l&&r<=y)
		{
			sum[p]+=(r-l+1)*d;
			tag[p]+=d;
			return;
		}
		push_down(p,l,r);
		if (x<=mid)add(pl,l,mid,x,y,d);
		if (mid<y)add(pr,mid+1,r,x,y,d);
		sum[p]=sum[pl]+sum[pr];
	}
	ll ask(ll p,ll l,ll r,ll x)
	{
		if (l==r)return l+1;
		push_down(p,l,r);
		if (x>=sum[pr])return ask(pl,l,mid,x-sum[pr]);
		else return ask(pr,mid+1,r,x);
		sum[p]=sum[pl]+sum[pr];
	}
	#undef pl
	#undef pr
	#undef mid
}xds;
ll n,m,a[500005],ans=1;
int main()
{
	faster;
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for (ll i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for (ll i=2;i<=n;i++)
	{
		xds.add(1,0,n,1,i-1,a[i]-a[i-1]);
		// cout<<a[i]-a[i-1]<<" ";
		// cout<<xds.ask(1,0,n,m)<<"\n";
		ans=max(ans,i-xds.ask(1,0,n,m)+1);
	}
	cout<<ans;
	return 0;
}