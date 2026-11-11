#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pa pair<ll,int> 
#define di first
#define ind second
const int M=5e5;
int c,n,m,d,qe;
ll w[M];
vector<pa> g[M];
int u[M];
ll v[M];
priority_queue <pa,vector<pa>,greater<pa> > q;
ll dist[M];
bool vis[M];
const int inf=1e18;
void add(int id)
{
	for(int i = 0;i<g[id].size();i++)
	{
		if(!vis[g[id][i].ind])
		{
			//cout << dist[id]+g[id][i].di << " " << g[id][i].ind << "\n";
			q.push({dist[id]+g[id][i].di,g[id][i].ind});
		}
	}
	return ;
}
ll dij(int st,int ed)
{
	while(!q.empty())
	{
		q.pop();
	}
	for(int i = 1;i<=m;i++)
	{
		dist[i]=inf;
		vis[i]=0;
	}
	dist[st]=0;
	q.push({0,st});
	while(!vis[ed] && !q.empty())
	{
		pa tmp=q.top();
		//cout << tmp.di << " " << tmp.ind << "\n";
		q.pop();
		if(!vis[tmp.ind])
		{
			dist[tmp.ind]=tmp.di;
			vis[tmp.ind]=1;
			add(tmp.ind);
			
		}
	}
	
	return dist[ed];
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin >> c >> n >> m >> d >> qe;
	for(int i = 1;i<=m;i++)
	{
		cin >> w[i];
	}
	for(int i = 1;i<=n;i++)
	{
		int k;
		cin >> k;
		for(int j = 1;j<=k;j++)
		{
			cin >> u[j] >> v[j];
			for(int l = 1;l<j;l++)
			{
				g[u[l]].push_back({v[j]+v[l],u[j]});
				g[u[j]].push_back({v[j]+v[l],u[l]});
			}
		}
	}
	/*
	for(int i = 1;i<=m;i++)
	{
		cout << "id=" << i <<"\n";
		for(int j  = 0;j<g[i].size();j++)
		{
			cout << "to=" << g[i][j].ind << " w=" << g[i][j].di << "\n";
		}
		cout << "=======\n";
	}
	*/
	while(qe--)
	{
		int x,y;
		cin >> x >> y;
		cout << dij(x,y)+w[x]+w[y] << "\n";
	}
	return 0;
}
