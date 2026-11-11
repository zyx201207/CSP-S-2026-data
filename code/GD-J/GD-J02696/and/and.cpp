#include <bits/stdc++.h>
using namespace std;

int n, m, a[200002], ans;
bool vis[200002];

void dfs(int flr, int nw)
{
	//~ cout << "floor:" << flr << ' ' << "and now is " << nw << endl;
	if(flr > m)
	{
		ans = max(ans, nw);
		return;
		//~ cout << "back to " << flr - 1 << endl;	
	}
	
	for(int i = 1; i <= n; i++)
	{
		if(vis[i])
		{
			continue;
		}
		//~ cout << "choose" << a[i] << endl;
		vis[i] = 1;
		dfs(flr + 1, nw & a[i]);
		vis[i] = 0;
	}
	//~ cout << "back to " << flr - 1 << endl;
}
		

int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}
	if(m == 1)
	{
		for(int i = 1; i <= n; i++)
		{
			ans = max(ans, a[i]);
		}
	}
	else if(m == n)
	{
		ans = a[1];
		for(int i = 2; i <= n; i++)
		{
			ans &= a[i];
		}
	}
	else if(m == 2)
	{
		for(int i = 1; i <= n; i++)
		{
			for(int k = 1; k <= n; k++)
			{
				if(k == i)
				{
					continue;
				}
				ans = max(ans, a[i] & a[k]);
			}
		}
	}
	else
	{
		for(int i = 1; i <= n; i++)
		{
			vis[i] = 1;
			dfs(2, a[i]);
			vis[i] = 0;
		}
	}
	printf("%d", ans);
	return 0;
}


