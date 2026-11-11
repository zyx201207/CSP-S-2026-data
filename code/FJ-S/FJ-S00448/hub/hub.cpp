#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e4 + 5;
const int INF = 1e7;
int c, t, n, k, dis[MAXN][MAXN], ans;
int main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> t;
	while(t--)
	{ 
		cin >> n >> k;
		for  (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
				dis[i][j] = INF;
			dis[i][i] = 0; 
		}
		for (int k = 1; k <= n; k++)
			for (int i = 1; i <= n; i++)
				for (int j = 1; j <= n; j++)
					if (dis[i][k] != INF && dis[k][j] != INF)
					{
						dis[i][j] = min(dis[i][j], dis[i][k]+ dis[k][j]); 
					 }
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				for (int k = 1; k <= n; k++)
					if (dis[i][k] != INF && dis[k][j] != INF)
						 ans = max(dis[i][k] + dis[j][k], ans);
		cout << ans << endl;
	}
	return 0;
}
