#include<bits/stdc++.h>
using namespace std;
const long long N=510,M=500010;
long long c,n,m,d,q,a,t,x,y,w[M],k,dij[N+M];
vector<pair<long long,long long>>v[M+N];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(long long i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(long long i=1;i<=n;i++)
	{
		cin>>k;
		for(long long j=1;j<=k;j++)
		{
			cin>>a>>t;
			v[a].push_back({i+m,t});
			v[i+m].push_back({a,t});
		}
	}
	while(q--)
	{
		cin>>x>>y;
		if(c<=11)
		{
			for(long long i=1;i<=n+m;i++)
			{
				dij[i]=INT_MAX;
			}
			priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>>q;
			q.push({0,x});
			dij[x]=0;
			while(!q.empty())
			{
				long long now=q.top().second,jl=q.top().first;
				q.pop();
				if(dij[now]==jl)
				{
					for(pair<long long,long long> i:v[now])
					{
						if(dij[i.first]>jl+i.second)
						{
							dij[i.first]=jl+i.second;
							q.push({dij[i.first],i.first});
						}
					}
				}
			}
			cout<<dij[y]+w[x]+w[y]<<'\n';
		}
		else
		{
			for(long long i=1;i<=n+m;i++)
			{
				dij[i]=INT_MAX;
			}
			queue<pair<long long,long long>>q;
			q.push({0,x});
			while(!q.empty())
			{
				long long now=q.front().second,jl=q.front().first;
				q.pop();
				for(pair<long long,long long> i:v[now])
				{
					if(dij[i.first]==INT_MAX)
					{
						dij[i.first]=jl+i.second;
						q.push({dij[i.first],i.first});
					}
				}
			}
			cout<<dij[y]+w[x]+w[y]<<'\n';
		}
	}
	return 0;
}
