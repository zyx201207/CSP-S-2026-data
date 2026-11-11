#include <iostream>
using namespace std;

const int N = 2e5 + 10;

int d[N], n, j, k;

long long ans;

char c[N];

int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d %c", d + i, c + i);
	}
	j = 1, k = n;
	while (j <= k)
	{
		if (d[j] > d[k])
		{
			if (c[j] != c[k])
			{
				ans += d[k];
			}
			d[j] -= d[k];
			k--;
		}
		else if (d[j] < d[k])
		{
			if (c[j] != c[k])
			{
				ans += d[j];
			}
			d[k] -= d[j];
			j++;
		}
		else
		{
			if (c[j] != c[k])
			{
				ans += d[j];
			}
			j++;
			k--;
		}
//		printf("%d %d %lld\n", j, k, ans);
	}
	printf("%lld", ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
3
2 a
2 b
1 c
2
2 a
3 a
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
done for 26min
*/
