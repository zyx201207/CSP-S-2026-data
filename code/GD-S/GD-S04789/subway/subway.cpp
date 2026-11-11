#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int maxn = 5e5+5;

int c, n, m, d, q, w[maxn], k[maxn], a[maxn], t[maxn], x, y, head = 1, tail = 0;


struct edge{
	int u, w;
};

struct node{
	int fa, v, w;
}que[maxn];

vector<edge> V[2*maxn];

int dij(int k){
	tail = 0, head = 1;
	int res = 1e9+5;
	bool vis[2*maxn] = {};
	que[++tail] = {0, k, w[k]};
	vis[k] = 1;
	while(head <= tail){
		auto now = que[head++];
		
//		cout << now.fa << " " << now.v << " " << now.w << "\n";
		
		if(now.v == y){
			res = min(res, now.w + w[y]);
			continue;
		}
		
		for(auto v : V[now.v]){
			if(v.u == now.fa) continue;
			if(vis[v.u]) continue;
			vis[v.u] = 1;
			que[++tail] = {now.v, v.u, now.w + v.w};
		}
		sort(que+head, que+tail+1, [](node l, node r){
			return l.w < r.w;
		});
	}
	return res;
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	freopen("subway5.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	cin >> c >> n >> m >> d >> q;
	
	for(int i = 1; i <= m; i++){
		cin >> w[i];
	}
	for(int i = 1; i <= n; i++){
		cin >> k[i];
		for(int j = 1; j <= k[i]; j++){
			cin >> a[j] >> t[j];
			V[a[j]].push_back({i + m, t[j]});
			V[i + m].push_back({a[j], t[j]});
		}
	}
	while(q--){
		cin >> x >> y;
		cout << dij(x) << "\n";
		
	}
	return 0;
}

