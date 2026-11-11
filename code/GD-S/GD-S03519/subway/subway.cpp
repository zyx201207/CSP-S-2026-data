#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> PII;

const int MAXN = 5e2+10;
const int MAXM = 5e5+10;

int c, n, m, d, q;
int w[MAXN + MAXM];
vector<PII> e[MAXN + MAXM]; // 1 ~ n , n+1 ~ n+m

ll dis[MAXN][MAXN];

void dijkstra(int s)
{
	priority_queue<PII, vector<PII>, greater<PII>> pq;
	dis[s][s] = 0, pq.push({0, s});
	while(!pq.empty())
	{
		auto x = pq.top(); pq.pop();
		ll d = x.first, u = x.second;
		if(d > dis[s][u]) continue;
		for(auto x : e[u])
		{
			ll v = x.first, w1 = x.second;
			for(auto x : e[v])
			{
				ll nu = x.first, w2 = x.second;
				if(nu == u) continue;
				ll nd = dis[s][u] + w1 + w2;
				if(nd < dis[s][nu])
				{
					dis[s][nu] = nd;
					pq.push({nd, nu});
				}
			}
		}
	}
}

map<int, int> ds[MAXN];

int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
//	clock_t bg = clock();
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i+n];
	for(int u=1;u<=n;u++)
	{
		int k; cin>>k;
		while(k--)
		{
			int v, t;
			cin>>v>>t;
			v += n;
			ds[u][v] = t;
			e[u].push_back({v, t});
			e[v].push_back({u, t});
		}
	}
//	cerr<<(clock()-bg)*1.00/CLOCKS_PER_SEC<<'\n';
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) dis[i][j] = 1e16;
	for(int i=1;i<=n;i++) dijkstra(i);
//	cerr<<(clock()-bg)*1.00/CLOCKS_PER_SEC<<'\n';
	while(q--)
	{
		int u, v;
		cin>>u>>v;
		u += n, v += n;
		ll ans = 1e18;
		for(auto x : e[u])
		{
			int nu = x.first;
			for(auto x : e[v])
			{
				int nv = x.first;
				ans = min(ans, dis[nu][nv] + ds[nu][u] + ds[nv][v]);
			}
		}
		ans += w[u] + w[v];
		cout<<ans<<'\n';
	}
//	cerr<<(clock()-bg)*1.00/CLOCKS_PER_SEC<<'\n';
	return 0;
}
