#include <bits/stdc++.h>
using namespace std;
int n, m, a[500005], ans[300005], cnt[300005], flag;
int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++)
	{
		flag = 1;
		for (int l = i - 1; l >= 1; l--)
		{
			int r;
			for (r = i + 1; r <= n; r++)
			{
				if (a[r] == a[l])
				{
					flag = 0;
					break;
				}
			}
			if (!flag)
				break;
		}
		if (!flag)
			ans[a[i]]++;
		else
			ans[a[i]] += (i - cnt[a[i]]);
		cnt[a[i]] = i;
	}
	for (int i = 1; i <= m; i++)
		cout << ans[i] << " ";
	return 0; 
}
