#include <bits/stdc++.h>
using namespace std;

bool flag[1000005];
long long n, k;
vector<long long> now;
long long dep[1000005];
long long dp[1000005][25];
long long len[100005];
vector<long long> v[1000005];
long long vis[1000005];

void calc(long long x, long long fa)
{
	dep[x] = dep[fa] + 1;
	len[x] = len[fa] + 1;
	dp[x][0] = fa;
	for(long long i = 0; i < v[x].size(); i++)
	{
		long long y = v[x][i];
		if(y == fa) continue;
		calc(y, x);
	}
}
long long lca(long long x, long long y)
{
	if(dep[x] < dep[y]) swap(x, y);
	for(long long i = 24; i >= 0; i--) if(dep[dp[x][i]] >= dep[y]) x = dp[x][i];
	if(x == y) return x;
	for(long long i = 24; i >= 0; i--) if(dp[x][i] != dp[y][i]) x = dp[x][i], y = dp[y][i];
	return dp[x][0];
}
long long ans = 1e9;
bool check()
{
	memset(vis, 0, sizeof(vis));
	for(long long i = 0; i < now.size(); i++) vis[i] = 1;
	long long cnt = 0;
	for(long long i = 0; i < now.size(); i++)
	{
		if(vis[now[i]] == 1)
		{
			cnt++;
			if(cnt >= 3) return false;
			queue<long long> q;
			q.push(now[i]);
			while(!q.empty())
			{
				long long x = q.front();
				q.pop();
				for(long long i = 0; i < v[x].size(); i++)
				{
					long long y = v[x][i];
					if(!vis[y] && vis[y] != 2) continue;
					vis[y] = 2;
					q.push(y);
				}
			}
		}
	}
	return true;
}
void dfs1(long long step)
{
	if(step > k)
	{
		now.clear();
		for(long long i = 1; i <= n; i++) if(flag[i]) now.push_back(i);
		long long x = lca(now[0], now[1]);
		long long sum = len[now[0]] + len[now[1]] - 2 * len[x];
		if(check()) ans = min(ans, sum);
		return;
	}
	for(long long i = 1; i <= n; i++)
	{
		if(!flag[i]) 
		{
			flag[i] = 1;
			dfs1(step + 1);
			flag[i] = 0;
		}
	}
}
void dfs(long long step)
{
	if(step > k)
	{
		now.clear();
		for(long long i = 1; i <= n; i++) if(flag[i]) now.push_back(i);
		long long maxn = -1e9;
		for(long long i = 0; i < now.size(); i++)
			for(long long j = i + 1; j < now.size(); j++) maxn = max(maxn, len[now[i]] + len[now[j]] - 2 * len[lca(now[i], now[j])]);
		ans = min(ans, maxn);
		return;
	}
	for(long long i = 1; i <= n; i++)
	{
		if(!flag[i]) 
		{
			flag[i] = 1;
			dfs(step + 1);
			flag[i] = 0;
		}
	}
}
int main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	long long c, t;
	cin >> c >> t;
	if(c == 7 || c == 11 || c == 12)
	{
		while(t--)
		{
			len[0] = -1;
			cin >> n >> k;
			for(long long i = 1; i <= n - 1; i++) 
			{
				long long x, y;
				cin >> x >> y;
				v[x].push_back(y);
				v[y].push_back(x);
			}
			calc(1, 0);
			for(long long j = 1; j <= 24; j++)
				for(long long i = 1; i <= n; i++) 
					dp[i][j] = dp[dp[i][j - 1]][j - 1];
			dfs1(1);
			cout << ans << "\n";
		}
	}
	else
	{
		while(t--)
		{
			len[0] = -1;
			cin >> n >> k;
			for(long long i = 1; i <= n - 1; i++) 
			{
				long long x, y;
				cin >> x >> y;
				v[x].clear();
				v[y].clear();
				v[x].push_back(y);
				v[y].push_back(x);
			}
			//cout << "x" << endl;
			calc(1, 0);
			for(long long j = 1; j <= 24; j++)
				for(long long i = 1; i <= n; i++) 
					dp[i][j] = dp[dp[i][j - 1]][j - 1];
			dfs(1);
			cout << ans << "\n";
		}
	}
	return 0;
}
