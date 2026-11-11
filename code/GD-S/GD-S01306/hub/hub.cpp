#include<bits/stdc++.h>
using namespace std;
const int N = 2e6 + 10;
int c, t;
int n, k;
vector<int> e[N];
bool vis[N];
bool fl[N];
int ans = N;

void dfs(int x)
{
	fl[x] = 1;
	for(auto v : e[x])
	{
		if(fl[v]) continue;
		if(!vis[v]) continue;
		dfs(v);
	}
}

bool check()
{
	int cnt = 0;
	for(int i = 1; i <= n; i++)
		fl[i] = 0;
	for(int i = 1; i <= n; i++)
	{
		if(fl[i]) continue;
		if(!vis[i]) continue;
//		if(vis[2] && vis[3] && vis[10]) cout << i << endl;
		dfs(i);
		cnt++;
	}
//	if(vis[2] && vis[3] && vis[10]) cout << cnt << endl;
//	cout << cnt << endl;
	return (cnt <= 2);
}

int get()
{
//	for(int i = 1; i <= n; i++)
//		cout << vis[i] << " ";
//	cout << endl;
	int ans = 0;
	for(int i = 1; i <= n; i++)
	{
		queue<pair<int, int> > q;
		q.push({i, 0});
		for(int j = 1; j <= n; j++)
			fl[j] = 0;
		fl[i] = 1;
		while(q.size())
		{
			int x = q.front().first, s = q.front().second;
			q.pop();
			if(vis[x])
			{
				ans = max(ans, s);
				break;
			}
			for(auto v : e[x])
			{
				if(fl[v]) continue;
				fl[v] = 1;
				q.push({v, s + 1});
			}
		}
	}
//	cout << ans << endl;
	return ans;
}

void che(int x, int k)
{
	if(!k)
	{
		if(check()) ans = min(ans, get());
		return;
	}
	vis[x] = 0;
	if(x + k <= n) che(x + 1, k);
	vis[x] = 1;
	che(x + 1, k - 1);
	vis[x] = 0;
}

void solve()
{
	cin >> n >> k;
	for(int i = 1; i <= n; i++)
		e[i].clear();
	for(int i = 1; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		e[x].push_back(y);
		e[y].push_back(x);
	}
//	if(c == 1 || c == 2 || c == 3)
//	{
		ans = N;
		che(1, k);
		cout << ans << endl;
//	}
}

signed main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> t;
	while(t--) solve();
	return 0;
}
