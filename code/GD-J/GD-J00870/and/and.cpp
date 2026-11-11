#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N = 2e5 + 10;
int n, m, a[N], ans;
bool vis[N];
inline void dfs(int u, int sum)
{
	if(u == m + 1)
	{
		ans = max(ans, sum);
		return;
	}
	for(int i = 1; i <= n; i++)
	{
		if(vis[i]) continue;
		vis[i] = true;
		dfs(u + 1, (u == 1 ? a[i] : (sum & a[i])));
		vis[i] = false;
	}
}
signed main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	dfs(1, 1);
	cout << ans;
	return 0;
}
