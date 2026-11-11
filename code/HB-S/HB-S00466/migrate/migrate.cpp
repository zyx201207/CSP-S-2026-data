#include <cstdio>
#include <algorithm>
#include <cstring>
using std::min;
using std::max;
#define minx(A, B) (A = min(A, B))
typedef long long intt;

const int MX = 2000010;

intt x[MX];

namespace solve
{
namespace DP
{
int nxt[MX];
intt f[MX][3][4];

void init(int n, intt d)
{
	for (int i = n, j = n; i; nxt[i--] = j)
		for (; x[j] - x[i] > d; j--);
}

void trans(int i, int t, int j, int k, intt x)
{
	int se = i + 1 < t ? 1 : 2, sse = i + 2 < t ? 2 : 3;

	const auto check = [&](int s) -> void
	{
		if (nxt[s] == t)
			minx(sse, se), se = 0;
		if (nxt[s] > i and nxt[s] >= t - 1)
			minx(sse, 1);
		if (nxt[s] > i and nxt[s] >= t - 2)
			minx(sse, 2);
	};

	if (j < 2)
		check(i - j);
	if (k < 3)
		check(i - k);
	f[t][se][sse] += x;
}

void add(int i, int j, int k, intt x, intt& res)
{
	if (j < 2)
	{
		if (k < 3)
			res += (nxt[i - j] - nxt[i - k]) * x;
		else res += max(nxt[i - j] - i, 0) * x;
	}
}

intt DP(int n, intt d)
{
	init(n, d);
	memset(f + 1, 0, sizeof(f[0]) * n);
	intt ret = 0;
	for (int i = 1; i <= n; i++)
		if (f[i][2][3]++, i != nxt[i])
			for (int j = 0; j < 3; j++)
				for (int k = j; k < 4; k++)
					if ((j < i or j == 2) and (k < i or k == 3) and f[i][j][k])
						trans(i, nxt[i], j, k, f[i][j][k]),
						add(i, j, k, f[i][j][k], ret);
	return ret;
}
}

intt solve(int n, intt d)
{
	return DP::DP(n, d);
}
}

int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int t, n;
	intt d;
	scanf("%*d%d", &t);
	while (t--)
	{
		scanf("%d%lld", &n, &d);
		for (int i = 1; i <= n; scanf("%lld", x + i++));
		printf("%lld\n", solve::solve(n, d));
	}
}