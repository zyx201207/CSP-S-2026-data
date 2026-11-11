#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,ans,la,a[500010];
bool pd=1;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
		if(i>=2)
		{
			if(i==2) la=a[i]-a[i-1];
			if(i>2)
			{
				if(a[i]-a[i-1]!=la) pd=0;
			}
		}
	}
	if(pd)
	{
		ans=1;
		for(int i=1;i<=n;++i)
		{
			if(m>la*i)
			{
				++ans;
				m-=la*i;
			}
			if(ans>=n) break;
			if(m>la*i)
			{
				++ans;
				m-=la*i;
			}
			if(ans>=n) break;
		}
		cout<<max(ans,n);
		return 0;
	}
	for(int i=1;i<=n;++i)
	{
		vector<ll> ax;
		for(int j=1;j<=n;++j)
		{
			if(a[i]>=a[j])
			{
				ax.push_back(a[i]-a[j]);
			}
		}
		sort(ax.begin(),ax.end());
		ll x=m,sum=0;
		for(ll j : ax)
		{
			if(x>=j)
			{
				x-=j;
				sum++;
			}
		}
		ans=max(ans,sum);
	}
	cout<<ans;
	return 0;
}
