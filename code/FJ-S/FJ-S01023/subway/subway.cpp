/*
subway 1s,1024M
floyd, DP method
optimizing build graph
*/
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
typedef long long LL;
#define l first
#define t second
const int N = 505, M = 5e5 + 5;
const LL INF = 1e14 + 5;
int n, m, q;
int w[M];
LL f[N][N];
vector<PII> Line[M];
int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
	int c, d;
	scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
	for (int i = 1; i <= m; i ++)scanf("%d", &w[i]);
	for (int i = 1, k, x, y; i <= n; i ++)
	{
		scanf("%d", &k);
		while (k --)
		{
			scanf("%d%d", &x, &y);
			Line[x].push_back({i, y});
		}
		for (int j = 1; j <= n; j ++)f[i][j] = INF;
		f[i][i] = 0;
	}
	for (int i = 1; i <= m; i ++)
	{
		for (PII j : Line[i])
		{
			for (PII k : Line[i])f[j.l][k.l] = min(f[j.l][k.l], (LL)j.t + (LL)k.t);
		}
	}
	for (int k = 1; k <= n; k ++)
	{
		for (int i = 1; i <= n; i ++)
		{
			for (int j = 1; j <= n; j ++)f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
		}
	}
	while (q --)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		LL res = INF;
		for (auto i : Line[x])
		{
			for (auto j : Line[y])res = min(res, (LL)i.t + (LL)j.t + f[i.l][j.l]);
		}
		printf("%lld\n", res + (LL)w[x] + (LL)w[y]);
	}
    return 0;
}
