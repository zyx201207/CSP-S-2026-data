#include<bits/stdc++.h>
using namespace std;
struct Node
{
	long long u;
	long long w;
};
int vis[505][500005];
long long w[500005];
long long p[505][505];
long long k[505];
long long dis[500005];
bool v[500005];
bool operator<(Node a,Node b)
{
	return a.w>b.w;
}
priority_queue<Node>q;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	for(int i=1;i<=500;i++)
	{
		for(int j=1;j<=500;j++)
		p[i][j]=1e18;
		p[i][i]=0;
	}
	long long c,n,m,d,q1;
	cin>>c>>n>>m>>d>>q1;
	for(int i=1;i<=m;i++)
	cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			int x,t;
			cin>>x>>t;
			vis[i][x]=t;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int k=1;k<=m;k++)
			{
				if(vis[i][k]>=1 && vis[j][k]>=1)
				p[i][j]=min(p[i][j],(long long)(vis[i][k]+vis[j][k])),p[j][i]=p[i][j];
			}
		}
	}
	while(q1--)
	{
		memset(v,0,sizeof(v));
		int st,ed;
		cin>>st>>ed;
		for(int i=1;i<=n;i++)
		{
			if(vis[i][st])
			p[0][st]=vis[i][st],p[st][0]=vis[i][st];
		}
		for(int i=1;i<=n;i++)
		{
			if(vis[i][ed])
			p[i][n+1]=vis[i][ed],p[n+1][i]=vis[i][ed];
		}
		q.push({0,0});
		while(!q.empty())
		{
			Node u=q.top();
			q.pop();
			if(v[u.u])
			continue;
			dis[u.u]=u.w;
			v[u.u]=1;
			for(int i=1;i<=n+1;i++)
			{
				if(v[i] || p[i][u.u]==1e18)
				continue;
				q.push({i,u.w+p[i][u.u]});
			}
		}
		cout<<dis[n+1]+w[st]+w[ed]<<"\n";
		for(int i=1;i<=n;i++)
		p[0][i]=1e18,p[i][0]=1e18,p[n+1][i]=1e18,p[i][n+1]=1e18;
	}
}
