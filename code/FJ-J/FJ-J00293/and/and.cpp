#include <iostream>
#include <algorithm>
using namespace std;

const int N = 2e5 + 10;

int s[40], d[N], n, m, ans;

bool flag[N];

inline void update(int k, int q)
{
	int n = 0;
	while (k)
	{
		if (k & 1)
		{
			s[n] += q;
		}
		k /= 2;
		n++;
	}
}

inline int nmbr()
{
	int w = 0;
	for (int i = 0; i <= 30; i++)
	{
		if (s[i] == m)
		{
			w += (1 << i);
		}
//		printf("%d ", s[i]);
	}
//	printf("\n");
	return w;
}

inline void dfs(int k)
{
	if (k > m)
	{
		ans = max(ans, nmbr());
		return ;
	}
	for (int i = 1; i <= n; i++)
	{
		if (!flag[i])
		{
			update(d[i], 1);
			flag[i] = true;
			dfs(k + 1);
			flag[i] = false;
			update(d[i], -1);
		}
	}
}

int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", d + i);
	}
	if (n <= 500)
	{
		dfs(1);
		printf("%d", ans);
		return 0;
	}
	sort(d + 1, d + 1 + n);
	for (int i = 1; i <= n; i++)
	{
		update(d[i], 1);
		if (i >= m)
		{
			ans = max(ans, nmbr());
			update(d[i - m + 1], -1);
		}
	}
	printf("%d", ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
4 2
3 15 12 12
5 3
31 3 1 15 7
done for 59min
*/
