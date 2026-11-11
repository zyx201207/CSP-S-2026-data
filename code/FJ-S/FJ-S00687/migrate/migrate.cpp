#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e6 + 6;
int c, T, n;
ll d, x[N]; 
ll f[305][305], g[305][305];
void baoli()
{
	ll ans = 0;
	for (int len = 1; len <= n; len++)
	{
		for (int i = 1; i + len - 1 <= n; i++)
		{
			int j = i + len - 1;
			if (i == j)
			{
				f[i][j] = 0;
				g[i][j] = 1;
				continue;
			}
			if (x[j] - x[i] <= d) 
			{
				f[i][j] = 1;
				g[i][j] = 1;
				continue;
			}
			f[i][j] = 0x3f3f3f3f3f3f3f3f;
			g[i][j] = 0;
			for (int k = i+1; k <= j-1; k++)
			{
				if (x[j] - x[k] <= d)
				{
					if (f[i][j] == f[i][k] + 1 && g[i][k] > 0)
					{
						g[i][j] += g[i][k];
					}
					else if (f[i][j] > f[i][k] + 1 && g[i][k] > 0)
					{
						f[i][j] = f[i][k] + 1;
						g[i][j] = g[i][k];
					}
				}
			}
			if (g[i][j] == 2) ans++;
			
//			cout << i << ' ' << j << ' ' << f[i][j] << ' ' << g[i][j] << '\n';
		} 
	}
	cout << ans << '\n';
//	cout << "------------\n";
}
int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> c >> T;
	while (T--)
	{
		cin >> n >> d;
		for (int i = 1; i <= n; i++) cin >> x[i];
		baoli();
	}
	return 0;
 }

