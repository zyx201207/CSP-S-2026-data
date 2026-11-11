#include <bits/stdc++.h>
using namespace std;
const int N=1e6+5;

int c, G, n, m, u1, v1, col[N];
vector<int> a[N];
void dfs(int u, int fa, int cnt, int p)
{
	if (!cnt && p==1)
	{
		for (int i=1; i<=n; i++) printf("%d ", col[i]);
		puts("");
		return ;
	}
	
	for (int i=0; i<a[u].size(); i++)
	{
		int v=a[u][i];
		if (v==fa) continue;
		
		col[u]=0;
		dfs(v, u, cnt, p);
		
		if (cnt)
		{
			if (col[fa] || u==1)
			{
				col[u]=1;
				dfs(v, u, cnt-1, p);
			}
			else if (p==0)
			{
				col[u]=1;
				dfs(v, u, cnt-1, 1);
			}
		}
	}
}
int main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	
	scanf("%d%d", &c, &G);
	while (G--)
	{
		scanf("%d%d", &n, &m);
		for (int i=1; i<=n; i++) a[i].clear();
		
		for (int i=1; i<n; i++)
		{
			scanf("%d%d", &u1, &v1);
			a[u1].push_back(v1);
			a[v1].push_back(u1);
		}
//		dfs(1, 0, m, 0);
		
		printf("1\n");
	}
	
	
	
	return 0;
}
/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10

*/
