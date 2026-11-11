
#include<bits/stdc++.h>
#define pii pair<int,int>
#define Mp make_pair

using namespace std;
using ll = long long;

const int N = 5e5+1;

int c, n, m, d, q;
ll w[N];
map <pii, ll> mp;

struct node {int d; ll v;};
bool operator< (const node &x, const node &y) { return x.v > y.v;}
priority_queue <node> pq;
map <int, ll> dist[N];
bool vis[N], Vis[N];

void dijk (int s)
{
	if (Vis[s]) return;
	Vis[s] = true;
	memset (vis, 0, sizeof vis);
	while (not pq.empty()) pq.pop();
	
	dist[s][s] = 0;
	pq.push (node{s, dist[s][s]});
	
	while (not pq.empty())
	{
		int now = pq.top().d;
		pq.pop();
		if (vis[now])
			continue;
		vis[now] = true;
		for (int i = 1; i <= m; i++)
			if (mp[Mp(now, i)] != 0 and not vis[i] and (dist[s][i] == 0 or dist[s][i] > dist[s][now] + mp[Mp(now, i)]))
				dist[s][i] = dist[s][now] + mp[Mp(now, i)],
				pq.push (node{i, dist[s][i]});
	}
}

int main()
{
	freopen ("subway.in", "r", stdin);
	freopen ("subway.out", "w", stdout);
	
	ios::sync_with_stdio (false);
	cin.tie (nullptr), cout.tie (nullptr);
	
	cin >> c >> n >> m >> d >> q;

	for (int i = 1; i <= m; i++)
		cin >> w[i];
		
	for (int i = 1; i <= n; i++)
	{
		int k;
		cin >> k;
		int a[N] = {0};
		ll t[N] = {0};
		for (int i = 1; i <= k; i++)
			cin >> a[i] >> t[i];
		for (int i = 1; i <= k; i++)
			for (int j = 1; j <= k; j++)
				if (i != j)
					mp[Mp(a[i], a[j])] = mp[Mp(a[i], a[j])] == 0 ? t[i] + t[j] : min (mp[Mp(a[i], a[j])], t[i] + t[j]);
	}
	
	while (q--)
	{
		int s, t;
		cin >> s >> t;
		dijk (s);
		cout << dist[s][t] + w[s] + w[t] << '\n';
	}
	
	return 0;
}
