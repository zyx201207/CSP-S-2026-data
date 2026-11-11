#include <bits/stdc++.h>
using namespace std;
long long c, n, m, p, q, x, y, k, ans, mp[505][505][505];
long long v[5005], t[505][5005];
int DFS(int x, int y)
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	for (int i = 1; i <= n; i++)
	{
		if (mp[i][x][y] == 1)
		{
			ans = ans + t[i][x];
			ans += t[1][i];
			ans += t[i][i];
			ans += v[y];
			return ans;	
		} 
	}
	ans += t[1][y];
	DFS(x + 1, y); 
	return ans;
}
int main()
{
	cin >> c >> n >> m >> p >> q;
	for (int i = 1; i <= m; i++)
	{
		cin >> v[i];
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> k;
		for (int j = 1; j <= k; j++)
		{
			int a, b;
			b = a;
			cin >> a;
			cin >> t[i][a];
			if (j >= 2)
			{
				mp[i][b][a] = 1;
			}
		}
	}
	for (int i = 1; i <= q; i++)
	{
		cin >> x >> y;
		ans += v[x];
		DFS(x, y);
		cout << ans << endl;
	}
	return 0;
} 
