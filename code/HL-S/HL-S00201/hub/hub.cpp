#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	
	int c, t;
	cin >> c >> t;
	while(t--)
	{
		int n, k;
		cin >> n >> k; 
		vector<vector<int> > ed(n + 1, vector<int>(n + 1));
		for(int i = 0; i < n - 1; i++)
		{
			int u, v;
			cin >> u >> v;
			ed[u][v] = ed[v][u] = 1;
		}
		int ans = 10000;
		for(int i = 0; i < (2 << n); i += 2)
		{
			int cnt = 0;
			for(int j = 1; j <= n; j++) cnt += (i >> j) % 2;
			if(cnt != k) continue;
			cnt = 0;
			for(int j = 1; j <= n; j++)
			{
				if((i >> j) % 2)
				{
					bool ok = false;
					for(int k = j + 1; k <= n; k++)
					{
						if((i >> k) % 2)
						{
							if(ed[j][k] == 1)
							{
								ok = true;
								break;
							} 
						}
					}
					if(!ok) cnt++;
				}
			}
			if(cnt <= 2)
			{
				vector<int> dis(n + 1, -1);
				queue<int> q;
				for(int j = 1; j <= n; j++)
				{
					if((i >> j) % 2)
					{
						dis[j] = 0;
						q.push(j);
					}
				}
				while(!q.empty())
				{
					int f = q.front();
					q.pop();
					for(int k = 1; k <= n; k++)
					{
						if(!ed[f][k]) continue;
						if(dis[k] != -1) continue;
						dis[k] = dis[f] + 1;
						q.push(k);
					}
				}
				int r = 0;
				for(int j = 1; j <= n; j++) r = max(r, dis[j]);
				ans = min(ans, r);
			}
		}
		cout << ans << endl;
	}

	return 0;
}

