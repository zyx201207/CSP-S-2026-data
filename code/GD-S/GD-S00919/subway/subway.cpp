#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 505;
const int M = 5e5 + 5;

int subT, n, m, d, q;
int w[M];

int arrCnt[M];
pair<int, int> arr[M][22];

inline void addLine(int stopId, int paid, int lineId)
{
	arr[stopId][++arrCnt[stopId]] = {lineId, paid};
}

ll dist[N][N];

inline void chkmin(ll &obj, const ll &val)
{
	(obj > val) && (obj = val);
}

namespace IO
{
	char ch;
	void faread(int& num)
	{
		ch = 0; num = 0;
		while (!isdigit(ch)) ch = getchar();
		while (isdigit(ch))
		{
			num = num * 10 + ch - '0';
			ch = getchar();
		}
	}
}
using IO::faread;

int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	faread(subT), faread(n), faread(m);
	faread(d), faread(q);
	for (int i = 1; i <= m; ++i)
	{
		faread(w[i]);
	}
	for (int i = 1; i <= n; ++i)
	{
		int stopCnt;
		faread(stopCnt);
		for (int j = 1; j <= stopCnt; ++j)
		{
			int stopId, paid;
			faread(stopId);
			faread(paid);
			addLine(stopId, paid, i);
		}
	}
	memset(dist, 0x3f, sizeof dist);
	for (int i = 1; i <= m; ++i)
	{
		for (int j = 1; j <= arrCnt[i]; ++j)
		{
			int u = arr[i][j].first, du = arr[i][j].second;
			for (int k = j + 1; k <= arrCnt[i]; ++k)
			{
				int v = arr[i][k].first, dv = arr[i][k].second;
				chkmin(dist[u][v], du + dv);
				chkmin(dist[v][u], du + dv);
			}
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		dist[i][i] = 0;
	}
	for (int k = 1; k <= n; ++k)
	{
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= n; ++j)
			{
				chkmin(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
	while (q--)
	{
		ll ans = 2e18;
		int S, T;
		faread(S); faread(T);
		for (int i = 1; i <= arrCnt[S]; ++i)
		{
			int u = arr[S][i].first, du = arr[S][i].second;
			for (int j = 1; j <= arrCnt[T]; ++j)
			{
				int v = arr[T][j].first, dv = arr[T][j].second;
				chkmin(ans, dist[u][v] + du + dv);
			}
		}
		printf("%lld\n", ans + w[S] + w[T]);
	}
	return 0;
}
