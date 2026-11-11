#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
const int N = 2e5 + 10;
int n, m, a[N], vis[N], maxn = -1;
void dfs(int k, int ans, int len)
{
	// Debug
	// cout << k << " " << ans << " " << len << "\n";
	
	if(ans < maxn) return;
	if(len >= m)
	{
		maxn = max(maxn, ans);
		return;
	}
	vis[k] = 1;
	for(int i = k + 1; i <= n; i ++)
	{
		if(vis[i]) continue;
		dfs(i, ans & a[i], len + 1);
		vis[i] = 0;
	}
}
signed main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i ++) cin >> a[i];
	if(m == n)
	{
		int ans = a[1];
		for(int i = 2; i <= n; i ++) ans = ans & a[i];
		cout << ans << "\n";
		return 0;
	}
	if(n <= 2000)
	{
		for(int i = 1; i <= n; i ++)
		{
			memset(vis, 0, sizeof vis);
			dfs(i, a[i], 1);
		}
		cout << maxn << "\n";
		return 0;
	}
	sort(a + 1, a + n + 1, greater<int>());
	cout << a[m] << "\n";
	return 0;
}

