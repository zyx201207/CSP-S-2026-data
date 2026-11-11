#include <bits/stdc++.h>
#define unique UNIQUE
using namespace std;
const int N = 2e6 + 12;
const int E = 21;
long long a[N];
int up[E][N];
long long endings[E][N];
char options[E][N];
int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int C, T, n;
	long long d;
	scanf("%d %d", &C, &T);
	while (T--)
	{
		scanf("%d %lld", &n, &d);
		for (int i = 1; i <= n; i++)
			scanf("%lld", &a[i]);
		int r = 1;
		long long A = 0;
		for (int i = 1; i <= n; i++)
		{
			while (r <= n - 1 && a[r + 1] - a[i] <= d) r++;
			if (r > i) up[0][i] = r;
		}
		for (int j = 1; j < E; j++)
			for (int i = 1; i <= n; i++)
				up[j][i] = up[j - 1][up[j - 1][i]];
		for (int i = 1; i <= n; i++)
		{
			if (!up[1][i])
			{
				options[0][i] = 2;
				continue;
			}
			if (up[0][i] - i <= 1 || up[0][up[0][i] - 1] < up[1][i]) continue;
			options[0][i]++;
			if (up[0][i] - i <= 2 || up[0][up[0][i] - 2] < up[1][i]) continue;
			options[0][i]++;
		}
		for (int j = 1; j < E; j++)
			for (int i = 1; i <= n; i++)
			{
				options[j][i] = options[j - 1][i] + options[j - 1][up[j - 1][i]];
				if (options[j][i] >= 3) options[j][i] = 2;
			}
		// options at the tail
		for (int i = 1; i <= n; i++)
		{
			if (!up[1][i]) continue;
			if (up[0][i] == i + 1) continue;
			endings[0][i] = up[0][up[0][i] - 1] - up[0][up[0][i] - 2];
			A += endings[0][i];
			if (up[0][i - 1] >= up[0][i] - 1) endings[0][i] = 0;
		}
		for (int j = 1; j < E; j++)
			for (int i = 1; i <= n; i++)
				endings[j][i] = endings[j - 1][i] + endings[j - 1][up[j - 1][i]];
		for (int i = 1; i <= n; i++)
		{
			if (options[0][i]) continue;
			A -= endings[0][i];
			int z = i;
			for (int j = E - 1; j >= 0; j--)
				if (!options[j][z])
				{
					A += endings[j][z];
					z = up[j][z];
				}
			A += endings[0][z];
		}
		for (int j = 0; j < E; j++)
			for (int i = 1; i <= n; i++)
				endings[j][i] = 0;
		// options not at the tail
		for (int i = 1; i <= n; i++)
		{
			if (!up[1][i]) continue;
			endings[0][i] = up[0][up[0][i]] - up[0][up[0][i] - 1];
		}
		for (int j = 1; j < E; j++)
			for (int i = 1; i <= n; i++)
				endings[j][i] = endings[j - 1][i] + endings[j - 1][up[j - 1][i]];
		for (int i = 1; i <= n; i++)
		{
			int z = i;
			if (!options[0][i])
			{
				for (int j = E - 1; j >= 0; j--)
					if (!options[j][z]) z = up[j][z];
			}
			if (options[0][z] == 2) continue;
			if (up[0][z - 1] >= up[0][z] - 1 && z != i) continue;
			z = up[0][z];
			for (int j = E - 1; j >= 0; j--)
				if (!options[j][z])
				{
					A += endings[j][z];
					z = up[j][z];
				}
			A += endings[0][z];
		}
		// finished
		printf("%lld\n", A);
		for (int i = 1; i <= n; i++)
			a[i] = 0;
		for (int j = 0; j < E; j++)
			for (int i = 1; i <= n; i++)
			{
				up[j][i] = 0;
				endings[j][i] = 0;
				options[j][i] = 0;
			}
	}
	return 0;
}
// 15:30 - 17:30, samples passed (2877 ms), [60, 100] points
// 17:30 - 17:40, samples passed (644 ms), 100 points

