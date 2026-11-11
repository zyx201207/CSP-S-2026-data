#include <iostream>
#include<cstdio>
#include <algorithm>
#define int long long
using namespace std;

int n, m;
int ans = 0;
int a[200010];
bool vis[200010];

void DFS(int cnt, int sum)
{
	if (cnt > m)
	{
		ans = max(ans, sum);
	}
	for (int i = 1; i <= n; i++)
	{
		if (vis[i])
			continue;
		vis[i] = true;
		DFS(cnt + 1, sum & a[i]);
		vis[i] = false;
	}
}

signed main ()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++)
	{
		vis[i] = true;
		DFS(2, a[i]);
		vis[i] = false;
	}
	cout << ans;
	return 0; 
}
