#include<bits/stdc++.h>
#define fs first
#define sc second
//#define int long long
using namespace std;

const int N = 1e6 + 5, inf = 1e9 + 7;

int T, c, n, k, bu, bv, s, t, mid, ru, rv, ans;
int dis[N], dep[N], mx[N], fa[N];
vector<int> p[N];
vector<pair<int, int>> e;
priority_queue<pair<int, int>> pq;

int dfs(int u, int v, int w){
	dis[u] = w;
	int maxx = u;
	for(int i : p[u]){
		if(i == v || (u == bu && i == bv) || (u == bv && i == bu)) continue;
		int res = dfs(i, u, w + 1);
		if(dis[maxx] < dis[res]) maxx = res;
	}
	return maxx;
}

bool find_mid(int u, int v){
	if(u == t) return 1;
	for(int i : p[u]){
		if(i == v || (u == bu && i == bv) || (u == bv && i == bu)) continue;
		if(find_mid(i, u) && dis[u] == dis[t] / 2){
			mid = u;
			return 0;
		}
	}
}

void dfs2(int u, int v){
	mx[u] = dep[u];
	fa[u] = v;
	for(int i : p[u]){
		if(i == v || (u == bu && i == bv) || (u == bv && i == bu)) continue;
		dep[i] = dep[u] + 1;
		dfs2(i, u);
		mx[u] = max(mx[u], mx[i]);
	}
}

void push_in(int u){
	if(!pq.empty()) pq.pop();
	for(int i : p[u]){
		if(i == fa[u] || (u == bu && i == bv) || (u == bv && i == bu)) continue;
		pq.push({mx[i] - dep[u], i});
	}
}

signed main(){
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	
	cin >> c >> T;
	while(T--){
		
		cin >> n >> k;
		e.clear();
		for(int i = 1;i <= n;i++) p[i].clear();
		for(int i = 1;i < n;i++){
			int u, v;
			cin >> u >> v;
			p[u].push_back(v);
			p[v].push_back(u);
			e.push_back({u, v});
		}
		
		if(k == 1){
			s = dfs(1, 0, 0);
			t = dfs(s, 0, 0);
			cout << (dis[t] / 2 + (dis[t] & 1)) << "\n"; 
			continue;
		}
		
		ans = inf;
		for(auto i : e){
			
			for(int i = 1;i <= n;i++) fa[i] = dep[i] = 0;
			while(!pq.empty()) pq.pop();
			
			bu = i.fs; bv = i.sc;
			
			s = dfs(bu, 0, 0);
			t = dfs(s, 0, 0);
			find_mid(s, 0);
			ru = mid;
			dfs2(ru, 0);
			push_in(ru);
			
			s = dfs(bv, 0, 0);
			t = dfs(s, 0, 0);
			find_mid(s, 0);
			rv = mid;
			dfs2(rv, 0);
			push_in(rv);
			
			if(pq.empty()){
				ans = 0;
				break;
			}
			
			int tk = k - 2;
			while(tk > 0){
				if(pq.empty()){
					ans = 0;
					break;
				}
				tk--;
				push_in(pq.top().sc);
			}
			
			if(pq.empty()) break;
			else ans = min(ans, pq.top().fs);
			
		}
		
		cout << ans << "\n";
		
	}
	
	return 0;
	
}
