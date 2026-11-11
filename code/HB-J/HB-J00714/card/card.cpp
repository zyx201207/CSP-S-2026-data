#include <bits/stdc++.h>
using namespace std;
int n, m, a[500010], lst[500010], cnt[500010], dif[500010], book[500010], ans[500010];
int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++)
		cnt[i] = cnt[lst[a[i]]] + 1, lst[a[i]] = i;
	for (int i = n; i >= 1; i--)
	{
		book[a[i]] = cnt[i];
		for (int j = n; j >= i; j--)
		{
			if (book[a[j]] && ((cnt[j] - book[a[j]]) & 1))
			{
				dif[j]++;
				break;
			}
			else if (j == i)
				dif[j]++;
		}
	}
	for (int i = 1; i <= n; i++)
		dif[i] += dif[i - 1], ans[a[i]] += dif[i];
	for (int i = 1; i <= m; i++)
		printf("%d ", ans[i]);
	return 0;
}
