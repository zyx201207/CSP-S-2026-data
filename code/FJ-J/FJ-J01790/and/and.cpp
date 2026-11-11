#include <bits/stdc++.h>
using namespace std;

int n, m, a[200001];
bool flag[200001];

int dfs(int l, int ans)
{
	if(ans == 0) return 0;
	if(l >= m) return ans;
	int maxn = -1;
	for (int i = 1;i <= n;i++)
	{
		if(!flag[i])
		{
			flag[i] = true;
			maxn = max(maxn, dfs(l + 1, ans & a[i]));
			flag[i] = false;
		}
	}
	return maxn;
}

int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> a[i];
	if(m == n)
	{
		int ans = a[1];
		for (int i = 2;i <= n;i++) ans = ans & a[i];
		cout << ans;
		return 0;
	}
	if(m == 1)
	{
		int maxn = -1;
		for (int i = 1;i <= n;i++) maxn = max(maxn, a[i]);
		cout << maxn;
	}
	cout << dfs(0, 0x3f);
	return 0;
}
