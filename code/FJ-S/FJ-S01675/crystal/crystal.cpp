#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m;
ll a[5000005];
ll ans=-1,ans2=-1;
bool chek(ll x)
{
	ll d=0,g=-1;
	for(int i=1;i<=n;i++)
	{
		if(a[i]<=x)
		{
			d+=x-a[i]; 
		}
		else
		{
			g=i-1;
			break;
		}
	}
	if(d<=m)
	{
		ans=max(ans,g);
		return true;
	}
	return false;
}
ll h(int k)
{
	ll d=0,cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]>k)
		{
			for(int j=i-1;j>=1;j--)
			{
				if(d+(k-a[j])<=m)
				{
					d=d+(k-a[j]);
					cnt++; 
				}
			}
			break;
		}
	}
	return cnt;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(m>1e8)
	{
		ll l=a[1],r=a[n]+1;
		while(l<r)
		{
			ll mid=l+(r-l+1)/2;
			if(chek(mid))
			{
				l=mid;
			}
			else
			{
				r=mid-1;
			}
		}
		cout<<ans;
	}
	else
	{
		ll l2=a[1],r2=a[n];
		for(int i=l2;i<=r2;i++)
		{
			ans2=max(ans2,h(i));
		}
		cout<<ans2;
	}
	return 0;
} 
