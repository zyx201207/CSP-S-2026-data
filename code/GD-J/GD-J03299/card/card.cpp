#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[500005], b[500005], ans[500005];
int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	for(int l = 1; l <= m; l++)
	{
		for(int i = 1; i <= n; i++)
		{
			b[i] = a[i];
			for(int j = 1; j <= i-1; j++)
			{
				if(b[i] == b[j])
				{
					b[j] = b[i];
					for(int x = j+1; x <= i; x++)
						b[x] = 0;
				}
			}
			ans[m]++;
			if(b[i] == m)
				break;
		}
	}
	for(int i = 1; i <= m; i++)
		cout << ans[m] << " ";
	return 0;
}
