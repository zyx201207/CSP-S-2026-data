//GZ-J00103 张万嘉 贵阳市第十九中学
#include <bits/stdc++.h>
using namespace std;
long long a[200010];
bool flag[200010];
long long n, m, ans = -1;
void dfs(long long x, long long num)
{
	if(x == m)
	{
		ans = max(ans, num);
		return ;
	}
	for(long long i = 1; i <= n; i++)
	{
		if(flag[i]) continue;
		flag[i] = true;
		if(num == -1) dfs(x + 1, a[i]);
		else dfs(x + 1, (num & a[i]));
		flag[i] = false;
	}
}
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	bool f = true;
	long long maxn = -1;
	for(long long i = 1; i <= n; i++)
	{
		cin >> a[i];
		if(a[i] != a[i - 1]) f = false;
		maxn = max(maxn, a[i]);
	}
	if(m == 1)
	{
		cout << maxn;
		return 0;
	}
	if(f == true)
	{
		cout << a[1];
		return 0;
	}
	dfs(0, -1);
	cout << ans;
	return 0;
}
