#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5;

int n, m, maxn;
int a[N + 5];

void dfs(int step, int sum, int val)
{
	if (step > n || sum > m)
	{
		if (sum == m) maxn = max(maxn, val);
		return;
	}
	
	dfs(step + 1, sum + 1, val == -1 ? a[step] : (a[step] & val));
	dfs(step + 1, sum, val); 
}

bool cmp(int x, int y)
{
	return x > y;
}

signed main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	if (n <= 2000)
	{
		dfs(1, 0, -1);
		cout << maxn;
	} 
	else
	{
		sort(a + 1, a + n + 1, cmp);
		int ans = a[1];
		for (int i = 2; i <= m; i++) ans &= a[i];
		cout << ans;
	}
	return 0;
}
