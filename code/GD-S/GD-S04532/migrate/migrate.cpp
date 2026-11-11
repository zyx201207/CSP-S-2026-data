#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+5, INF=1e9;

int c, G, n, dis[N], vis[N];
ll x[N], g[N], d, ans=0;
vector<int> a[N];
queue<int> q;
void clr()
{
	ans=0;
	for (int i=1; i<=n; i++) a[i].clear();
}
void dij(int s)
{
	for (int i=1; i<=n; i++) dis[i]=INF, g[i]=0, vis[i]=0;
	
	q.push(s), dis[s]=0, g[s]=1;
	while (!q.empty())
	{
		int u=q.front();
		q.pop();
		
		if (vis[u]) continue;
		vis[u]=1;
		
		for (int i=0; i<a[u].size(); i++)
		{
			int v=a[u][i];
			
			if (dis[v]>dis[u]+1) dis[v]=dis[u]+1, g[v]=g[u], q.push(v);
			else if (dis[v]==dis[u]+1) g[v]+=g[u];
		}
	}
}
int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	scanf("%d%d", &c, &G);
	while (G--)
	{
		scanf("%d%lld", &n, &d), clr();
		for (int i=1; i<=n; i++) scanf("%lld", &x[i]);
		
		for (int i=1; i<=n; i++) 
			for (int j=i; j>=1; j--) 
			{
				if (x[i]-x[j]<=d) a[j].push_back(i);
				else break;
			}
				
		for (int i=1; i<=n; i++)
		{
			dij(i);
			for (int j=i; j<=n; j++) if (g[j]==2) ans++;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
/*
0 2
4 2 
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

*/
