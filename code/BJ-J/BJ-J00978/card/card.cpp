#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int a[N], st[N],en[N], ans[N];
bool f[N];
signed main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,m;
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
		if (!st[a[i]]) st[a[i]] = i;
		en[a[i]] = i;
	}
	for (int i = 1;i <= n;i++)
	{
		int j = i;
		while (j <= n)
		{
			//cout << j << " ";
			j = en[a[j]];
			ans[a[j]]++;
			j++;
		}
	}
	for (int i = 1;i <= m;i++) cout << ans[i] << " ";
	return 0;
}
