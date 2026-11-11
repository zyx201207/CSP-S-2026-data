#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005];
vector<pair<int,int>>g[25];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		vector<int>a(k+1,0),t(k+1,0);
		for(int i=1;i<=k;i++)
			cin>>a[i]>>t[i];
		for(int i=1;i<k;i++)
			for(int j=i+1;j<=k;j++)
				g[a[i]].push_back({a[j],t[i]});
	}
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		priority_queue<pair<int,int>>q;
		int dist[25];
		memset(dist,0x3f3f3f3f,sizeof(dist));
		dist[x]=0;
		q.push({0,x});
		while(q.size())
		{
			int dd=-q.top().first,u=q.top().second;
			q.pop();
			if(dd!=dist[u])continue;
			for(pair<int,int>pr:g[u])
			{
				int v=pr.second,w=-pr.first;
				if(dist[v]>dist[u]+w)
				{
					dist[v]=dist[u]+w;
					q.push({-dist[v],v});
				}
			}
		}
		cout<<dist[y]<<"\n";
	}
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2*/
