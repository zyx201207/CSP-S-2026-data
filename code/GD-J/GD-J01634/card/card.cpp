#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int n , m;
int a[N] , g[N] , ans[N];

int main()
{
	freopen("card.in" , "r" , stdin);
	freopen("card.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (long long i = 0 ; i < n ; i ++)
	{
		cin >> a[i];
	}
	for (long long i = 0 ; i < n ; i ++)
	{
		memset(g , 0 , sizeof(g));
		for (long long j = i ; j < n ; j ++)
		{
			g[j - i] = a[j];
		}
		for (long long j = 0 ; j < n ; j ++)
		{
			if (g[j] == -1 || g[j] == 0)
			{
				continue;
			}
			for (long long k = j + 1 ; k < n ; k ++)
			{
				if (g[k] == -1 || g[k] == 0)
				{
					continue;
				}
				if (g[k] == g[j])
				{
					for (long long b = j ; b < k ; b ++)
					{
						g[b] = -1;
					}
				}
			}
		}
		for (long long j = 0 ; j < n ; j ++)
		{
			if(g[j] != -1)
			{
				ans[g[j]] ++;
			}
		}
	}
	for (long long i = 1 ; i <= m ; i ++)
	{
		cout << ans[i] << " ";
	}
	cout << '\n';
	
	return 0;
}
