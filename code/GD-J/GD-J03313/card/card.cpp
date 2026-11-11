#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[500100];
int table[500100];
int ap[500100];
int ans[500100];

int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++)
	{
		for (int j = i; j <= n; j++)
		{
			table[j] = a[j];
			if (ap[table[j]] == false) ap[table[j]] = true;
			else
			{
				for (int l = j-1; l >= i; l--)
				{
					table[l] = 0;
					ap[table[l]] = false;
					if(table[l-1] == table[j]) break;
				}
				table[j] = 0;
			}
		}
		for (int j = i; j <= n; j++)
		{
			ans[table[j]]++;
			table[j] = 0;
			ap[table[j]] = false;
			if(table[j+1] == 0) break;
		}
	}
	for (int i = 1; i <= m; i++)
		cout << ans[i] << ' ';
	return 0;
}
