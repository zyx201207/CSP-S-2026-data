#include<bits/stdc++.h>
using namespace std;
int n, m, a[50010], x, k = 0, b[30010], c[50010];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> c[i];
	}
	for (int w = 1; w <= n; w++){
		for (int i = w; i <= n; i++)
		{
			x = c[i];
			for (int j = 0; j < k; j++)
			{
				if (a[j] == x)
				{
					k = j;
					a[j] = 0;
					break;
				}
			}
			a[k] = x;
			k++;
		}
		for (int j = 0; j < k; j++)
		{
			b[a[j]]++;
		}
	}
	for (int i = 1; i <= m; i++)
	{
		cout << b[i] << " ";
	}
	return 0;
}
