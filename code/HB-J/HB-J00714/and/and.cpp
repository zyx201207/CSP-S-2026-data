#include <bits/stdc++.h>
using namespace std;
int n, m, cnt, ans, a[200010], vis[200010];
int main()
{
	freopen("and.in", "r", stdin), freopen("and.out", "w", stdout);
	scanf("%d%d", &n, &m), cnt = n;
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 30; i >= 0; i--)
	{
		int x = 0;
		for (int j = 1; j <= n; j++)
			if (!vis[j])
				x += !((1 << i) & a[j]);
		if (cnt - x >= m)
		{
			cnt -= x, ans += 1 << i;
			for (int j = 1; j <= n; j++)
				if (!vis[j])
					vis[j] = !((1 << i) & a[j]);
		}
	}
	printf("%d", ans);
	return 0;
}
