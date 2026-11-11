#include <bits/stdc++.h>
using namespace std;

const int N = 200001;

int n, m, a[N], ans; 

//&: 1&1=1; 1&0=0; 0&1=0; 0&0=0.

void dfs(int idx, int cnt, int num)
{
	if (cnt == m)
	{
		ans = max(num, ans);
		return ;
	}
	if (n-idx+1 == m-cnt)
	{
		for (int i = idx; i <= n; ++i) num = num & a[i];
		dfs(n+1, m, num);
		return ;
	}
	dfs(idx+1, cnt+1, num & a[idx]);
	dfs(idx+1, cnt, num);
}

int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	dfs(1, 0, 2147483647);
	cout << ans;
	return 0;
}
