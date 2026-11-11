#include<bits/stdc++.h>
using namespace std;
struct node
{
	int x,t;
};
long long c,n,m,d,q,w[500020],t[500020],dis[500020];
bool f[500020];
vector<node>a[520],g[500020];
long long di(long long s,long long e)
{
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
	dis[s]=0;
	q.push({dis[s],s});
	while(!q.empty())
	{
		int u=q.top().second;
		f[u]=1;
		q.pop();
		for(auto i:g[u])
		{
			int v=i.x,t=i.t;
			if(dis[v]>dis[u]+t and !f[v])
			{
				dis[v]=dis[u]+t;
				q.push({dis[v],v});
			}
		}
	}
	return dis[e];
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		int k,x,t;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			cin>>x>>t;
			a[i].push_back({x,t});
			for(int l=0;l<j-1;l++)
			{
				g[a[i][l].x].push_back({a[i][j-1].x,a[i][j-1].t+a[i][l].t});
				g[a[i][j-1].x].push_back({a[i][l].x,a[i][j-1].t+a[i][l].t});
			}
		}
	}
	while(q--)
	{
		for(int i=1;i<=500019;i++)
		{
			dis[i]=1e15;
			f[i]=0;
		}
		int s,e;
		cin>>s>>e;
		cout<<di(s,e)+w[e]+w[s]<<endl;
	}
	return 0;
}
