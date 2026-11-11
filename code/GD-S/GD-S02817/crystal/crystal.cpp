#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,M,ans,a[500003],b[500003],c[500005];
ll count(int s,ll l)
{
	
		ll ans=0;
		for(int i=s;i<s+l-1;i++)ans+=c[i+1]*(i-s+1);
	
	return ans;
}
int main() 
{
	ll mam=0;
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>M;
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	ll ccc=a[2]-a[1],T=1;
	for(int i=1;i<=n;i++){
		b[i]=a[i]+b[i-1];c[i]=a[i]-a[i-1];
		if(c[i]!=ccc)T=0;mam=max(mam,abs(a[i]));
	}
	if(T==1)
	{
		ll sum=0;
		ll i=1;
		for(;i<=n&&sum<=M;i++)sum+=i*ccc;
		cout<<i-1;
		return 0;
	}
	if(mam<=100&&n>5000)
	{
		ll p[500]={},q[555]={};
		for(int i=1;i<=n;i++)p[a[i]+101]++;
		for(int i=1;i<=201;i++)q[i]=p[i]-p[i-1];
		for(int l=1;l<=201;l++)
		{
			for(int i=1;i<=201-l+1;i++)
			{
				ll sun=0;
				for(int j=i;j<i+l-1;j++)
				{
					sun+=q[j+1]*(j-i+1);
				}
				if(sun<=M)ans=max(ans,l*1ll);
			}
		}
		cout<<ans;
		return 0;
	}
	ll r=n,l=1;
	while(r>=l)
	{
		ll m=(l+r)/2;
		ll an=1e18;
		for(int i=1;i<=n-m+1;i++)
		{
			an=min(an,count(i,m));
		}
		if(an<=M&&m>ans)
		{
			ans=m;
			l=m+1;
		}
		else{
			r=m-1;
		}
	}
	cout<<ans;
	return 0;
}
