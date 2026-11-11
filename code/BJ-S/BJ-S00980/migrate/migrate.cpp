#include <bits/stdc++.h>
using namespace std;

const int N = 2e6 + 5;

long long n, d, pos[N];
vector<int> G[N], rd;

long long dp[N], dis[N];
void topu()
{
	memset(dp, 0, sizeof(dp));
	memset(dis, 0x3f, sizeof(dis));
	queue<int> q;
	
	for (int i = 1; i <= n; i++)
	{
		if (!rd[i])
		{
			dp[i] = 1, dis[i] = 0;
			q.push(i);
		}
	}
	
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		
		for (int i = 0; i < (int)G[u].size(); i++)
		{
			int v = G[u][i];
			rd[v]--;
			
			if (dis[u] + 1 == dis[v]) dp[v] += dp[u];
			else if (dis[u] + 1 < dis[v]) dis[v] = dis[u] + 1, dp[v] = 1;
			
			if (!rd[v]) q.push(v);
		}
	}
}

int main()
{	
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);

	int t, c;
	cin >> c >> t;
	while (t--)
	{
		for (int i = 1; i <= n; i++) 
			G[i].clear();
		
		cin >> n >> d;
		rd.resize(n + 1, 0);
		for (int i = 1; i <= n; i++)
		{
			cin >> pos[i];
			for (int j = 1; j < i; j++)
			{
				if (abs(pos[j] - pos[i]) <= d)
				{
					G[j].push_back(i);
					rd[i]++;
				}
			}
		}
		
		topu();
		
		long long cnt = 0;
		for (int i = 1; i <= n; i++)
			if (dp[i] == 2) cnt++;
		
		cout << cnt << "\n";
	}
	
	return 0;
}