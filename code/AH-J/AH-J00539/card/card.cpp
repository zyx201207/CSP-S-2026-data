#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	ll n,m;cin>>n>>m;
	vector<ll> sum(m+1,0);
	unordered_map <ll,ll> mp;
	mp.erase(1);
	vector<ll> a(n+1);
	for(ll i=1;i<=n;i++)cin>>a[i];
	for(ll i=n;i>=1;i--)
	{

		if(mp.find(a[i])!=mp.end())
		{
			ll f=mp[a[i]];
			for(auto &t:mp)
			{
				if(t.second<=f) mp.erase(t.first);
			}
		}
		 mp[a[i]]=i;
		for(auto &t:mp)
		{
			sum[t.first]++;
		}

	}
	for(ll i=1;i<=m;i++) cout<<sum[i]<<' ';
}