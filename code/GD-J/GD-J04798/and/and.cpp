#include <bits/stdc++.h>
using namespace std;

#define int long long

int n, m, maxn = -2e9;
int a[200005];
int b[200005];
bool vis[1050000];

void dfs(int dep)
{
	if(dep == m + 1)
	{
		int ans = b[1] & b[2];
		for(int i = 3 ; i <= m ; i++)
		{
			ans = ans & b[i];
		}
//		cout << ans << endl;
		maxn = max(maxn, ans);
		return;
	}
	for(int i = 1 ; i <= n ; i++)
	{
		if(vis[i] == false)
		{
			vis[i] = true;
			b[dep] = a[i];
			dfs(dep + 1);
			vis[i] = false;
		}
	}
}

signed main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i++)
	{
		cin >> a[i];
	}
	dfs(1);
	cout << maxn << endl;
	return 0;
}
