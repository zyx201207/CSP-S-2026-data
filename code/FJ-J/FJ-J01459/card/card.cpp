#include <bits/stdc++.h>
using namespace std;

const int N = 5e5;
const int M = 3e5;
int a[N + 5], card[N + 5], b[M + 5];

int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	
	for (int i = 1; i <= n; i++)
	{
		int cur = 0;
		memset(card, 0, sizeof(card));
		for (int j = i; j <= n; j++)
		{
			int tmp = 0;
			bool f = 0;
			for (int p = 1; p <= cur; p++)
			{
				if (card[p] == a[j])
				{
					tmp = p;
					f = 1;
					break;
				}
			}
			if (f)
			{
				while (cur != tmp)
				{
					card[cur] = 0;
					cur --;
				}
				card[cur] = 0;
				cur --;
			}
			card[++cur] = a[j];
		} 
		
		for (int j = 1; j <= cur; j++)
		{
			b[ card[j] ] ++;
		}
	}
	
	for (int i = 1; i <= m; i++) cout << b[i] << " ";
	return 0;
} 
