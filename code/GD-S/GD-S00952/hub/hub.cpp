#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int c,t,n,k;
vector <int> g[N];
int p[N];
int f[N][25],dep[N];
bool vis[N];

int find(int x)
{
	if(p[x] == x) return x;
	return p[x] = find(p[x]);
}

void merge(int x,int y)
{
	x = find(x),y = find(y);
	if(x == y) return ;
	p[x] = y;
}

void dfs(int u,int fa)
{
	f[u][0] = fa;
	dep[u] = dep[fa] + 1;
	for(int i = 1;i <= 20;i++)
		f[u][i] = f[f[u][i - 1]][i - 1];
	for(int v : g[u])
		if(v != fa)
		{
			dfs(v,u);
		}
}

int lca(int x,int y)
{
	if(dep[x] > dep[y]) swap(x,y);
	for(int i = 20;i >= 0;i--)
		if(dep[f[y][i]] >= dep[x])
		{
			y = f[y][i];
		}
	if(x == y) return x;
	for(int i = 20;i >= 0;i--)
		if(f[x][i] != f[y][i])
		{
			x = f[x][i];
			y = f[y][i];
		}
	return f[x][0];
} 

int calc(int x,int y)
{
	return dep[x] + dep[y] - 2 * dep[lca(x,y)];
}

int u[N],v[N];

int check()
{
	vector <int> vec;
	for(int i = 1;i <= n;i++) p[i] = i;
	for(int j = 1;j <= n;j++) 
		if(vis[j]) vec.push_back(j);
	for(int x : vec)
		for(int y : vec)
		{
			if(x == y) continue;
			for(int i = 1;i < n;i++)
				if((u[i] == x && v[i] == y) || (v[i] == x && u[i] == y))
				{
					merge(x,y);
					break;
				}
		}
	int cnt = 0;
	for(int x : vec)
		if(find(x) == x) cnt++;
	return cnt;
}

void solve()
{
	scanf("%d%d",&n,&k);
	for(int i = 1;i <= n;i++)
	{
		vector <int> tmp = {};
		swap(g[i],tmp);
	}
	for(int i = 1;i < n;i++)
	{
		scanf("%d%d",&u[i],&v[i]);
		g[u[i]].push_back(v[i]);
		g[v[i]].push_back(u[i]);
	}
	if(c == 13 || c == 14)
	{
		int m = (n - 1) / 2;
		cout << (m - k + 6) / 4 << '\n';
		return ;
	}
	dfs(1,0);
	if(c <= 3)
	{
		int ans = 2e9;
		for(int i = 0;i < (1 << n);i++)
		{
			vector <int> vec;
			int cnt = 0;
			for(int j = 0;j < n;j++) 
				if((i >> j) & 1) vis[j + 1] = 1,cnt++,vec.push_back(j + 1);
				else vis[j + 1] = 0;
			int tot = check();
			if(cnt == k && check() <= 2)
			{
				int maxn = 0;
				for(int i = 1;i <= n;i++)
				{
					if(vis[i]) continue;
					int minn = 2e9;
					for(int x : vec)
						minn = min(minn,calc(x,i));
					maxn = max(maxn,minn);
				}
				ans = min(ans,maxn);
			}
		}
		printf("%d\n",ans);
	}
}

int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin >> c >> t;
	while(t--)
	{
		solve();
	}
}
