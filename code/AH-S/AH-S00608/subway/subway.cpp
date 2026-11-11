#include <bits/stdc++.h>
using namespace std;
const int N = 512;
const int M = 5e5 + 12;
const int D = 22;
const long long I = 1e18;
long long lines[N][N];
int gates[M];
int stations[M];
int platforms[M][D];
int transfers[M][D];
int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int C, n, m, d, q;
	scanf("%d %d %d %d %d", &C, &n, &m, &d, &q);
	for (int i = 1; i <= m; i++)
		scanf("%d", &gates[i]);
	for (int i = 1; i <= n; i++)
	{
		int k, a, t;
		scanf("%d", &k);
		for (int j = 1; j <= k; j++)
		{
			scanf("%d %d", &a, &t);
			stations[a]++;
			platforms[a][stations[a]] = i;
			transfers[a][stations[a]] = t;
		}
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (i != j) lines[i][j] = I;
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= stations[i]; j++)
			for (int k = j + 1; k <= stations[i]; k++)
			{
				long long distance = transfers[i][j] + transfers[i][k];
				if (lines[platforms[i][j]][platforms[i][k]] > distance)
					lines[platforms[i][j]][platforms[i][k]] = distance;
				if (lines[platforms[i][k]][platforms[i][j]] > distance)
					lines[platforms[i][k]][platforms[i][j]] = distance;
			}
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				lines[i][j] = min(lines[i][j], lines[i][k] + lines[k][j]);
	while (q--)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		long long a = I;
		for (int i = 1; i <= stations[x]; i++)
			for (int j = 1; j <= stations[y]; j++)
			{
				long long distance = lines[platforms[x][i]][platforms[y][j]];
				distance += gates[x] + gates[y];
				distance += transfers[x][i] + transfers[y][j];
				a = min(a, distance);
			}
		printf("%lld\n", a);
	}
	return 0;
}
// 15:10 - 15:30, samples passed (278 ms), 100 points

