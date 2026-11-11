#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;


int n,m,a[200001];
int dfs(int x,int y,int ans)
{
	if (y == m && ans != 0) return ans;
	if (x > n || x + m - y > n) return 0;
	if (ans == 0) return max(dfs(x + 1,y + 1,a[x]),dfs(x + 1,y,0));
	return max(dfs(x + 1,y + 1,ans & a[x]),dfs(x + 1,y,ans));
}

int ans;
int main()
{
	freopen("and3.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++) cin >> a[i];
	if (n <= 20)
	{
		ans = dfs(1,0,0);
	}
	if (m == 1)
	{
		ans = -1;
		for (int i = 1;i <= n;i++) ans = max(ans,a[i]);
		cout << ans;
	}
	if (m == n)
	{
		ans = a[1];
		for (int i = 1;i <= n;i++) ans = ans & a[i];
	}
	if (m == 2)
	{
		ans = -1;
		for (int i = 1;i <= n;i++) for (int j = i + 1;j <= n;j++) ans = max(ans,a[i] & a[j]);
	}
	cout << ans;
	return 0;
}
