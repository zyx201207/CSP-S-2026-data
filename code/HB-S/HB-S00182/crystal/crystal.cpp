#include <bits/stdc++.h>
#define ll long long
const ll N=5*1e5;
using namespace std;
ll n,m,a[N],sum=1,t,cnt,ans,flag=1;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(ll i=2;i<n;i++)
		if(a[i-1]-a[i]!=a[i]-a[i+1])
			{flag=0;break;}
	if(flag)
	{
		for(ll i=n;i>=1;i--)
		{
			if(m>=(a[n]-a[i]))m-=(a[n]-a[i]),ans++;
			else break;
		}
		cout<<ans;return 0;
	}
	for(ll i=1;i<=n;i++)
	{
		t=m;
		cnt=0;
		for(ll j=i;j>=1;j--)
		{
			ll k=a[i]-a[j];
			if(t>=k)t-=k,cnt++;
			else break;
		}
		for(ll j=i+1;j<=n;j++)
		{
			if(a[j]==a[i])cnt++;
			else break;
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
}
