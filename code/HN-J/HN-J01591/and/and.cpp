#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[200005];
int ans;

void dfs(int l, int res, int cnt)
{
	if(l == n + 1)
	{
		if(cnt == m)
		{
			ans = max(ans, res);
		}
		return;
	}
	
	dfs(l + 1, res & a[l], cnt ++);
	dfs(l + 1, res, cnt);
} 

int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i ++)
	{
		cin >> a[i];
	}
//	dfs(1, 1, 0);
	for(int i = 1;i <= n;i ++)
	{
		dfs(1, a[i], 0);
	}
	cout << ans;
	return 0;
} 
