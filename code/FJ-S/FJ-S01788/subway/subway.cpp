#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll INF = 2e18;

inline ll qread(){
	ll x = 0, f = 1;
	char c = getchar();
	for(;!isdigit(c);c=getchar()) if(c == '-') f = -1;
	for(;isdigit(c);c=getchar()) x = x*10+c-48;
	return x * f;
}

int c;
ll n, m, d, q;
vector<vector<pair<ll, ll>>> graph;
vector<ll> w;

ll dijkstra(ll s, ll e){
	vector<ll> dist(m+1, INF);
	dist[s] = 0;
	priority_queue<pair<ll, ll>> pq;
	pq.push({0, s});
	while(!pq.empty()){
		auto p = pq.top();
		pq.pop();
		int u = p.second, w = p.first;
		
		if(dist[u] < w) continue;
		
		for(auto p: graph[u]){
			int v = p.first, d = p.second;
			if(dist[v] > dist[u] + d){
				dist[v] = dist[u] + d;
				pq.push({dist[v], v});
			}
		}
	}
	return dist[e] + w[s] + w[e];
}

// O(n*k^2) TLE :(

int main(){
	
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	c = qread();
	n = qread(); m = qread(); d = qread(); q = qread();
	w.resize(m+1, 0);
	for(int i = 1; i<=m; i++) w[i] = qread();
	graph.resize(m+1);
	for(int i = 1; i<=n; i++){
		ll k = qread();
		vector<pair<ll, ll>> tmp(k);
		for(auto &p: tmp) p = {qread(), qread()};
		for(int x = 0; x<k; x++){
			for(int y = 0; y<k; y++){
				int u = tmp[x].first, v = tmp[y].first, w = tmp[x].second + tmp[y].second;
				if(u == v) continue;
				graph[u].push_back({v, w});
				graph[v].push_back({u, w});
			}
		}
	}
	
	while(q--){
		ll x = qread(), y = qread();
		printf("%lld\n", dijkstra(x, y));	
	}
	
	return 0;
}