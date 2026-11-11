#include <bits/stdc++.h>
#define int long long
#define eb emplace_back
#define endl putchar('\n')
using namespace std;
int read()
{
	int sum = 0, f = 1;
	char ch = getchar();
	for (ch;ch < '0' || ch > '9';ch = getchar()) if (ch == '-') {f = -1;}
	for (ch;ch >= '0' && ch <= '9';ch = getchar()) sum = sum * 10 + ch - '0';
	return sum * f;
}
void write(int x)
{
	if (x < 0) x = -x, putchar('-');
	if (x > 9) write(x / 10);
	putchar(x % 10 + '0');
}
void gmax(int &x, int y)
{
	if (y > x) x = y;
}
void gmin(int &x, int y)
{
	if (y < x) x = y;
}
const int N = 5e5 + 5, M = 505, inf = 1e18;
/*

注意到线路数很少，而从站到站必然要进过线路的，

考虑对线路之间做floyd，然后枚举起、终点分别从哪条线路开始 

*/
int CID, n, m, d, Q, w[N];
int dis[M][M];
struct Edge
{
	int to, val;
};
vector<Edge> vec[N];
signed main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	CID = read(), m = read(), n = read(), d = read(), Q = read();
	for (int i = 1;i <= n;i++) w[i] = read();
	for (int i = 1;i <= m;i++)
	{
		int k = read();
		for (int j = 1;j <= k;j++)
		{
			int a = read(), t = read();
			vec[a].eb((Edge){i, t});
		}
	}
	for (int i = 1;i <= m;i++)
	{
		for (int j = 1;j <= m;j++) dis[i][j] = inf;
		dis[i][i] = 0;
	}
	for (int i = 1;i <= n;i++)
	{
		for (int j = 0;j < vec[i].size();j++)
		{
			int u = vec[i][j].to, val1 = vec[i][j].val;
			for (int k = 0;k < vec[i].size();k++)
			{
				int v = vec[i][k].to, val2 = vec[i][k].val;
				if (u == v) continue;
				gmin(dis[u][v], val1 + val2);
			}
		}
	}
	for (int k = 1;k <= m;k++)
	{
		for (int i = 1;i <= m;i++)
		{
			if (dis[i][k] == inf) continue;
			for (int j = 1;j <= m;j++)
			{
				if (dis[k][j] == inf) continue;
				gmin(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}
	while (Q--)
	{
		int st = read(), ed = read();
		int ans = inf;
		for (int i = 0;i < vec[st].size();i++)
		{
			int u = vec[st][i].to, val1 = vec[st][i].val;
			for (int j = 0;j < vec[ed].size();j++)
			{
				int v = vec[ed][j].to, val2 = vec[ed][j].val;
				gmin(ans, w[st] + val1 + dis[u][v] + val2 + w[ed]);
			}
		}
		write(ans), endl;
	}
	return 0;
}
