#include <bits/stdc++.h>
using namespace std;
const int N = 100,D = 6;
const int inf = 0x3f3f3f3f;
int n,k;
vector<int> to[N];
void addedge(int u,int v)
{
	to[u].push_back(v);
	to[v].push_back(u);
	return;
}
int dep[N],nxt[N][D + 1];
void dfs(int u,int fa)
{
	dep[u] = dep[fa] + 1;
	nxt[u][0] = fa;
	for(int v : to[u])
	{
		if(v == fa)
			continue;
		dfs(v,u);
	}
	return;
}
void lcaInit()
{
	memset(dep,0,sizeof dep);
	memset(nxt,0,sizeof nxt);
	dfs(1,0);
	for(int i = 1; i <= D; i++)
		for(int j = 1; j <= n; j++)
			nxt[j][i] = nxt[nxt[j][i - 1]][i - 1];
	return;
}
int lcaQuery(int x,int y)
{
	if(dep[x] < dep[y])
		swap(x,y);
	for(int i = D; i >= 0; i--)
		if(dep[nxt[x][i]] >= dep[y])
			x = nxt[x][i];
	if(x == y)
		return x;
	for(int i = D; i >= 0; i--)
		if(nxt[x][i] != nxt[y][i])
			x = nxt[x][i],y = nxt[y][i];
	return nxt[x][0];
}
int dist(int x,int y)
{
	int lca = lcaQuery(x,y);
	return dep[x] + dep[y] - dep[lca] * 2;
}
ifstream fin("hub.in",ios_base::in);
ofstream fout("hub.out",ios_base::out);
int main()
{
	ios::sync_with_stdio(0); fin.tie(0); fout.tie(0);
	int c,T; fin >> c >> T;
	while(T--)
	{
		fin >> n >> k;
		for(int i = 1; i <= n; i++)
			to[i].clear();
		for(int i = 1; i <= n - 1; i++)
		{
			int u,v; fin >> u >> v;
			addedge(u,v);
		}
		lcaInit();
		int ans = inf;
		for(int status = 0; status < (1 << n); status++)
		{
			int keyCnt = 0,edgeCnt = 0;
			for(int i = 1; i <= n; i++)
				if(status & (1 << (i - 1)))
				{
					keyCnt++;
					for(int j : to[i])
						if(status & (1 << (j - 1)))
							edgeCnt++;
				}
					
			if(keyCnt != k || edgeCnt < k - 2)
				continue;
			int r = 0;
			for(int i = 1; i <= n; i++)
			{
				int disI = inf;
				for(int j = 1; j <= n; j++)
					if(status & (1 << (j - 1)))
						disI = min(disI,dist(i,j));
				r = max(r,disI);
			}
			ans = min(ans,r);
		}
		fout << ans << '\n';
	}
	
	return 0;
}
