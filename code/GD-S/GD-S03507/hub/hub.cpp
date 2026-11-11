#include <bits/stdc++.h>
using namespace std;
int c, t, n, k;
int dep[1000005], maxnum, cntltk;
int mindis = 0x3f3f3f3f, num[1000005];
vector<int> g[1000005];
void dfszj(int u, int fa)
{
	dep[u] = dep[fa] + 1;
	if(dep[maxnum] < dep[u])
		maxnum = u;
	for(int v : g[u])
	{
		if(v == fa) continue;
		dfszj(v,u);
	}
 } 
 void dfs(int u, int fa)
 {
 	if(num[u] && !num[fa]) cntltk++;
 	for(int v : g[u])
 	{
 		if(v == fa) continue;
 		dfs(v,u);
	 }
 }
void ck(int u, int fa)
 {
 	dep[u] = dep[fa] + 1;
 	if(num[u]) mindis = min(mindis,dep[u]-1);
 	for(int v : g[u])
 	{
 		if(v== fa) continue;
 		ck(v,u);
	 }
 }
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		for(int i = 1; i <= n; i++) g[i].clear();
		for(int i = 1; i < n; i++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			g[x].push_back(y);
			g[y].push_back(x);
		}
		if(n > 20 && k == 2)
		{
			maxnum = 0;
			for(int i = 1; i <= n; i++) dep[i] = 0;
			dfszj(1,0);
			for(int i = 1; i <= n; i++) dep[i] = 0;
			dfszj(maxnum,0);
			cout << (dep[maxnum]+3)/4 << "\n";
			continue;
		}
		int ans = 0x3f3f3f3f;
		for(int i = 0; i < (1<<n); i++)
		{
			if(__builtin_popcount(i) != k) continue;
			for(int j = 0; j < n; j++)
			{
				num[j+1] = 0;
				if(i & (1<<j)) num[j+1] = 1;
			}
			cntltk = 0;
			int maxn = 0;
			dfs(1,0);
			if(cntltk > 2) continue;
			for(int j = 1; j <= n; j++)
			{
				for(int K = 1; K <= n; K++) dep[K] = 0;
				mindis = 0x3f3f3f3f;
				if(!num[j])
				{
					ck(j,0);
					maxn = max(maxn,mindis);
				}
			}
			ans = min(ans,maxn);
		}
		cout << ans << "\n";
	}
	return 0;
}
