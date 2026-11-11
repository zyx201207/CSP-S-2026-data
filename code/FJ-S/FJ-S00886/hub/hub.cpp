#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
using namespace std;

const int SIZE = 1e6 + 10;
int c, t, n = 0, k = 0;
int A, B, far, len, res;
int dis[SIZE] = {0};
int fa[SIZE] = {0};
int down[SIZE] = {0};
bool hub[SIZE] = {0};
vector<int> edge[SIZE];

void dfs(int u, int father)
{
	if(dis[u] > dis[far])
	{
		far = u;
	}
	fa[u] = father;
	
	int v;
	for(int i = 0; i < edge[u].size(); i++)
	{
		v = edge[u][i];
		if(v == father || hub[v])
		{
			continue;
		}
		dis[v] = dis[u] + 1;
		dfs(v, u);
	}
}

void solve1()
{
	int i = A, j = B, t = len;
	int ta, tb;
	while(t > 0)
	{
		hub[i] = true;
		i = down[i];
		t--;
		if(t <= 0)
		{
			break;
		}
		hub[j] = true;
		j = fa[j];
		t--;
	}
	ta = fa[i], tb = down[j];
	
	while(dis[i] <= dis[j])
	{
		if(hub[j])
		{
			j = fa[j];
			continue;
		}
		res = max(res, max(dis[j] - dis[ta], dis[tb] - dis[j]));
	}
	
	for(int f = B; f > 0; f = fa[f])
	{
		if(!hub[f])
		{
			continue;
		}
		dfs(f, 0);
		res = max(res, dis[far]);
	}
}

void solve2()
{
	res = 1;
}

int main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	
	scanf("%d%d", &c, &t);
	
	while((t--) > 0)
	{
		for(int i = 1; i <= n; i++)
		{
			edge[i].clear();
		}
		scanf("%d%d", &n, &k);
		for(int i = 1, u, v; i < n; i++)
		{
			scanf("%d%d", &u, &v);
			edge[u].push_back(v);
			edge[v].push_back(u);
		}
		
		memset(hub, 0, sizeof(hub));
		res = 0;
		far = 1;
		dfs(1, 0);
		A = far;
		dis[A] = 0;
		dfs(A, 0);
		B = far;
	
		len = 0;
		for(int i = B; i > 0; i = fa[i])
		{
			down[fa[i]] = i;
			len++;
		}
	
		if(len >= k)
		{
			solve1();
		}
		else
		{
			solve2();
		}
		printf("%d\n", res);
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
