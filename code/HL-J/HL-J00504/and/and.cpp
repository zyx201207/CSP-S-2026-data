#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int a[200001];
int n, m;
int logcc(int t)
{
	int retu = 1;
	while ((1 << retu) <= t)
	{
		retu ++;
	}
	return retu - 1;
}
bool andcan(int t)
{
	int tmp = 2147483647;
	int cnt = 0;
	for (int i = 1; i <= n; i ++)
	{
		if ((t & a[i]) >= t)
		{
			cnt ++;
		}
	}
	return cnt >= m;
}
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int maxx = 0;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i ++)
	{
		scanf("%d", &a[i]);
		maxx = max(a[i], maxx);
	}
	sort(a + 1, a + n + 1, greater<int>());
	int ans = 0;
	int pp = (1 << logcc(maxx));
	while (pp >= 1)
	{
		if (!andcan(ans + pp))
		{
			// printf("%d isn't a answer\n", ans + pp);
		}
		else
		{
			// printf("%d might be a answer\n", ans + pp);
			ans += pp;
		}
		pp >>= 1;
	}
	// printf("the answer is %d", ans);
	printf("%d", ans);
}