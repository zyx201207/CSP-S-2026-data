#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const int N=1e5*5+10;
ll n,m;
int a[N];
ll ans;
ll as[N];
ll lmax(ll b,ll s)
{
	if(b>=s)
	{
		return b;
	}
	else
	{
		return s;
	}
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	bool ts=1,fir=1;
	ll firbig;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=i)
		{
			ts=0;
		}
		as[i]=as[i-1]+a[i];
		if(as[i]>=m&&fir)
		{
			firbig=i;
			fir=0;
		}
	}
	for(int i=2;i<=n;i++)
	{
		if(a[i]!=a[i-1])
		{
			ts=0;
		}
	}
	if(ts)
	{
		cout<<firbig;
		return 0;
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		ll w=0;
		ll ci=1;
		for(int j=i-1;j>=1;j--)
		{
			w+=a[i]-a[j];
			if(m>=w)
			{
				ci++;
			}
		}
		ans=lmax(ans,ci);
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
