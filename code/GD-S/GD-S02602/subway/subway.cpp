#include<bits/stdc++.h>
#define pii pair<int, int>
#define fi first
#define se second
#define ll long long
using namespace std;

// subway


const int N = 5e2 + 10, M = 5e5 + 10;
const ll inf = 1e18;
ll w[M], tot, idx;
struct node {
	ll v, w;
	bool operator<(const node &x)const{
		return w > x.w;
	} 
};
vector<node> g[M << 1];
void add(int u, int v, int w){
	g[u].push_back({v, w});
//	if(u == 57 || v == 57 || u == 199 || v == 199) 
//	cout << u << ' ' << v << ' ' << w << endl;
}
ll dis[M << 1];

void dij(int s, int t){
	priority_queue<node> q;
	q.push({s, 0});
	for(int i = 1; i <= idx; i ++){
		dis[i] = inf;
	}
	dis[s] = 0;
	while(q.size()){
		node u = q.top();
		q.pop();
		if(u.v == t){
			cout << w[s] + w[t] + dis[u.v] << '\n';
			return ;
		}
		if(dis[u.v] != u.w){
			continue;
		}
		for(auto x : g[u.v]){
//			cout << x.v << ' ' << x.w << ' ' << u.w << ' ' << dis[x.v] << endl;
			if(dis[x.v] > u.w + x.w){
				dis[x.v] = u.w + x.w;
				q.push({x.v, dis[x.v]});
			}
		}
	}
//	cout << '\n';
} 
int main(){
//	freopen("1.in", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
//	freopen("1.ans", "w", stdout); 
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i ++){
		cin >> w[i];
	}
	tot = 0, idx = m;
	for(int i = 1; i <= n; i ++){
		int k, lst; cin >> k;
		tot += k;
		for(int j = 1; j <= k; j ++){
			int a, t; cin >> a >> t;
			++idx;
			add(idx, a, t);
			add(a, idx, t);
			if(j > 1){
//				if(idx == 199) cout << lst << endl;
				add(lst, idx, 0); 
				add(idx, lst, 0); 
			}
//			if(a == 57) cout << idx << endl;
			lst = idx;
		}
	}
	while(q --){
		int s, t; cin >> s >> t;
		dij(s, t);
	}
	
	return 0;
} 
