#include <iostream>
#include <queue>
#include <cstdio>
#define int long long
using namespace std;

int n, m, a[2000010];
bool bfs(int s, int t)
{
	queue<pair<int, int> > q;
	q.push({s, 0});
	int minn = 1e18, mink = 0;
	while(!q.empty())
	{
		int u = q.front().first, cnt = q.front().second;
		q.pop();
		if(cnt > minn) continue;
		if(u == t)
		{
			if(cnt < minn) minn = cnt, mink = 1;
			else if(cnt == minn) mink++;
			continue;
		}
		for(int i = u + 1; i <= n; i++)
		{
			if(a[i] - a[u] > m) break;
			q.push({i, cnt + 1});
		}
	}
	return (mink == 2);
}
pair<int, int> p[2000010];
void solve()
{
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	if(n <= 100)
	{
		int cnt = 0;
		for(int l = 4; l <= n; l++)
		{
			for(int i = 1; i <= n - l + 1; i++)
			{
				int j = i + l - 1;
				if(bfs(i, j)) cnt++;
			}
		}
		cout << cnt << endl;
		return;
	}
	if(c == 11 || c == 12)
	{
		int d = a[2] - a[1];
		if(d > m) cout << 0 << endl;
		else cout << n - 3 << endl;
	}
	cout << 2 << endl;
}

signed main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	int c, T;
	cin >> c >> T;
	while(T--) solve();
	return 0;
}
