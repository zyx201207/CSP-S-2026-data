#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 1;
int C, n, m, p, q, w[N];
long long d[501][501];
vector<pair<int, int>> a[N];
void Floyd()
{
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
}
int read()
{
	int a = 0;
	char c;
	while (c = getchar(), !isdigit(c));
	do
		a = a * 10 + c - '0';
	while (c = getchar(), isdigit(c));
	return a;
}
int sta[21], top;
void print(long long a)
{
	do
	{
		sta[++top] = a % 10;
		a /= 10;
	}
	while (a);
	while (top) putchar(sta[top--] + '0');
}
int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	C = read(), n = read(), m = read(), p = read(), q = read();
	for (int i = 1; i <= m; i++)
		w[i] = read();
	memset(d, 0x3f, sizeof d);
	for (int i = 1; i <= n; i++)
		d[i][i] = 0;
	for (int i = 1, k; i <= n; i++)
	{
		k = read();
		while (k--)
		{
			int u, t;
			u = read(), t = read();
			for (pair<int, int> x: a[u])
				d[x.first][i] = d[i][x.first] = min(d[i][x.first], (long long)x.second + t);
			a[u].emplace_back(i, t);
		}
	}
	Floyd();
	while (q--)
	{
		int s, t;
		s = read(), t = read();
		long long ans = 0x3f3f3f3f3f3f3f3f;
		for (pair<int, int> x: a[s])
			for (pair<int, int> y: a[t])
				ans = min(ans, x.second + y.second + d[x.first][y.first]);
		print(ans + w[s] + w[t]), putchar('\n');
	}
	return 0;
}
