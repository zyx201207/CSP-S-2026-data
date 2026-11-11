#include<bits/stdc++.h>
using namespace std;
const int N = 2e6 + 10;
#define int long long
int c, t;
int n, d;
int x[N];
int f[N];
int g[N];

void solve()
{
	cin >> n >> d;
	for(int i = 1; i <= n; i++)
		cin >> x[i];
//	if(c == 13 || c == 14)
//	{
//		int w = 1e9 + 10;
//		for(int i = 1; i <= n; i++)
//			if(x[i] - x[1] <= d && x[n] - x[i] <= d) w = min(w, i);
//		int ans = 0;
//		for(int i = 1; i < w; i++)
//		{
//			int l = i, r = n;
//			while(l < r)
//			{
//				int mid = (l + r + 1) / 2;
//				if(x[mid] - x[i] <= d) l = mid;
//				else r = mid - 1;
//			}
//			if(l - w > 1) continue;
//			l = 
//		}
//	}
	int ans = 0;
	for(int i = 1; i <= n; i++)
	{
		f[i] = 0;
		g[i] = 1;
		for(int j = i + 1; j <= n; j++)
			f[j] = N, g[j] = 0;
		for(int j = i; j < n; j++)
		{
			for(int k = j + 1; k <= n && x[k] - x[j] <= d; k++)
			{
				if(f[k] > f[j] + 1)
				{
					f[k] = f[j] + 1;
					g[k] = 0;
				}
				if(f[k] == f[j] + 1) g[k] += g[j], g[k] = min(3ll, g[k]);
			}
		}
		for(int j = i + 1; j <= n; j++)
			if(g[j] == 2) ans++;
	}
	cout << ans << endl;
}

signed main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while(t--) solve();
	return 0;
}
