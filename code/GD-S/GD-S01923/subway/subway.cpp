#include <bits/stdc++.h>
using namespace std;

struct st
{
	long long l, t, w;	
};

const int N = 2 * 1E4 + 5, M = 505, MXN = 2 * 1E5 + 5;
int c, n, m, d, q, ck, x, l, r, wc[MXN];
vector<st> kc[MXN];
long long dp[M][M];

void init()
{
	for(int i = 1; i <= n; i ++)
	{
		for(int j = 1; j <= n; j ++)
		{
			dp[i][j] = 1e18;
		}
		dp[i][i] = 0;
	}
}

void floyd()
{
	for(int k = 1; k <= n; k ++)
	{
		for(int i = 1; i <= n; i ++)
		{
			for(int j = 1; j <= n; j ++)
			{
				dp[i][j] = min(dp[i][k] + dp[k][j], dp[i][j]);
			} 
		}
	}
}

int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); 
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i ++)
	{
		cin >> wc[i];
	}
	init();
	for(int i = 1; i <= n; i ++)
	{
		cin >> ck;
		for(int j = 1; j <= ck; j ++)
		{
			long long t1;
			cin >> x >> t1;
			for(int k = 0; k <kc[x].size(); k ++)
			{
				long long v = kc[x][k].l;
				long long w = kc[x][k].t;
				dp[i][v] = min(dp[i][v], t1 + w);
				dp[v][i] = min(dp[v][i], t1 + w);
			}
			kc[x].push_back({i, t1, t1 + wc[x]});
		}
	}
	floyd();	
	for(int i = 1; i <= q; i ++)
	{
		cin >> l >> r;
		long long mn = 1e18;
		for(int i = 0; i < kc[l].size(); i ++)
		{
			for(int j = 0; j < kc[r].size(); j ++)
			{
				long long u = kc[l][i].l, v = kc[r][j].l;
				mn = min(dp[u][v] + kc[l][i].w + kc[r][j].w, mn);
			}
		}
		cout << mn << "\n";
	}	
}
