#include<bits/stdc++.h>
using namespace std;
int n, m;
long long a[200005], ans;
void dfs(int x, int k, long long sum)
{
	if (x > n || k == m)
	{
		if (k == m && sum > ans)
		{
			ans = sum;
		}
		return;
	}
	for (int i = 1; i <= n; ++i)
	{
		
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
	}
	for (int i = 1; i <= n; ++i)
	{
		dfs(i, 1, a[i]);
	}
	cout << ans;
	return 0;
}
