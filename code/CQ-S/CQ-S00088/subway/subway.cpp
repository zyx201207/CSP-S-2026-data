#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
long long dis[501][501],w[500001],diss[500505];
vector<pair<int,long long>> to[500505];
map<pair<int,int>,long long> mp;
bool vis[500505];
long long solve(int x,int y)
{
	for(int i=1;i<=m+n;i++)
		diss[i]=1e10,vis[i]=0;
	diss[x]=0;
	priority_queue<pair<long long,pair<int,int> >,vector<pair<long long,pair<int,int> > >,greater<pair<long long,pair<int,int> > > > pq;
	pq.push({0,{x,-1}});
	while(!pq.empty())
	{
		auto u=pq.top();
		pq.pop();
		if(vis[u.second.first])
			continue;
		vis[u.second.first]=1;
		if(u.second.first==y)
			return u.first+mp[{u.second.first,u.second.second-m}];
		for(int i=0;i<(int)to[u.second.first].size();i++)
		{
			int v=to[u.second.first][i].first;
			long long val=to[u.second.first][i].second;
			if(u.second.second==-1)
				val+=mp[{u.second.first,v-m}];
			if(v>m&&u.second.first<=m)
			{
				if(diss[v]==1e10)
				{
					diss[v]=diss[u.second.first]+val;
					pq.push({diss[v],{v,u.second.first}});
				}
			}
			else if(diss[v]>diss[u.second.first]+val)
			{
				diss[v]=diss[u.second.first]+val;
				pq.push({diss[v],{v,u.second.first}});				
			}
		}
	}
	return 0;
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			dis[i][j]=1e10;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			int a,val;
			cin>>a>>val;
			to[m+i].push_back({a,0});
			to[a].push_back({m+i,0});
			mp[{a,i}]=val;
		}
	}
	for(int i=1;i<=m;i++)
	{
		if(to[i].size()<=1)
			continue;
		for(int j=0;j<(int)to[i].size();j++)
			for(int k=j+1;k<(int)to[i].size();k++)
				dis[to[i][j].first-m][to[i][k].first-m]=min(dis[to[i][j].first-m][to[i][k].first-m],mp[{i,to[i][j].first-m}]+mp[{i,to[i][k].first-m}]);
	}
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			if(dis[i][j]!=1e10)
			{
				to[m+i].push_back({m+j,dis[i][j]});
				to[m+j].push_back({m+i,dis[i][j]});
			}
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		cout<<w[x]+w[y]+solve(x,y)<<'\n';
	}
	return 0;	
}
/*
0≤c≤25，1≤n≤500，1≤m≤∑ki ≤5*10^5，1≤d≤20，1≤q ≤10^5

应该可以把图建出来

能写一个 O(q*最短路)

好像常数略微有点大？ 
*/
