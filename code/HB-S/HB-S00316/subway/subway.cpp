#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int c, n, m, d, q;
int w[N], b[N];
vector <long long> ve[N], t[N], vb[N];
int e;
long long minn = 5e12;
void dfs(int u, long long sum, int ix)
{
	if(u == e)
	{
		minn = min(minn, sum);
		return;
	}
	for(int i = 0; i < (int) ve[u].size(); i ++)
	{
		if(!b[ve[u][i]])
		{
			b[ve[u][i]] = 1;
			if(vb[u].empty() || t[u].empty())
			{
				dfs(ve[u][i], sum, i);
				continue;
			}
			if(vb[u][i] != vb[u][ix])
			{
				dfs(ve[u][i], sum + t[u][i] + t[u][ix], i);
			}
			else
			{
				dfs(ve[u][i], sum, i);
			}
			b[ve[u][i]] = 0;
		}
	}
}
int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i ++)
	{
		cin >> w[i];
	}
	for(int i = 1; i <= n; i ++)
	{
		for(int j = 1; j <= m; j ++)
		{
			t[j].push_back(0);
		}
	}
	for(int i = 1; i <= m; i ++)
	{
		for(int j = 1; j <= m + 3 * n; j ++)
		{
			vb[j].push_back(0);
		}
	}
	for(int i = 1; i <= n; i ++)
	{
		int k;
		cin >> k;
		int ba = 0;
		for(int j = 1; j <= k; j ++)
		{
			int aij, ti;
			cin >> aij >> ti;
			if(j != 1)
			{
				ve[ba].push_back(aij);
				ve[aij].push_back(ba);
			}
			ba = aij;
			t[aij][i] = ti;
			vb[aij][j] = i;
		}
	}
	while(q --)
	{
		int x, y;
		cin >> x >> y;
		e = y;
		minn = 5e12;
		dfs(x, 0, 0);
		cout << (minn + w[x] + w[y]) * 2 << "\n";
 	}
	return 0;
}
