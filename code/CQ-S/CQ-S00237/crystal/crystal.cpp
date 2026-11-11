#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll n,m;
ll ls[500005];
ll d[500005];

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	ll t=0,dd=0;
	for(int i=1;i<=n;i++) cin>>ls[i];
	stable_sort(ls+1,ls+n+1);
	for(int i=1;i<=n;i++) d[i]=ls[i]-ls[i-1];
	for(int i=1;i<=n;i++)
	{
		if(i<=2 || ls[i]-ls[i-1]==dd)
		{
			t++;
			dd=ls[i]-ls[i-1];
		}
	}
	if(t==n)
	{
		ll ans=0,sum=0;
		for(int i=1;i<=n;i++)
		{
			sum+=(i-1)*d[i];
			if(sum<=m) ans++;
			else break;
		}
		cout<<ans;
		return 0;
	}
	ll ans=1;
	ll sum=0,cnt=0;
	for(int i=2;i<=n;i++)
	{
		sum=0,cnt=1;
		for(int j=i+1;j<=n;j++)
		{
			sum+=(i-1)*d[i];
			if(sum<=m) cnt++;
			else break;
		}
		ans=max(cnt,ans);
	}
	cout<<ans;
	return 0;
}
