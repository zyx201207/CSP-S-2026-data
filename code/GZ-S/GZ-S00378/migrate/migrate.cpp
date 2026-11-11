//GZ-S00378 ³ÂË¼Ù¡ 
#include <bits/stdc++.h>

#define int long long
#define endl '\n'

using namespace std;

const int N1 = 2e6+11;
const int N = 3e2+11, INF = 1e9;
int n, d;
int a[N1];
int dist[N][N];
int cnt[N][N];

inline void solve1()
{
	d = d / (a[2] - a[1]);
	for (int i = 1; i <= n; i ++)
		a[i] = i;
	
	if (d == 1)
	{
		cout << 0 << endl;
		return;
	}	
//	cout << d << endl;

	int ans = 0;
	for (int i = 1; i <= n; i ++)
	{
		ans += (n - a[i]) / d;
//		cout << i << " " << ans << endl;
	}
		
	cout << ans / 2 << endl;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	int c, T;
	cin >> c >> T;
	while (T --)
	{
		cin >> n >> d;

		for (int i = 1; i <= n; i ++)
		{
			cin >> a[i];
		}

		if (c == 11 || c == 12)
		{
			solve1();
			continue;
		}

		for (int i = 1; i <= n; i ++)
			for (int j = 1; j <= n; j ++)
			{
				dist[i][j] = dist[j][i] = INF;
				cnt[i][j] = cnt[j][i] = 0;
			}
		
		for (int i = 1; i <= n; i ++)
		{
			int j = i + 1;
			
			while (a[j] - a[i] <= d && j <= n)
			{
				dist[i][j] = dist[j][i] = 1;
				cnt[i][j] = cnt[j][i] = 1;
				j ++;
			}
			
//			cout << i << " " << j - 1 << endl;
		}
		
		for (int k = 1; k <= n; k ++)
		{
			for (int i = 1; i <= n; i ++)
			{
				for (int j = 1; j <= n; j ++)
				{
					if (i == j || i == k || j == k)
						continue;
						
					int new_dist = dist[i][k] + dist[k][j];
//					cout << i << " " << k << " " << j << endl;
					
					if (new_dist < dist[i][j])
					{
						dist[i][j] = new_dist;
						cnt[i][j] = 1;
//						cout << 1 << endl;
					}
					else
					if (new_dist == dist[i][j])
					{
						cnt[i][j] ++;
//						cout << 2 << endl;
					}
//					else cout << dist[k][j] << endl;
				}
			}
		}
		
		int ans = 0;
		
		for (int i = 1; i <= n; i ++)
			for (int j = 1; j <= n; j ++)
				if (cnt[i][j] == 2)
					ans ++;
		
		cout << ans / 2 << endl;
	}	

	return 0;
}
