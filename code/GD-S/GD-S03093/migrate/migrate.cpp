#include <iostream>
#include <cstdio>
#include <queue>
#define ll long long
#define inf 1e18
using namespace std;
const int N = 5005;
int c, n, d, x[N], f[N][N];
ll dis[N][N];
void dfs(int s, int now, ll sum)
{
	if (now > n)
	{
		return;
	}
	for (int i = now+1; i <= n; i++)
	{
		if (x[i]-x[now] > d) break;
		if (sum+1 < dis[s][i])
		{
			dis[s][i] = sum+1;
			dfs(s, i, sum+1);
		}
	}
}
void dfs2(int s, int now, ll sum)
{
	if (now > n)
	{
//		if (sum == dis[s][n]) f[s][n]++;
		return;
	}
	for (int i = now+1; i <= n; i++)
	{
		if (x[i]-x[now] > d) break;
		if (sum+1 == dis[s][i])
		{
			f[s][i]++;
			dfs2(s, i, sum+1);
		}
		
	}
}
int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int T;
	cin >> c >> T;
	while (T--)
	{
		cin >> n >> d;
		for (int i = 1; i <= n; i++) cin >> x[i];
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++) dis[i][j] = inf, f[i][j] = 0;
//			vis[i] = true;
			dfs(i, i, 0);
		}
		for (int i = 1; i <= n; i++) 
			dfs2(i, i, 0);
		int ans = 0;
		for (int i = 1; i <= n; i++)
		{
			for (int j = i+1; j <= n; j++)
			{
				if (f[i][j] == 2) ans++;
//				cout << f[i][j] << (j == n ? "\n" : " ");
			}
		}
		cout << ans << "\n"; 
	}
	return 0;
}/*




0 2
4 2
1 2 3 4
5 2
1 2 3 4 5


0 1
4 2
1 2 3 4








*/
