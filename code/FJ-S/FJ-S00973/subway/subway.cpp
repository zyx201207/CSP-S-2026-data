#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<LL, LL> PII;
const LL N = 5e5 + 10, T = 510, INF = 1e18;

LL v[N];
vector<PII> ag[N];
LL d[T][T];

LL read()
{
	LL x = 0, f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9')
	{
		if (ch == '-') f = -f;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9')
	{
		x = (x << 3) + (x << 1) + ch - '0';
		ch = getchar();
	}
	return x * f;
}

void write(LL x)
{
	if (x < 0) {putchar('-'); x = -x;}
	if (x <= 9) {putchar(x + '0'); return;}
	write(x / 10); putchar(x % 10 + '0');
}

void solve()
{
	LL C = read(), n = read(), m = read(), D = read(), Q = read();
	for (LL i = 1; i <= m; i ++ ) v[i] = read();
	for (LL i = 1, K; i <= n; i ++ )
	{
		K = read();
		while (K -- )
		{
			LL a = read(), t = read();
			ag[a].push_back({i, t});
		}
	}
	for (LL i = 1; i <= n; i ++ )
		for (LL j = 1; j <= n; j ++ )
		{
			if (i == j) d[i][j] = 0;
			else d[i][j] = INF;
		}
	for (LL i = 1; i <= m; i ++ )
	{
		LL sz = (LL)ag[i].size();
		for (LL j = 0; j < sz; j ++ )
			for (LL k = j + 1; k < sz; k ++ )
			{
				LL u = ag[i][j].first, w1 = ag[i][j].second;
				LL v = ag[i][k].first, w2 = ag[i][k].second;
				d[u][v] = min(d[u][v], w1 + w2), d[v][u] = min(d[v][u], w1 + w2);
			}
	}
	for (LL k = 1; k <= n; k ++ )
		for (LL i = 1; i <= n; i ++ )
			for (LL j = 1; j <= n; j ++ )
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
	while (Q -- )
	{
		LL s = read(), t = read();
		LL mn = INF, sz1 = (LL)ag[s].size(), sz2 = (LL)ag[t].size();
		for (LL i = 0; i < sz1; i ++ )
			for (LL j = 0; j < sz2; j ++ )
			{
				LL u = ag[s][i].first, w1 = ag[s][i].second;
				LL v = ag[t][j].first, w2 = ag[t][j].second;
				mn = min(mn, d[u][v] + w1 + w2);
			}
		write(mn + v[s] + v[t]); putchar('\n');
	}
}

int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	LL T = 1;
	while (T -- ) solve();
	return 0;
}
