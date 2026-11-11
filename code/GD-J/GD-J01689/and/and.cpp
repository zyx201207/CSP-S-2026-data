#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[200005], vis[200005], maxx = -1;	
int n, m;
void dfs(int id, int ans) {
	if(id == m + 1)
	{
		maxx = max(maxx, ans);
		return ;
	}
	for(int i = 1;i <= n;i++)
	{
		if(vis[i] == 0)
		{
			if(ans == -1)
			{
				vis[i] = 1;
				dfs(id + 1, a[i]);
				vis[i] = 0;
			}
			else {
				vis[i] = 1;
				dfs(id + 1, (ans & a[i]));
				vis[i] = 0;
			}
		}
	}
}
signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	int cnt = -1;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
		if(cnt == -1)
		{
			cnt = a[i];
		}
		else cnt = (cnt & a[i]);
	}
	sort(a + 1, a + n + 1);
	if(n <= 20)
	{
		dfs(1, -1);
		cout << maxx;
		return 0;
	}
	if(m == 1)
	{
		cout << a[n];
		return 0;
	}
	if(m == n)
	{
		cout << cnt;
		return 0;
	}
	if(m == 2)
	{
		for(int i = 1;i < n;i++)
		{
			for(int j = i + 1;j <= n;j++)
			{
				maxx = max(maxx, (a[i] & a[j]));
			}
		}
		cout << maxx;
		return 0;
	}
	for(int i = n;i >= n - m + 1;i--)
	{
		if(maxx == -1)
		{
			maxx = a[i];
		}
		else maxx = (maxx & a[i]);
	}
	cout << maxx;
	return 0;
}
