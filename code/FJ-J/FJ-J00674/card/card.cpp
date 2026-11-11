#include <bits/stdc++.h>
using namespace std;
int n, m, ans[500005];
int a[500005], b[300005], c[300005];
queue <int> q;
//a-store b-tong
int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	for (int i = 1;i <= n;i++)
	{
		for (int j = i;j <= n;j++)
		{
			c[a[j]]++;
		}
		for (int j = i;j <= n;j++)
		{
			q.push(a[j]);
			if (c[a[j]] >= 2)
			{
				while (!q.empty())
				{
					q.pop();
				}
				q.push(a[j]);
			}
		}
		while (!q.empty())
		{
			ans[q.front()]++;
			q.pop();
		}
		for (int j = 1;j <= m;j++)
		{
			c[j] = 0;
		}
	}
	for (int i = 1;i <= m;i++)
	{
		cout << ans[i] << " ";
	}
	return 0;
}
/*
卑鄙我去吧瞬间就爱上雷神
yellow and purple 小 fish

1.
4 3
1 2 1 3

3 1 4

2.
10 3
3 1 2 1 3 2 3 1 2 1

10 3 3
*/

