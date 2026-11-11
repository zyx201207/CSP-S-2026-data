#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 2e5 + 5;
int n, m, ans = -1, a[N], sum, t;

void dfs(int step, int cnt, int sum)
{
	if (cnt == m)
	{
		ans = max(ans, sum);
		return;
	}
	if (step > n) return;
	dfs(step + 1, cnt + 1, sum & a[step]);
	dfs(step + 1, cnt, sum);
}

struct node
{
	int val, cnt;
} b[N];

bool cmp(node x, node y)
{
	if (x.cnt == y.cnt) return x.val > y.val;
	return x.cnt > y.cnt;
}
 	 
signed main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	if (n <= 20) 
	{
		dfs(1, 0, -1);
		cout << ans;
		return 0;
	}
	if (m == 1)
	{
		for (int i = 1; i <= n; i++) ans = max(ans, a[i]);
		cout << ans;
		return 0;
	}
	if (m == n)
	{
		for (int i = 1; i <= n; i++) ans &= a[i];
		cout << ans;
		return 0;
	}
	if (m == n - 1)
	{
		sort(a + 1, a + n + 1);
		for (int i = n; i >= n - m + 1; i--) ans &= a[i];
		cout << ans;
		return 0;
	}
	for (int i = 1; i <= n; i++) b[i].val = a[i], b[i].cnt = __builtin_popcountll(a[i]);
	sort(b + 1, b + n + 1, cmp);
	for (int i = 1; i <= m; i++) ans &= b[i].val;
	cout << ans; 
	return 0;
}  	
