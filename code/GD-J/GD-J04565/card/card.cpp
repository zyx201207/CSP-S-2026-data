#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;
int a[N], n, m, v[N], cur, vis[N], ans[N];

int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++)
	{
		cur = 0;
		for (int j = 1; j <= n; j++) v[i] = 0;
		for (int j = 1; j <= m; j++) vis[j] = 0;
		for (int j = i; j <= n; j++)
		{
			if (!vis[a[j]]) v[++cur] = a[j], vis[a[j]] = 1;
			else
			{
				for (int k = 1; k <= cur; k++)
				{
					if (v[k] == a[j])
					{
						for (int l = k; l <= cur; l++) v[l] = 0;
						cur = k - 1, v[++cur] = a[j];
						break;
					}
				}
			}
		}
		for (int j = 1; j <= cur; j++) ans[v[j]]++;
	}
	for (int i = 1; i <= m; i++) cout << ans[i] << " ";
	return 0;
 } 
