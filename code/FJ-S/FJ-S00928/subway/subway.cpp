#include<bits/stdc++.h>
#define ll long long
using namespace std;

struct node
{
	ll line, time;
};

const ll N = 500 + 50, M = 2e4 + 50, INF = 1e8;
ll c, n, m, d, q, res = INF, w[N], trasfer_time[N][M];
bool sl[N][M], vis[N];
vector<ll> temp;
vector<node> G[N];
queue<node> que;

ll bfs(ll t)
{
	while(!que.empty())
	{
		ll u = que.front().line, cur_w = que.front().time;
		vis[u] = 1;
//		cout << "u = " << u << "	cur_w = " << cur_w << "\n";
		if(sl[u][t]) res = min(res, cur_w + trasfer_time[u][t]);
		que.pop();
		for(auto p : G[u])
		{
			ll v = p.line, w = p.time;
			if(vis[v]) continue;
			que.push({v, cur_w + w});
		}
	}
}

int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(ll i = 1; i <= m; i++) cin >> w[i];
	for(ll line = 1; line <= n; line++)
	{
		ll k;
		cin >> k;
		while(k--)
		{
			ll station, t;
			cin >> station >> t;
			sl[line][station] = 1;
			trasfer_time[line][station] = t;
		}
	}
	for(ll station = 1; station <= m; station++)
	{
		temp.clear();
		for(ll line = 1; line <= n; line++)
		{
			if(sl[line][station]) temp.push_back(line);
		}
		if(temp.size() <= 1) continue;
		for(ll l = 0; l < temp.size(); l++)
		{
			for(ll r = l + 1; r < temp.size(); r++)
			{
				ll line1 = temp[l], line2 = temp[r];
				G[line1].push_back({line2, trasfer_time[line1][station] + trasfer_time[line2][station]});
				G[line2].push_back({line1, trasfer_time[line1][station] + trasfer_time[line2][station]});
			}
		}
	}
//	for(ll i = 1; i <= n; i++)
//	{
//		cout << "line:" << i << "\n"; 
//		for(auto p : G[i])
//		{
//			cout << p.line << "," << p.time << "	";
//		}
//		cout << "\n";
//	}
	while(q--)
	{
		// ¶à²âÒªÇå¿Õ£¡ 
		res = INF; memset(vis, 0, sizeof(vis)); 
		while(!que.empty()) que.pop();
		ll s, t;
		cin >> s >> t;
		for(ll line = 1; line <= n; line++)
		{
			if(sl[line][s]) que.push({line, trasfer_time[line][s]});
		}
		bfs(t);
		cout << w[s] + w[t] + res << "\n";
	}
	return 0;	
}
