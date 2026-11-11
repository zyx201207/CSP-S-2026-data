#include <bits/stdc++.h>
using namespace std;
const int N = 2*1e5+10;
int n,m;
int a[N];
int use[N];
int vis[N];
int ans = 0;

void dfs(int u)
{
	if (u == m+1)
	{
		int anss = use[1];
		for (int i = 2;i <= m;i++)
		{
			anss = (anss & use[i]);
		}
		if (anss > ans)
		{
			ans = anss;
		}
		return;
	}
	for (int i = 1;i <= n;i++)
	{
		if (vis[i] == 0)
		{
			vis[i] = 1;
			use[u] = a[i];
			dfs(u+1);
			use[u] = 0;
			vis[i] = 0;
		}
	}
	return;
}

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	dfs(1);
	cout << ans;
	return 0;
}
