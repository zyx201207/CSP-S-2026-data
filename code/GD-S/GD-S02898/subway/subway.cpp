#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,dis[520],w[500020],a[520][22],t[520][22],s[520];
vector<pair<int,int>>g[520];
void dijkstra(int s)
{
	memset(dis,0x3f,sizeof dis);
	dis[s]=0;
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
	pq.push({0,s});
	while(!pq.empty())
	{
		auto A=pq.top();
		pq.pop();
		int d=A.first;
		int u=A.second;
		for(auto B:g[u])
		{
			int v=B.first;
			int w=B.second;
			if(dis[u]+w<dis[v]) dis[v]=dis[u]+w,pq.push({dis[v],v});
		}
	}
	return ;
}
void sol(int u,int v)
{
	int sum=0;
	sum+=w[u]+w[v];
	dijkstra(u);
//	cout<<dis[v]<<" ";
	sum+=dis[v];
	printf("%d\n",sum);
	return ;
}
void add(int u,int v,int w)
{
	g[u].push_back({v,w});
	g[v].push_back({u,w});
	return ;
}
int main()
{
//	freopen("subway.in","r",stdin);
//	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++) scanf("%d",&w[i]);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&s[i]);
		for(int j=1;j<=s[i];j++) 
		{
			scanf("%d%d",&a[i][j],&t[i][j]);
			if(j>1) add(a[i][j-1],a[i][j],0);
			add(a[i][j],0,t[i][j]);
		}
	}
	while(q--)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		sol(u,v);
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

*/
