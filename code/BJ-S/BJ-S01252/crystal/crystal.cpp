#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=5e5+7;
ll n,m;
ll a[N],c[N],q[N]={};
ll ans=1;
ll calc(ll i,ll k)
{
	return (a[i]*k-(q[i-1]-q[i-k-1]));
}
void work(ll i)
{
	ll l=0,r=i-1,cnt=0;
	while(l<=r)
	{
		ll mid=(l+r)/2;
		if(calc(i,mid)<=m)
		{
			cnt=max(cnt,mid);
			l=mid+1;
		}
		else
		{
			r=mid-1;
		}
	}
	ans=max(ans,cnt+1);
	return;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(ll i=1;i<=n;i++)
	{
		q[i]=q[i-1]+a[i];
	}
	for(ll i=n;i>=1;i--)
	{
		work(i);
		/*for(ll j=i-1;j>=1;j--)
		{
			if(sum+(a[i]-a[j])<=m)
			{
				sum+=(a[i]-a[j]);
				cnt++;
			}
			else
			{
				break;
			}
		}
		ans=max(ans,cnt);*/
	}
	cout<<ans;
	return 0;
}
