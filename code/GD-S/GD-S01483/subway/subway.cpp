#include <bits/stdc++.h>
using namespace std;

const int N = 500010,M = 510;
struct node 
{
	long long id,t;
};
struct eg
{
	int u;long long st;
	bool operator < (const eg&cmp) const
	{
		return st>cmp.st;
	}
};
vector<node> v[N];
int c,n,m,g,q;
long long d[M][M],p[M][M],w[N];
bool vis[M][M];
int l[N];
priority_queue<eg> qu;
void dij(int u)
{
	qu.push({u,0});p[u][u]=0;vis[u][u]=1;
	while(!qu.empty())
	{
		eg f=qu.top();
		qu.pop();
		for(int i=1;i<=n;i++)
		{
			if(p[u][i]>p[u][f.u]+d[f.u][i])
			{
				p[u][i]=p[u][f.u]+d[f.u][i];
				if(!vis[u][i]) 
				{
					qu.push({i,p[u][i]});
					vis[u][i]=1;
				}
			}
		}
	}
}
long long mi=(long long)1e18;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&g,&q);
	for(int i=1;i<=m;i++) scanf("%lld",&w[i]);
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) d[i][j]=p[i][j]=(long long)1e18;
	for(int i=1;i<=n;i++)
	{
		int k;
		scanf("%d",&k);
		for(int j=1;j<=k;j++)
		{
			long long a,t;
			scanf("%lld%lld",&a,&t);
			v[a].push_back({i,t});l[a]++;
		}
	}
	for(int i=1;i<=m;i++) 
	{
		for(int x=0;x<l[i];x++)
		{
			for(int y=x+1;y<l[i];y++)
			{
				int a=v[i][x].id,b=v[i][y].id;
				d[a][b]=d[b][a]=min(d[a][b],v[i][x].t+v[i][y].t);
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		dij(i);
	}
	while(q--)
	{
		int xx,yy;
		scanf("%d%d",&xx,&yy);
		long long mi=(long long)1e18;
		for(int i=0;i<l[xx];i++)
		{
			for(int j=0;j<l[yy];j++) mi=min(mi,p[v[xx][i].id][v[yy][j].id]+v[xx][i].t+v[yy][j].t);
		}
		printf("%lld\n",mi+w[xx]+w[yy]);
		
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
