#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
ll m;
ll ans=0;
ll a[1000005],d[1000005],pre[1000005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for (ll i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	for (int i=1;i<=n;i++)
	{
		d[i]=a[i]-a[i-1];
	}
	d[1]=0;
	for (ll i=1;i<=n;i++)
	{
		pre[i]=pre[i-1]+d[i];
	}
	/*
	for (int i=1;i<=n;i++)
	{
		cout<<a[i]<<" ";
	}
	for (int i=1;i<=n;i++)
	{
		cout<<d[i]<<" ";
	}
	*/
	ll sum=0;
	for (ll i=1,j=1;i<=j&&j<=n;)
	{
		while(j<n&&sum+d[j+1]*(j-i+1)<=m) 
		{
			sum+=d[j+1]*(j-i+1);
			//cout<<d[j+1]*(j-i+1)<<" ";
			j++;
		}
		ans=max(ans,j-i+1);
		if (i==j)
		{
			i++,j++;
			continue;
		}
		//cout<<i<<" "<<j<<" "<<sum<<"\n";
		sum-=pre[j]-pre[i];
		i++;
		//cout<<i<<" "<<j<<" "<<sum<<"\n";
	}
	printf("%lld",ans);
	return 0;
}
