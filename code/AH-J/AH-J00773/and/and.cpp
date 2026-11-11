#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2 * 1e5 + 10;
int n, m, a[N], b[N], ans = -1;
bool pd[N];
int dfs(int dep)
{
	if(dep == m + 1)
	{
		int cnt = b[1];
		for(int i = 2; i <= m; i++)
			cnt &= b[i];
		ans = max(ans, cnt);
		return dep;
	}
	for(int i = 1; i <= n; i++)
	{
		if(!pd[i])
		{
			pd[i] = 1;
			b[dep] = a[i];
			dfs(dep + 1);
			pd[i] = 0;
		}
	}
}
signed main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	dfs(1);
	cout << ans;
	return 0;
}
