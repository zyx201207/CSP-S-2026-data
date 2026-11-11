#include<bits/stdc++.h> 
#define fi first
#define se second

using namespace std;

typedef vector<int> VI;
typedef pair<int, int> PII;

const int N = 1e6 + 10, INF = 1e9;

int n, k, ea[N], eb[N], dist[2][N], pp[2], p[N];
vector<int> G[N];

void init(){	//TODO;
	for(int i = 1; i <= n; i++) G[i].clear();
	for(int i = 1; i <= n; i++) dist[0][i] = dist[1][i] = 0;
	pp[0] = pp[1] = 0;
}

bool checkA(){
	if(n % 2 == 0) return false;
	int m = (n - 1) / 2;
	for(int i = 1; i <= m; i++) if(ea[i] != i || eb[i] != i + 1) return false;
	for(int i = m + 1; i <= n - 1; i++) if(ea[i] != i - m || eb[i] != i + 1) return false;
	return true;
}

void solve_subA(){
	int m = (n - 1) / 2, mm = m / 2, a = k / 2, b = k / 2 + (k & 1);
	int x = mm - a, y = (m - mm) - b, res = 0;
	res = max((x + 1) / 2 + 1, (y + 1) / 2 + 1);
	cout << res << "\n";
}

void dfs_k2(int u, int pre, int id){
	for(int v : G[u]) if(v != pre){
		dist[id][v] = dist[id][u] + 1, dfs_k2(v, u, id);
		if(dist[id][v] > dist[id][pp[id]]) pp[id] = v;
	}
}

void solve_k2(){
	dfs_k2(1, 0, 0), dfs_k2(pp[0], 0, 1), dfs_k2(pp[1], 0, 0);
//	cout << pp[0] << " " << pp[1] << "\n";
	int mxd = dist[0][pp[1]], dd0 = 0, dd1 = 0;
	for(int i = 1; i <= n; i++){
		if(dist[0][i] < dist[1][i]) dd0 = max(dd0, dist[0][i]);
		else dd1 = max(dd1, dist[1][i]);
	}
	int res = max((dd0 + 1) / 2, (dd1 + 1) / 2);
	cout << res << "\n";
//	cout << (mxd + 3) / 2 << "\n";
}

int find(int x){
	return x == p[x] ? x : p[x] = find(p[x]);
}

void solve_n10(){
	queue<PII> Q;
	int res = INF;
	for(int t = 0; t < (1 << n); t++){
		vector<int> st(n + 1, 0);
		int cntk = 0;
		for(int i = 0; i < n; i++) if((t >> i) & 1) cntk++, st[i + 1] = 1;
		if(cntk != k) continue;
		iota(p + 1, p + n + 1, 1);
//		for(int i = 1; i <= n; i++) cout << p[i] << " ";
//		cout << "\n";
		for(int i = 1; i <= n; i++){
			int a = ea[i], b = eb[i];
			if(!st[a] || !st[b]) continue;
			a = find(a), b = find(b);
			if(a != b) p[a] = b, cntk--;
		}
		if(cntk != 2) continue;
		int mxd = 0;
		for(int i = 1; i <= n; i++){
			while(!Q.empty()) Q.pop();
			Q.push({i, 0});
			while(!Q.empty()){
				int u = Q.front().fi, d = Q.front().se; Q.pop();
				if(st[u]){ mxd = max(mxd, d); break; }
				for(int v : G[u]) Q.push({v, d + 1});
			}
		}
		res = min(res, mxd);
	}
	cout << res << "\n";
}

void solve(){
	init();
	cin >> n >> k;
	for(int i = 1, a, b; i < n; i++){
		cin >> a >> b, ea[i] = a, eb[i] = b;
		G[a].push_back(b), G[b].push_back(a);
	}
	if(k == n) return cout << "0\n", void();
	if(checkA()) return solve_subA(), void();
	if(n <= 10) return solve_n10(), void();
	if(k == 2) return solve_k2(), void();
	dfs_k2(1, 0, 0), dfs_k2(pp[0], 0, 1), dfs_k2(pp[1], 0, 0);
//	cout << pp[0] << " " << pp[1] << "\n";
	int mxd = dist[0][pp[1]], dd0 = 0, dd1 = 0;
	for(int i = 1; i <= n; i++){
		if(dist[0][i] < dist[1][i]) dd0 = max(dd0, dist[0][i]);
		else dd1 = max(dd1, dist[1][i]);
	}
	int res = max((dd0 + 1) / 2, (dd1 + 1) / 2);
	cout << res << "\n";
//	cout << (mxd + 3) / 2 << "\n";
}

int main(){
//	freopen("hub2.in", "r", stdin);
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int T = 1, _;
	cin >> _;
	cin >> T;
	while(T--) solve();
	return 0;
}
