#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],k,mx=-1;
vector<pair<long long,long long> > v[500005];
map<long long,long long> mp;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	long long x;
	for(long long i=1;i<=n;++i)
	{
		cin>>x;
		mp[x]++;
	}
	for(auto i:mp)
	{
		a[++k]=i.first;
		v[k].push_back({i.second,0});
	}
	for(int i=1;i<=k;i++)
	{
		long long mm=m;
		for(auto j:v[i])
		{
			v[i+1].push_back({min(mm/(a[i+1]-a[i]+j.second),j.first),a[i+1]-a[i]+j.second});
			mp[a[i+1]]+=min(mm/(a[i+1]-a[i]+j.second),j.first);
			mm-=min(mm/(a[i+1]-a[i]+j.second),j.first)*(a[i+1]-a[i]+j.second);
		}
		mx=max(mx,mp[a[i+1]]);
	}
	cout<<mx;
	return 0;
}
