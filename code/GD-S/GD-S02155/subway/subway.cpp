#include<bits/stdc++.h>

using namespace std;
const int M = 5e5+5, N = 5e2+5;
int tmp, n, m, q;
vector<int> path[M];
vector<long long> dist1(N);
vector<vector<long long>> dist2(M, vector<long long>(N, 1e18));
int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> tmp >> n >> m >> tmp >> q;
	for(int i = 1; i <= m; i++)
	{
		cin >> dist1[i];
	}
	for(int i = 1; i <= n; i++)
	{
		int k, u;
		cin >> k;
		for(int j = 1; j <= k; j++)
		{
			cin >> u >> dist2[u][i];
			dist2[u][i];
			path[u].push_back(i);
		}
	}
	for(int k = 1; k <= m; k++)
	{
		for(int i = 1; i <= m; i++)
		{
			for(int j = 1; j <= n; j++)
			{
				for(int l : path[k])
				{
					dist2[i][j] = min(dist2[i][j], dist2[i][l]+dist2[k][l]+dist2[k][j]);
				}
			}
		}
	}
	while(q--)
	{
		int u, v;
		long long ans = 1e18;
		cin >> u >> v;
		for(int i = 1; i <= n; i++)
		{
			ans = min(ans, dist1[u]+dist2[u][i]+dist2[v][i]+dist1[v]);
		}
		cout << ans << endl;
	}
	
	return 0;
}
