#include <iostream>
#include <vector>
using namespace std;

const int N = 510, M = 500010;
int w[M];
vector<int> side[N], sv[N], stat[M], uset[M];
int mind[N][N];
long long dp[N][N];

long long min(long long x, long long y)
{
	return (x < y ? x : y);
}

bool vis[N];
void getdp(int r, int n)
{
	for (int i = r + 1; i <= n; i++) vis[i] = false;
	for (int i = 1; i <= r; i++) dp[r][i] = dp[i][r];
	long long minv;
	int newid;
	for (int i = r + 1; i <= n; i++)
	{
		minv = 1145141919810, newid = 0;
		for (int j = r + 1; j <= n; j++)
		{
			if (vis[j]) continue;
			for (int k = 0; k < side[j].size(); k++)
			{
				if (vis[side[j][k]] && minv > dp[r][side[j][k]] + sv[j][k])
				{
					minv = dp[r][side[j][k]] + sv[j][k];
					newid = j;
				}
			}
		}
		vis[newid] = true;
		dp[r][newid] = minv;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int c, n, m, d, q, k, x, y, xt, yt;
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) cin >> w[i];
	for (int i = 1; i <= n; i++)
	{
		cin >> k;
		for (int j = 1; j <= k; j++)
		{
			cin >> x >> y;
			stat[x].push_back(i);
			uset[x].push_back(y);
		}
		for (int j = 1; j <= n; j++) mind[i][j] = 2147483647, dp[i][j] = 0;
	}
	vis[1] = true;
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j < stat[i].size(); j++)
		{
			x = stat[i][j], xt = uset[i][j];
			for (int k = 0; k < j; k++)
			{
				y = stat[i][k], yt = uset[i][k];
				mind[x][y] = min(mind[x][y], xt + yt);
				mind[y][x] = mind[x][y];
			}
		}
	}
	for (int i = 1; i < n; i++)
	{
		for (int j = i + 1; j <= n; j++)
		{
			if (mind[i][j] == 2147483647) continue;
			side[i].push_back(j);
			side[j].push_back(i);
			sv[i].push_back(mind[i][j]);
			sv[j].push_back(mind[i][j]);
			mind[i][j] = 2147483647;
		}
	}
	for (int i = 1; i <= n; i++) getdp(i, n);
	long long ans;
	for (int i = 1; i <= q; i++)
	{
		cin >> x >> y;
		ans = 1145141919810;
		for (int j = 0; j < stat[x].size(); j++)
		{
			for (int k = 0; k < stat[y].size(); k++)
			{
				ans = min(ans, dp[stat[x][j]][stat[y][k]] + uset[x][j] + uset[y][k]);
			}
		}
		ans += w[x] + w[y];
		cout << ans << endl;
	}
	return 0;
}