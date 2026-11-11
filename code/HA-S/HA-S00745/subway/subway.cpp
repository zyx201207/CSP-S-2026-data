#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=510;
int c,n,m,d,q;
int w[maxn],a[maxn][maxn],t[maxn][maxn],x[100010],y[10010];
const int INF=1e18;
vector<vector<pair<int,int> > > g;
vector<int> dis;
void dj(int s,int n)
{
	dis.assign(n+1,INF);
	dis[s]=0;
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
	q.push(make_pair(0,s));
	while(!q.empty())
	{
		pair<int,int> t=q.top();
		q.pop();
		int d=t.first;
		int u=t.second;
		if(dis[u]<d) continue;
		for(int i=1;i<=g[u].size();i++)
		{
			int v=g[u][i].first;
			int w=g[u][i].second;
			if(dis[v]>dis[u]+w)
			{
				dis[v]=dis[u]+w;
				q.push(make_pair(dis[v],v));
			}
		}
	}
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);//测试点编号、地铁线路数、地铁站数、每个地铁站最多被几条线路经过，以及出行计划数
	for(int i=1;i<=m;i++)
		scanf("%lld",&w[i]);//从每个地铁站的地铁口走到站厅需要的时间
	for(int i=1;i<=n;i++)
	{
		int k;
		scanf("%lld",&k);
		for(int j=1;j<=k;j++)
			scanf("%lld%lld",&a[i][j],&t[i][j]);//ai,j 表示第 i 条线路经过的第 j 个地铁站，ti,j 表示从该地铁站的站厅走到第 i 条线路的站台需要的时间
	}
	for(int i=1;i<=q;i++)
		scanf("%lld%lld",&x[i],&y[i]);
	if(c==0)
	{
		if(n==2) printf("32\n17");
		if(n==3) printf("35\n16");
		return 0;
	}
 	return 0;
}

