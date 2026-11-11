#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define em emplace_back
#define fi first
#define se second


const int MAXM = 5e5 + 5;
vector < pair < int , int > > adj[2 * MAXM + 500];
//1~m:µØÌú¿Ú m+1~2m:Õ¾Ìü 2m+1~2m+500:µØÌú 
int c, n, m, d, q;

priority_queue < pair < int , int > , vector < pair < int , int > > , greater < pair < int , int > > > qu;
vector < bool > vis;

int bfs(int st, int en)
{
	vis.clear();
	vis.resize(2 * m + n, 0);
	//cerr << "___";
	qu.push({0, st});
	while (!qu.empty())
	{
		auto now = qu.top();
		qu.pop();
		int u = now.se, l = now.fi;
		//cerr << "u=" << u << " len=" << l << endl;
		vis[u] = 1;
		if (u == en) return l;
		for (auto v : adj[u])
		{
			if (!vis[v.fi]) qu.push({l + v.se, v.fi});
		}
	}
	return 0;
}

int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	//freopen("subway.err", "w", stderr);
	
	ios :: sync_with_stdio(0);
	cin.tie(0);
	
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++)
	{
		int w;
		cin >> w;
		adj[i].em(m + i, w);
		adj[m + i].em(i, w);
	}
	
	for (int i = 1; i <= n; i++)
	{
		int k;
		cin >> k;
		for (int j = 1; j <= k; j++)
		{
			int a, t;
			cin >> a >> t;
			adj[m + a].em(m + m + i, t);
			adj[m + m + i].em(m + a, t);
		}
	}
	
	for (int i = 1; i <= q; i++)
	{
		int st, en;
		cin >> st >> en;
		cout << bfs(st, en) << endl;
	}
	
	return 0;
}

