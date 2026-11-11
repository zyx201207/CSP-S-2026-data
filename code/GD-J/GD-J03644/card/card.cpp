#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5 * 100000 + 5, MAXM = 3 * 100005 + 5;

int a[MAXN], b[MAXM];//int d[MAXM];
bool c[MAXM];

int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);     cout.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	
	for (int i = 1; i <= n; i++)
	{
		memset(c, false, sizeof c);
		for (int j = i; j <= n; j++)
		{
			if (c[a[j]] == true)
				for (int k = j; k >= i; k--)//for (int k = d[a[j]]; k >= i; k--)
					c[a[k]] = false;
			c[a[j]] = true;
			//d[a[j]] = j;
		}
		
		for (int j = 1; j <= m; j++)
			if (c[j])
				b[j]++;
	}
	
	for (int i = 1; i <= m; i++)
		cout << b[i] << ' ';
	
	cout << '\n';
	return 0;
} 
