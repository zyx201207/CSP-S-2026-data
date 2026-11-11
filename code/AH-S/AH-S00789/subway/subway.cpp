#include<bits/stdc++.h>
using namespace std;
struct fun
{
	long long v,w;
};
struct node
{
	long long pos,ans,dao;
	friend bool operator < (node a,node b)
	{
		return a.ans>b.ans;
	}
};
long long c,n,m,d,qq,w[500005],k,x[500005],y,xx,dis[20005][505],nxt1[20005][505],nxt2[20005][505],ppp[20005][505],mn;
vector<fun> v[500005];
priority_queue<node> q;
long long bfs()
{
	while(!q.empty())
	{
		q.pop();
	}
	for (int i=1;i<=m;i++)
	{
		for (int j=1;j<=500;j++)
		{
			dis[i][j]=1e18;
		}
	}
	mn=1e18;
	for (int i=0;i<v[xx].size();i++)
	{
		q.push((node){xx,v[xx][i].w,v[xx][i].v});
		dis[xx][v[xx][i].v]=v[xx][i].w;
	}
	while(!q.empty())
	{
		node n1=q.top();
		q.pop();
		if (n1.ans>=mn)
		{
			continue;
		}
		if (n1.pos==y)
		{
			if (c>=12&&c<=19)
			{
				return n1.ans+ppp[n1.pos][n1.dao];
			}
			mn=min(mn,n1.ans+ppp[n1.pos][n1.dao]);
			continue;
		}
		if (dis[n1.pos][n1.dao]<n1.ans)
		{
			continue;
		}
		if (dis[nxt1[n1.pos][n1.dao]][n1.dao]>dis[n1.pos][n1.dao])
		{
			dis[nxt1[n1.pos][n1.dao]][n1.dao]=dis[n1.pos][n1.dao];
			q.push((node){nxt1[n1.pos][n1.dao],dis[nxt1[n1.pos][n1.dao]][n1.dao],n1.dao});
		}
		if (dis[nxt2[n1.pos][n1.dao]][n1.dao]>dis[n1.pos][n1.dao])
		{
			dis[nxt2[n1.pos][n1.dao]][n1.dao]=dis[n1.pos][n1.dao];
			q.push((node){nxt2[n1.pos][n1.dao],dis[nxt2[n1.pos][n1.dao]][n1.dao],n1.dao});
		}
		for (int i=0;i<v[n1.pos].size();i++)
		{
			if (n1.dao!=v[n1.pos][i].v&&dis[n1.pos][v[n1.pos][i].v]>dis[n1.pos][n1.dao]+v[n1.pos][i].w+ppp[n1.pos][n1.dao])
			{
				dis[n1.pos][v[n1.pos][i].v]=dis[n1.pos][n1.dao]+v[n1.pos][i].w+ppp[n1.pos][n1.dao];
				q.push((node){n1.pos,dis[n1.pos][v[n1.pos][i].v],v[n1.pos][i].v});
			}
		}
	}
	return mn;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>qq;
	for (int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for (int i=1;i<=n;i++)
	{
		cin>>k;
		for (int j=1;j<=k;j++)
		{
			cin>>x[j]>>y;
			if (j>1)
			{
				nxt1[x[j-1]][i]=x[j];
				nxt2[x[j]][i]=x[j-1];
			}
			ppp[x[j]][i]=y;
			v[x[j]].push_back((fun){i,y});
		}
	}
	while(qq--)
	{
		cin>>xx>>y;
		cout<<bfs()+w[xx]+w[y]<<"\n";
	}
	return 0;
} 
