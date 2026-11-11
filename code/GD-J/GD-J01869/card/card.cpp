#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+5, M = 3e5+5;

int n, m, a[N], ans[M];
int b[M];
int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	for (int k = 1;k <= n;k++)
	{
		memset(b, 0, sizeof(b));
		for (int i = n;i >= k;i--)
		{
			if (b[a[i]])
			{
				for (int j = i;;j++)
				{
					if (a[j] == a[i] && j != i
					) break;
					b[a[j]]--;
				} 
			}
			b[a[i]]++;
		}
		for (int i = 1;i <= m;i++) 
		{
			ans[i] += (b[i] > 0);
		}
	}
	for (int i = 1;i <= m;i++)
	{
		cout << ans[i] << " ";
	}
	return 0;
}
