#include <bits/stdc++.h>
using namespace std;
int n, m, a[500005], b[500005], p, sum[300005];
bool st[300005];
int main ()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1;i <= n;i++)
		scanf("%d", &a[i]);
	for (int i = 1;i <= n;i++)
	{
		memset(b, 0, sizeof b);
		memset(st, false, sizeof st);
		p = 0;
		for (int j = i;j <= n;j++)
		{
			while (st[a[j]] == true)
			{
				st[b[p]] = false;
				b[p--] = 0;
			}
			b[++p] = a[j];
			st[a[j]] = true;
		}
		for (int j = 1;j <= p;j++)
			sum[b[j]]++;
	}
	for (int i = 1;i <= m;i++)
		printf("%d ", sum[i]);
	return 0;
}
