#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;ll m;bool tb=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n==1) tb=0;
	else
	{
		ll c=a[2]-a[1];
		for(int i=3;i<=n;i++)
		{
			if(c!=a[i]-a[i-1])
			{
				tb=0;
				break;
			}
		}
	}
	if(tb)
	{
		ll s=a[2]-a[1];
		cout<<floor((-s+sqrt(s*s+8*m*s))/2/s)+1;
		return 0;
	}
	int print=1;
	sort(a+1,a+n+1);
	if(n>1e4)
	{
		int xxx=10000;
		mt19937 rnd(434323);
		while(xxx--)
		{
			ll sum=m;
			int ans=1,i=(rnd()+n)%n+1;
			for(int j=i-1;j>=1;j--)
			{
				sum-=(a[i]-a[j]);
				if(sum>=0) ans++;
				else break;
			}
			print=max(print,ans);
		}
		cout<<print;return 0;
	}
	for(int i=n;i>=1;i--)
	{
		ll sum=m;
		int ans=1;
		for(int j=i-1;j>=1;j--)
		{
			sum-=(a[i]-a[j]);
			if(sum>=0) ans++;
			else break;
		}
		print=max(print,ans);
	}cout<<print;
	return 0;
}
