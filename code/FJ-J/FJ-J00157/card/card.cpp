#include <bits/stdc++.h>
using namespace std;
bool f;
int n, m, s, l, a[500005], w[300005], e[300005], b[300005];
int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if (a[i] < a[i - 1])
		{
			f = true;
		}
	}
	if (f == false)
	{
		for (int i = 1; i <= n; i++)
		{
			w[i] = i;
		}
	}
	else
	{
		for (int i = 1; i <= n; i++)
		{
			l = 0;
			memset(b, -1, sizeof(b));
			for (int j = i; j <= n; j++)
			{
				if (b[a[j]] == -1)
				{
					l++;
					b[a[j]] = l;
					e[l] = a[j];
				}
				else
				{
					l = b[a[j]];
				}
			}
			s = 1;
			while (a[i + 1] == a[i])
			{
				s++;
				i++;
			}
			for (int j = 1; j <= l; j++)
			{
				w[e[j]] += s;
			}
		}
	}
	for (int i = 1; i <= m; i++)
	{
		cout << w[i] << " ";
	}
	return 0;
}
