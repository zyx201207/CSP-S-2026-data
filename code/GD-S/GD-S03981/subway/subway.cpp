#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
struct node{
	int v,w,id;
};
vector<node> e[N];
int w[N],d[N],vis[N];
int c,n,m,di,q;
void dij(int s,int r)
{
	priority_queue<pair<int,int> > q;
	for(int i=0;i<=n;i++)
	{
		vis[i]=0;
		d[i]=INT_MAX;
	} 
	d[s]=0;
	q.push({0,s});
	while(q.size())
	{
		auto t=q.top();
		q.pop();
		int u=t.second;
		if(vis[u]) continue;
		vis[u]=1;
		for(auto ed:e[u])
		{
			int v=ed.v;
			int w=ed.w;
			int id=ed.id;
			if(id==r)
			{
				if(d[v]>d[u]+w)
				{
					d[v]=d[u]+w;
					q.push({-d[v],v}); 
				}
			}
			else
			{
				if(d[v]>d[u]+w+e[v][v].w)
				{
					d[v]=d[u]+w+e[v][v].w;
					q.push({-d[v],v});
				}
			}
		}
	}
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>di>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		int u,w;
		cin>>u>>w;
		e[u].push_back({u,w,i});
		for(int j=2;j<=k;j++)
		{
			int v,l;
			cin>>v>>l;
			e[u].push_back({v,l,i});
			u=v;
		}
	}
	for(int i=1;i<=q;i++)
	{
		int s,f;
		cin>>s>>f;
		dij(s,1);
		cout<<d[f]+w[s]+w[f];
	}
	return 0;	
} 
