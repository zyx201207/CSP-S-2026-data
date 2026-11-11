#include<bits/stdc++.h>
using namespace std;
long long cc,n,m,d,q;
int edge[5002][5002];
int a[100002],t[100002];
const int N=0x3f3f3f3f;
int dist[100002];
bool b[100002];
void dijkstra(int s,int t)
{
	memset(dist,127,sizeof(dist));
	dist[1]=0;
	priority_queue<pair<int,int>> q;
	q.push({0,1});
	b[1]=true;
	while(!q.empty())
	{
		int d=-q.top().first;
		int x=q.top().second;
		q.pop();
		if(d>dist[x]) continue;
		for(int y=1;y<=n;y++)
		{
			if(edge[x][y] && dist[x]+edge[x][y]<dist[y])
			{
				dist[y]=dist[x]+edge[x][y];
				if(!b[y])
				{
					q.push({-dist[y],y});
				}
			}
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>cc>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=m;j++)
		{
			edge[i][j]=N;
		}
	}
	for(int i=1;i<=m;i++)
	{
		edge[i][i]=m;
	}
	for(int i=1;i<=m;i++)
	{
		int x;
		cin>>x;
		edge[i][i+m]=min(edge[i][i+m],x);
		edge[i+m][i]=min(edge[i+m][i],x);
	}
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		for(int j=1;j<=x;j++)
		{
			cin>>a[i]>>t[i];
			edge[a[i]+m][a[i]+(2*m)]=min(edge[a[i]+m][a[i]+(2*m)],t[i]);
		}
		for(int j=1;j<=x;j++)
		{
			for(int k=1;k<=x;k++)
			{
				edge[j+(2*m)][k+(2*m)]=0;
				edge[k+(2*m)][j+(2*m)]=0;
			}
		}
	}
	for(int i=1;i<=q;i++)
	{
		int x,y;
		cin>>x>>y;
		dijkstra(x,y);
		cout<<dist[y];
	}
}
