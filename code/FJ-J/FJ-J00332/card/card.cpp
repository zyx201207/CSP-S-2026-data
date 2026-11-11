#include <bits/stdc++.h>
using namespace std;
int a[1000005], end[1000005];
bool cnt[1000005]; 
int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	queue<int> q;
	int n, m, cnt = 1;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = i; i <= n; i++)
		{
			if (cnt[a[j]])
			{
				for (int f = 1; f < j; f++)
				{
					if (a[f] == a[j])
					{
						for (int u = f; u <= j; u++)
						{
							cnt[a[u]] = 0;
						}
						break;
					}
				}
			}
			else
			{
				cnt[a[j]] = 1;
			}
		}
		for (int t = 1; t <= n; t++)
		{
			if(cnt[t])
			{
				end[t]++;
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		cout << end[i] << " ";
	}
	return 0;
}
