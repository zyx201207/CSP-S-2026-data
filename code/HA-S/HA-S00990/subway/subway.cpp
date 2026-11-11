#include <bits/stdc++.h>
using namespace std;
long long c,m,n,d,q;
long long w[500005],k[500005],dis[500003];
bool vis[500003];
vector < pair<int,int> > a[503];
void spfa(long long k)
{
	dis[k]=0;
	queue <long long> q;
	q.push(k);
	vis[k]=true;
	while(!q.empty())
	{
		long long f=q.front();
		vis[f]=false;
		q.pop();
		for(long long i=0;i<a[f].size();i++)
		{
			long long t=a[f][i].first;
			long long s=a[f][i].second;
			if(dis[t]>dis[f]+s)
			{
				dis[t]=dis[f]+s+w[f];
				if(!vis[t])
				{
					vis[t]=true;
					q.push(t);
				}
			}
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(long long i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(long long i=1;i<=n;i++)
	{
		cin>>k[i];
		for(long long j=1;j<=k[i];j++)
		{
			long long f,g;
			cin>>f>>g;
			a[i].push_back(make_pair(f,g));
		}
	}
	for(long long i=0;i<q;i++)
	{
		memset(dis,sizeof(dis),1000000);
		long long x,y;
		cin>>x>>y;
		if(d==1)
		{
			cout<<w[x]+a[x][y].second<<'\n';
			return 0;
		}
		spfa(x);
		cout<<dis[y]+w[y]<<'\n';
	}
	return 0;
}
