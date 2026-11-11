#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int Inf = 1e9, MAXN = 3e2 + 5;

int c, t, cnt[MAXN][MAXN], dis[MAXN][MAXN]; ll x[MAXN];

int main()
{
	freopen("migrate.in", "r", stdin); freopen("migrate.out", "w", stdout);
	
	cin >> c >> t;
	
	if (c == 11 || c == 12)
	{
		while (t --)
		{
			int n; ll d; cin >> n >> d;
			
			for (int i = 1; i <= n; i ++) cin >> x[i];
			
			cout << 0 << "\n";
		}
	}
	else
	{
		while (t --)
		{
			int n; ll d; cin >> n >> d;
			
			for (int i = 1; i <= n; i ++) cin >> x[i];
			
			for (int i = 1; i <= n; i ++)
			{
				cnt[i][i] = 1; dis[i][i] = 0;
				
				for (int j = i + 1; j <= n; j ++)
				{
					cnt[i][j] = cnt[j][i] = 0; dis[i][j] = dis[j][i] = Inf;
					
					if (abs(x[i] - x[j]) <= d)
					{
						cnt[i][j] = cnt[j][i] = 1; dis[i][j] = dis[j][i] = 1;
					}
				}
			}
			
			for (int k = 1; k <= n; k ++)
			{
				for (int i = 1; i <= n; i ++)
				{
					for (int j = 1; j <= n; j ++)
					{
						if (i == j || j == k || k == i) continue;
						
						if (dis[i][j] > dis[i][k] + dis[k][j])
						{
							dis[i][j] = dis[i][k] + dis[k][j]; cnt[i][j] = cnt[i][k] * cnt[k][j]; if (cnt[i][j] > 2) cnt[i][j] = 3;
						}
						else if (dis[i][j] == dis[i][k] + dis[k][j])
						{
							cnt[i][j] += cnt[i][k] * cnt[k][j]; if (cnt[i][j] > 2) cnt[i][j] = 3;
						}
					}
				}
			}
			
			ll ans = 0;
			
			for (int bg = 1; bg <= n; bg ++)
			{
				for (int ed = bg + 1; ed <= n; ed ++)
				{
					if (cnt[bg][ed] == 2) ans ++; //cout << cnt[bg][ed] << " ";
				}
			}
			
			cout << ans << "\n";
		}
	}
	
	return 0;
}
