#include <bits/stdc++.h> 
using namespace std;
int n, m, a[200005], ans[300005], v[200005], u[300005];
int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = i; j <= n; j++)
		{
			int l = i, r = i;
			while(l <= n)
			{
				v[l] = a[l];
				u[a[l]]++;
				if (u[a[l]] == 2)
				{
					int k = i;
					while(k <= n)
					{
						if (v[k] == a[l])
						{
							j = k;
							break;
						}
						k++;
					}
					u[a[l]]--;
				}
			}
		}
		for (int j = 1; j <= n; j++)
		{
			ans[v[j]]++;
		}
	}
	for (int i = i; i <= m; i++)
	{
		cout << ans[i] << " ";
	}
	return 0;
}
