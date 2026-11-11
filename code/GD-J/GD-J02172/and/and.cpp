#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
typedef long long ll;
int n, m;
ll a[N];
bool vis[N];
ll ans = 0;
bool cmp(ll x, ll y)
{
	return x > y;
}
void dfs(int x, int step, ll cnt)
{
	if (step == m) 
	{
		ans = max(ans, cnt);
		return;
	}
	for (int i = x + 1;i <= n - m + step;i ++)
	{
		dfs(i, step + 1, cnt & a[i]);
	}
}
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	scanf("%d%d", &n, &m);
	for (int i = 1;i <= n;i ++)
	{
		scanf("%lld", &a[i]);
	}
	sort(a + 1, a + n + 1, cmp);
	for (int i = 1;i <= n - m + 1;i ++)
	{
		dfs(i, 1, a[i]);
	}
	printf("%lld", ans);
	return 0;
}
