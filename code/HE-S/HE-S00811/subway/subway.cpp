#include <bits/stdc++.h>
#define int long long

using namespace std;
const int N = 5e5 + 20;
const int M = 555;

int c, n, m, d, q;
int w[N], k, r;
int x, y;
int f[M][M];
int a, ta;
bool vis[M][M];
bool cnm;

signed main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);	
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= n; i ++)
	{
		for (int j = 1; j <= n; j ++)
		{
			f[i][j] = INT_MAX;
		}
	}
	for (int i = 1; i <= n; i ++) f[i][i] = 0;
	for (int i = 1; i <= m; i ++)
	{
		cin >> w[i];
		f[i][0] = w[i];
		f[0][i] = w[i];
	}
	int now = INT_MAX;
	for (int i = 1; i <= 2; i ++)
	{
		cin >> k;
		for (int j = 1; j <= 2 * k; j ++)
		{
			cin >> a >> ta;
			if (ta != now)
			{
				if (now == INT_MAX) now = ta;
				else cnm = 1;
			}
			f[a][0] = ta;
			f[0][a] = ta;
			f[a][j] = 0;
			f[j][a] = 0;
			vis[i][j] = 1;
			vis[j][i] = 1;
		}
	}
	if (!cnm)
	{
		cin >> r;
		while (r --)
		{
			cin >> x >> y;
			if (vis[x][y])
			{
				cout << 4 * ta << '\n';
				continue;
			}
			for (int i = 1; i <= n; i ++)
			{
				if (vis[x][i] && vis[i][y])
				{
					cout << 6 * ta << '\n';
					break;
				}
			}
		}
	}
	for (int k = 1; k <= n; k ++)
	{
		for (int i = 1; i <= n; i ++)
		{
			for (int j = 1; j <= n; j ++)
			{
				f[i][j] = min(f[i][j] + f[0][i], f[i][k] + f[k][j] + f[0][i] + f[k][0]); 
			}
		}			
	}
	cin >> r;
	while (r --)
	{
		cin >> x >> y;	
		cout << f[x][y] << '\n';	
	}
	return 0;
}
/*
	你奶奶的。我怎么什么都不会。。
	暴力都不知道怎么写。
	什么啥子题面。
	cnm的CCF退钱 
*/
