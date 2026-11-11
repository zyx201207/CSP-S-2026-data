#include <iostream>
#include <cstdio>
#include <cstring>
#define ll long long
using namespace std;
const int N = 2e5 + 5, M = 3e5 + 5;
int n, m, x[N], id[M], ans[M];
void doit(int s, int e)
{
	bool vis[N];
	memset(id, 0, sizeof id);
	memset(vis, 0, sizeof vis);
	for (int i = s; i <= e; i++)
	{
		if (id[x[i]] && !vis[id[x[i]]])
		{
			for (int j = id[x[i]]; j < i; j++) vis[j] = true;
		}
		id[x[i]] = i;
	}
	for (int i = s; i <= e; i++)
	{
		if (!vis[i]) 
			ans[x[i]]++;
	}
	return;
}
int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	bool A = true;
	for (int i = 1; i <= n; i++)
	{
		cin >> x[i];
		if (x[i] < x[i-1]) A = false;
	}
	if (A)
	{
		for (int i = 1; i <= n; i++)
		{
			while (x[i+1] == x[i])
			{
				i++;
			}
			ans[x[i]] = i;
		}
		for (int i = 1; i <= m; i++) cout << ans[i] << " ";
		return 0;
	}
	for (int i = 1; i <= n; i++)
	{
		doit(i, n);
	}
	for (int i = 1; i <= m; i++) cout << ans[i] << " ";
	return 0;
}
/*


4 3
1 2 1 3



*/
