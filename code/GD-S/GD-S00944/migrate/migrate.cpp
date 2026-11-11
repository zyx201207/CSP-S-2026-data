#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N = 2e6 + 10;
int c, t, n, d, Min, cnt;
bool vis[N];
vector<int> g[N];
void dfs(int u, int step, int t)
{
	if(u == t)
	{
		if(step < Min)
		{
			Min = step, cnt = 1;
		}
		if(step == Min) cnt++;
		return ;
	}
	for(int v : g[u])
	{
		if(vis[v]) continue;
		vis[v] = true;
		dfs(v, step + 1, t);
		vis[v] = false;
	}
}
signed main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cin >> c >> t;
	while(t--)
	{
		for(int i = 1; i <= n; i++) g[i].clear();
		cin >> n >> d;
		vector<int> x(n + 5, 0);
		for(int i = 1; i <= n; i++) cin >> x[i];
		for(int i = 1; i <= n; i++)
		{
			for(int j = i + 1; j <= n; j++)
			{
				if(abs(x[i] - x[j]) <= d)
				{
					g[i].push_back(j);
					g[j].push_back(i);
				}
			}
		}
		int ans = 0;
		for(int i = 1; i <= n; i++)
		{
			for(int j = i + 1; j <= n; j++)
			{
				Min = LLONG_MAX, cnt = 0;
				dfs(i, 0, j);
				if(cnt == 2) ans++;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
