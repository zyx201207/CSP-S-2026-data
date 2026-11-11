#include <bits/stdc++.h>
using namespace std;
int n, m, a[200005], maxa;
void dfs(int u, int num, int v)
{
	if (u == m)
	{
		maxa = max(maxa, num);
		return;
	}
	for (int i = v + 1; i <= n; i++)
	{
		//cout << num << " " << a[i] << " " << (num & a[i]) << endl;
		//num = (num & a[i]);
		//cout << u + 1 << " " << (num & a[i]) << " " << i << endl;
		dfs(u + 1, (num & a[i]), i);
	}
}
int main()
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
		dfs(1, a[i], i);
		//cout << 1 << a[i] << i << endl;
	}
	//dfs(1, 31, 1);
	cout << maxa;
	return 0;
}
