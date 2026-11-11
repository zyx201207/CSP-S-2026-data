#include<bits/stdc++.h>
using namespace std;

int n, m, a[200005], ans;

void dfs(int s, int x, int y)
{
	if(y == m)
	{
		ans = max(ans, x);
		return;
	}
	
	for(int i = s + 1; i <= n - m + y + 1; i++)
	{
		int t = upper_bound(a, a + n + 1, a[i]) - lower_bound(a, a + n + 1, a[i]);
		dfs(i, x & a[i], min(m, y + t));
	}
}

int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	cin >> n >> m;
	
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	
	sort(a + 1, a + n + 1);
	
	dfs(0, (1 << 30) - 1, 0);
	
	cout << ans << endl;
	
	return 0;
} 
