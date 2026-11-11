#include <iostream>
#include <cstdio>
using namespace std;
bool use[2005];
int a[2005];
long long maxn = -1e18;
const long long inf = 0x3f3f3f;
int n, m;
void speedup()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
}
void dfs(int step)
{
	if (step > n)
	{
		long long ans = inf;
		int cnt = 0;
		for (int i = 1; i <= n; i++) if (use[i]) ans &= a[i], cnt++;
		if (cnt == m) maxn = max(maxn, ans);
		return;
	}
	use[step] = true;
	dfs(step + 1);
	use[step] = false;
	dfs(step + 1);
}
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	speedup();
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	dfs(1);
	cout << maxn << endl;
	return 0;
}
