#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5, M = 3e5 + 5;
int n, m;
int a[N];
int ans[M];
int vis[N];
int vvis[M];
int last[M];

int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);

	scanf("%d%d", &n, &m);

	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);

	for (int i = 1; i <= n; ++i)
	{
		memset(last, 0, sizeof last);
		memset(vis, 0, sizeof vis);
		memset(vvis, 0, sizeof vvis);

		for (int j = i; j <= n; ++j)
		{
			if (last[a[j]] && !vis[last[a[j]]])
				for (int k = last[a[j]]; k < j; ++k)
					vis[k] = 1;

			last[a[j]] = j;
		}

		for (int j = i; j <= n; ++j)
		{
			if (!vis[j] && !vvis[a[j]])
				++ans[a[j]], vvis[a[j]] = 1;
		}
	}

	for (int i = 1; i <= m; ++i)
		cout << ans[i] << ' ';

	return 0;
}
