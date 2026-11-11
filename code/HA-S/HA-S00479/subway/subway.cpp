#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> PII;

ll c, n, m, d, q;
ll w[500010];
vector<PII> g[500010];

ll dis[500010];
bool mk[500010];

void dij(ll s){
	priority_queue<PII, vector<PII>, greater<PII> > q;
	q.push({0, s});
	dis[s] = 0;
	while(q.size()){
		auto d = q.top().first, u = q.top().second; q.pop();
		if(mk[u]) continue;
		mk[u] = 1;
		
		for(auto i = 0; i < g[u].size(); i ++){
			ll v = g[u][i].first, w = g[u][i].second;
			if(dis[v] > dis[u] + w){
				dis[v] = dis[u] + w;
				q.push({dis[v], v});
			}
		}
	}
}

int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> c >> n >> m >> d >> q;
	for(ll i = 1; i <= m; i ++) cin >> w[i];
	for(ll i = 1; i <= n; i ++){
		ll k; cin >> k;
		for(ll j = 1; j <= k; j ++){
			ll u, w; cin >> u >> w;
			g[u].push_back({m + i, w});
			g[m + i].push_back({u, w});
		}
	}
	
	if(c >= 12 && c <= 19){
		while(q --){
			ll a, b;
			cin >> a >> b;
			memset(mk, 0, sizeof mk);
			memset(dis, 0x3f, sizeof dis);
			
			queue<ll> q;
			q.push(a);
			mk[a] = 1;
			dis[a] = 0;
			while(q.size()){
				ll u = q.front(); q.pop();
				for(auto i = 0; i < g[u].size(); i ++){
					ll v = g[u][i].first, w = g[u][i].second;
					if(mk[v]) continue;
					mk[v] = 1;
					if(dis[v] > dis[u] + w){
						dis[v] = dis[u] + w;
						q.push(v);
					}
				}
			}
			
			printf("%d\n", dis[b] + w[a] + w[b]);
			
		}
		return 0;
	}
	
	while(q --){
		ll a, b;
		cin >> a >> b;
		
		memset(dis, 0x3f, sizeof dis);
		memset(mk, 0, sizeof mk);
		dij(a);
		
		printf("%d\n", dis[b] + w[a] + w[b]);
	}
	
	return 0;
}
