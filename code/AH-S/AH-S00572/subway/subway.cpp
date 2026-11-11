#include<bits/stdc++.h>
using namespace std;
const int N = 505, M = 5e5 + 505, Q = 1e5 + 10;

struct node{
	int to;
	long long w;
	friend bool operator < (node a, node b){
		return a.w > b.w;
	}
};

struct input{
	int l, r;
	int i;
}inp[Q];

bool cmp(input a, input b){
	return a.l < b.l;
}

long long out[Q];

int c, n, m, d, q;
int w[M];
long long dis[M];
bool vis[M];
vector<node> adj[M];
priority_queue<node> qu;

void dijkstra(int s){
	while(!qu.empty()) qu.pop();
	memset(dis, 0x3f3f, sizeof dis);
	memset(vis, 0, sizeof vis);
	qu.push({s, 0});
	dis[s] = 0;
	while(!qu.empty()){
		node h = qu.top();
		qu.pop();
		int u = h.to;
		if(vis[u]) continue;
		vis[u] = 1;
		long long d = h.w;
		for(auto nxt : adj[u]){
			int v = nxt.to;
			long long w = nxt.w;
			if(w + d < dis[v]){
				dis[v] = w + d;
				if(!vis[v])
					qu.push({v, dis[v]});
			}
		}
	}
}

int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
	for(int i = 1; i <= m; ++i)
		scanf("%d", w + i);
	
	for(int i = 1; i <= n; ++i){
		int k;
		scanf("%d", &k);
		for(int j = 1; j <= k; ++j){
			int a, t;
			scanf("%d%d", &a, &t);
			adj[i + m].push_back({a, t});
			adj[a].push_back((node){i + m, t});
		}
	}
	
	for(int i = 1; i <= q; ++i){
		scanf("%d%d", &inp[i].l, &inp[i].r);
		inp[i].i = i;
	}
	sort(inp + 1, inp + 1 + q, cmp);
	for(int i = 1; i <= q; ++i){
		if(inp[i].l != inp[i - 1].l)
			dijkstra(inp[i].l);
		out[inp[i].i] = dis[inp[i].r] + w[inp[i].l] + w[inp[i].r];
	}
	for(int i = 1; i <= q; ++i)
		printf("%lld\n", out[i]);
	return 0;
}
