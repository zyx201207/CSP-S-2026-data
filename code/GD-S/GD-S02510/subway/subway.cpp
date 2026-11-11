#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,k,w[500001],a[501][50001],t[501][50001],dist[500001];
bool st[500001];
vector<pair<int,long long>> e[500001];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			cin>>a[i][j]>>t[i][a[i][j]];
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=k;j++)
		{
			if(i==a[i][j]||a[i][j]==0)
			{
				continue;
			}
			e[i].push_back({a[i][j],t[i][i]+t[i][a[i][j]]});
			e[a[i][j]].push_back({i,t[a[i][j]][a[i][j]]+t[a[i][j]][i]});
		}
	}
	/*for(int i=1;i<=m;i++)
	{
		for(auto &edge:e[i])
		{
			cout<<i<<" "<<edge.first<<" "<<edge.second<<endl;
		}
	}*/
	for(int i=1;i<=q;i++)
	{
		int x,y;
		cin>>x>>y;
		memset(dist,0x3f,sizeof(dist));
		memset(st,0,sizeof(st));
		dist[x]=0;
		priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;
		pq.push({0,x});
		while(!pq.empty())
		{
			auto topp=pq.top();
			pq.pop();
			int d=topp.first,t=topp.second;
			if(st[t])
			{
				continue;
			}
			for(auto &edge:e[t])
			{
				int v=edge.first,w=edge.second;
				if(dist[v]>dist[t]+w)
				{
					dist[v]=dist[t]+w;
					pq.push({dist[v],v});
				}
			}
		}
		cout<<dist[y]+w[x]+w[y]<<endl;
	}
	return 0;
} 
