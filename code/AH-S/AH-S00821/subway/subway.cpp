#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 5e5 + 5;
int c, n, m, d, q, t[505][N], w[N], ans, vis[505], gg;
vector <int> tot[505], tot2[N];
int s, tt;
void dfs(int now, int sum)
{
	//cout << now << " " << sum << endl;
	if (now == tt)
	{
		ans = min(ans, sum);
		return ;
	}
	if(sum > ans) return ; 
	for (int i = 0; i < tot2[now].size(); i++)
	{
		int k = tot2[now][i], fl = 0;//k:way
		if (vis[k]) continue;
		for (int j = 0; j < tot[k].size(); j++)
		{
			int g = tot[k][j];
			if (g != now)
			{
				fl = 1;
				vis[k] = 1;
				dfs(g, sum + t[k][now] + t[k][g]);
				vis[k] = 0;
			}
		}
		if (!fl) return ;
	}
}
void dfs2(int now, int sum)
{
	if(sum > ans) return ; 
	if (now == tt)
	{
		ans = min(ans, sum);
		return ;
	}
	for (int i = 0; i < tot2[now].size(); i++)
	{
		int k = tot2[now][i], fl = 0;//k:way
		if (vis[k]) continue;
		for (int j = 0; j < tot[k].size(); j++)
		{
			int g = tot[k][j];
			if (g != now)
			{
				fl = 1;
				vis[k] = 1;
				dfs(g, sum + 2 * gg);
				vis[k] = 0;
			}
		}
		if (!fl) return ;
	}	
}
int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> q >> d;
	for (int i = 1; i <= m; i++)
	{
		cin >> w[i];
	}
	int flag = 1;
	for (int i = 1; i <= n; i++)//i:wayi
	{
		int k, h, y;
		cin >> k;
		for (int j = 1; j <= k; j++)
		{
			cin >> h >> y;
			if (i == 1 && j == 1) gg = y;
			else
			{
				if (gg != y) flag = 0;
			}
			t[i][h] = y;
			tot[i].push_back(h);
			tot2[h].push_back(i);
		}
	}

	for (int i = 1; i <= d; i++)
	{
		memset(vis, 0, sizeof(vis));
		ans = INT_MAX;
		cin >> s >> tt;
		if (flag) dfs2(s, 0);
		else dfs(s, 0);
		cout << ans + w[s] + w[tt] << endl;
	}
	return 0;
}
