#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <stack>
#define int long long
using namespace std;

int n, m;
int a[500010], cnt[300010];
int num[500010];

signed main ()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w",stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for (int k = 1; k <= n; k++)
	{
		memset(num, 0, sizeof(num));
		stack<int> card;
		for (int i = k; i <= n; i++)
		{
			if (num[a[i]])
			{
				while(card.top() != a[i])
				{
					num[card.top()]--;
					card.pop();
				}
			}
			else
			{
				card.push(a[i]);
				num[a[i]]++;
			}
		}
		for (int i = 1; i <= m; i++)
		{
			if (num[i])
			{
				cnt[i]++;
			}
		}
		
	}
	for (int i = 1; i <= m; i++)
	{
		cout << cnt[i] << " ";
	}
	return 0;
}
