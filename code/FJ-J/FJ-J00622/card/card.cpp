#include <bits/stdc++.h>
using namespace std;
int a[500005], book[300005];
int ans[500005], p[500005];

int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	int flag = 1;
	for (int i = 1; i < n; i++)
		if (a[i] > a[i + 1])
		{
			flag = 0;
			break;
		}
	if (flag)
	{
		for (int i = 1; i <= n; i++)
			book[a[i]] = i;
		for (int i = 1; i < m; i++)
			cout << book[i] << ' ';
		cout << book[m];
		return 0;
	}
	if (m <= 2)
	{
		int ans[3];
		ans[1] = ans[2] = 0;
		for (int i = 1; i < n; i++)
			ans[a[i]]++;
		if (a[n] == 1) ans[1] = n;
		if (a[n] == 2) ans[2] = n;
		cout << ans[1] << ' ' << ans[2];
		return 0;
	}
	for (int i = 1; i <= m; i++)
		ans[i] = 0; 
	for (int i = 1; i <= n; i++)
	{
		int top = 0;
		for (int j = i; j <= n; j++)
		{
			int flag = 0;
			for (int k = top; k >= 1; k--)
				if (p[k] == a[j])
				{
					flag = k;
					break;
				}
			if (flag == 0)
			{
				p[++top] = a[j];
				continue;
			}
			top = flag;
		}
		for (int i = 1; i <= top; i++)
			ans[p[i]]++;
	}
	for (int i = 1; i < m; i++)
		cout << ans[i] << ' ';
	cout << ans[m];
	return 0;
}
