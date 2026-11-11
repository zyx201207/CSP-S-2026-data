#include<bits/stdc++.h>
using namespace std;
long long w[500005],t[500005][505];
long long d[500005],vis[500005];
vector<pair<long long,long long> > tu[500005];
long long dij(long long s,long long tt)
{
	priority_queue<pair<long long,long long> > q;
	memset(d,0x3f,sizeof(d));
	memset(vis,0,sizeof(vis));
	q.push({0,s});
	d[s]=0;
	while(q.size())
	{
		auto u=q.top();
		vis[u.second]=1;
		q.pop();
		for(auto v:tu[u.second])
		{
			if(vis[v.first]) continue;
			if(v.second+d[u.second]<d[v.first])
			{
				d[v.first]=v.second+d[u.second];
				q.push({-d[v.first],v.first});
			}
		}
	}
	return d[tt];
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	long long c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		long long k;
		cin>>k;
		long long a[500005];
		for(int j=1;j<=k;j++)
		{
			cin>>a[j];
			cin>>t[a[j]][i];
			for(int jj=1;jj<j;jj++)
			{
				tu[a[j]].push_back({a[jj],t[a[j]][i]+t[a[jj]][i]});
				tu[a[jj]].push_back({a[j],t[a[j]][i]+t[a[jj]][i]});
			}
		}
	}
	for(int i=1;i<=q;i++)
	{
		long long x,y;
		cin>>x>>y;
		cout<<w[x]+w[y]+dij(x,y)<<'\n';
	}
	return 0;
}
