#include <bits/stdc++.h>
//#define int long long
using namespace std;
const int N = 50;
int n, k;
int f[N];
int ab[N][N], pp[N];
int dis[N][N];
int find(int u)
{
	return f[u] != u ? f[u] = find(u): u;
}
void solve()
{
	
//	memset(h, -1, sizeof h);
	memset(dis, 0x3f, sizeof dis);
	cin >> n >> k;
	for (int i = 1; i <= n - 1; i ++ )
	{
		f[i] = i;
		int x, y;
		cin >> x >> y;
		ab[x][y] = 1;
		dis[x][y] = 1;
		dis[y][x] = 1;
	}
	for (int k = 1; k <= n; k ++ )
	{
		for (int i = 1; i <= n; i ++ )
		{
			for (int j = 1; j <= n; j ++ )
			{
				dis[i][j] = min(dis[i][k] + dis[k][j], dis[i][j]);
//				cout << dp[i][j] << ' ';
			}
//			cout << '\n';
		}
//		cout << '\n';
	}
	f[n] = n;
	
	int ans = 0x3f3f3f3f;
	for (int i = 0; i < (1 << n); i ++ ) if (__builtin_popcount(i) == k)
	{
		memset(pp, 0, sizeof pp);
		for (int j = 0; j < n; j ++ )
		{
			if (i >> j & 1)
			{
				pp[i] = 1;
			}
		}
		for (int j = 1; j <= n; j ++ )
		{
			for (int k = 1; k <= n; k ++ )
			{
				if (pp[j] == 1 && pp[k] == 1)
				{
					f[find(j)] = find(k);
				}
			}
		}
		set<int> st;
		for (int j = 1; j <= n; j ++ )
		{
			if (f[j] == j) st.insert(f[j]);
		}
		if (st.size() <= 2)
		{
			int tt = 0;
			for (int i = 1; i <= n; i ++ ) if (pp[i])
			{
				int kk = 0x3f3f3f3f;
				for (int j = 1; j <= n; j ++ ) if (i != j) if (!pp[j])
				{
					kk = min(kk, max(dis[j][i], dis[i][j]));
					
//					cout << dis[i][j] << ' ' <<tt << ' ';
				}
//				cout << kk << '\n';
				tt = max(kk, tt);
			}
//			cout << tt << '\n';
			if (tt != 0)
			ans = min(ans, tt);
		}
		
	}
	cout << ans << '\n';
	return ;
}
int main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int c, t;
	cin >> c >> t;
	while (t -- ) solve();
	return 0;
}

