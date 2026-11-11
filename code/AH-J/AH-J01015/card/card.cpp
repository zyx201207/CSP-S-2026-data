#include <bits/stdc++.h>
using namespace std;
#define MAXN 500005
int n, m, a[MAXN], id[MAXN], f[5005][3005], ans, vis[MAXN], last[MAXN], lst[MAXN];
vector<int> v[MAXN];
int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++)
	{
		memset(vis, 0, sizeof(vis));
		memset(last, 0, sizeof(last));
		for (int j = i; j <= n; j++)
		{
			vis[a[j]]++;
			if (vis[a[j]] > 1)
			{
				for (int k = last[a[j]]; k < j; k++)
				{
					last[a[k]] = 0;
					vis[a[k]]--;
					vis[a[k]] = max(vis[a[k]], 0);
				}
			}
			last[a[j]] = j;
		}
		for (int j = i; j <= n; j++)
		{
			if (vis[a[j]]) 
			{
				v[i].push_back(a[j]);
			}
		}
	}
	for (int i = 1; i <= m; i++)
	{
		int cnt = 0;
		for (int j = 1; j <= n; j++)
		{
			for (int k : v[j])
			{
				if (k == i) 
				{
					cnt++;
					break;
				}
			}
		}
		cout << cnt << " "; 
	}
	return 0;
}
