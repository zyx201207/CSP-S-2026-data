#include<bits/stdc++.h>
#define int long long
using namespace std;
int n, m;
int a[200005];
int ans;
void dfs(int p, int l, int v)
{
	if(l == m)
	{
		ans = max(ans, v);
		return ;
	}
	for(int i = p + 1;i <= n;i++)
		dfs(i, l + 1, v & a[i]);
	return ;
}
signed main()
{
	ios::sync_with_stdio(false);cin.tie(0);
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
		cin >> a[i];
	sort(a + 1, a + n + 1, greater<int>());
	for(int i = 1;i <= n;i++)
		dfs(i, 1, a[i]);
	cout << ans;
	return 0;
}
