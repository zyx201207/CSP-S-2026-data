#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 16;
int c, t, n, k, ans, mx, d[N], l, r, mid;
bool f[N];
vector<int> vc[N];
priority_queue<pair<int, int> > pq;
void bfs(int s)
{
	memset(d, 127, sizeof(d));
	d[s] = 0;
	pq.push(make_pair(0, s));
	while(pq.size())
	{
		int u = pq.top().second;
		pq.pop();
		for(int i = 0, v; i < vc[u].size(); i++)
		{
			v = vc[u][i];
			if(d[v] > d[u] + 1)
			{
				d[v] = d[u] + 1;
				pq.push(make_pair(d[v], v));
			}
		}
	}
	mx = 0;
	for(int i = 1; i <= n; i++) mx = max(mx, d[i]);
}

signed main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> t;
	while(t--)
	{
		cin >> n >> k;
		for(int i = 1; i <= n; i++) vc[i].clear();
		for(int i = 1, u, v; i < n; i++)
		{
			cin >> u >> v;
			vc[u].push_back(v);
			vc[v].push_back(u);
		}
		if(k == n)
		{
			cout << 0 << endl;
			continue;
		}
		if(k == 1)
		{
			ans = n;
			for(int i = 1; i <= n; i++) 
			{
				bfs(i);
				ans = min(ans, mx);
			}
			cout << ans << endl;
			continue;
		}
		if(k >= n / 2) cout << 1 << endl;
		else cout << (n / 2 - k - 1) / 4 + 2 << endl;
	}
	return 0;
}
