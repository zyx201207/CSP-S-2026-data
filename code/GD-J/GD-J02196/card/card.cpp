#include <bits/stdc++.h>
using namespace std;

int LastPosition[100005], a[200005], moni[200005];
int cnt[100005];
int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	int x = 0;
	for (int i = n; i >= 1; i--)
	{
		if (LastPosition[a[i]] == 0 || LastPosition[a[i]] > x)
		{
			LastPosition[moni[++x]] = 0;
			moni[x] = a[i];
			LastPosition[a[i]] = x;
		}
		else
		{
			x = LastPosition[a[i]];
		}
		for (int j = 1; j <= x; j++)
		{
			cnt[moni[j]]++;
		}
	}
	for (int i = 1; i <= m; i++)
	{
		cout << cnt[i] << " ";
	}
	return 0;
}
