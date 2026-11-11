#include<bits/stdc++.h>
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;

// hub
const int N_1 = 30, inf = 1e9;
vector<int> g_1[N_1];
bool vis_1[N_1];
int a_1[N_1]; 
void dfs_2(int u, int fa){
	if(!a_1[u]){
		return ;
	}
	vis_1[u] = 1;
	for(auto x : g_1[u]){
		if(x != fa) dfs_2(x, u);
	} 
}
int dis_1[N_1][N_1];
int get_dis(int u, int t){
	return dis_1[u][t]; 
}
void dfs_1(int s, int u, int fa, int dep){
	dis_1[s][u] = dep;
	for(auto x : g_1[u]){
		if(x != fa){
			dfs_1(s, x, u, dep + 1); 
		}
	}
}
void sol_1(){
	int n, k; cin >> n >> k;
	for(int i = 1; i <= n; i ++){
		g_1[i].clear();
	}
	for(int i = 1; i < n; i ++){
		int u, v; cin >> u >> v;
		g_1[u].push_back(v);
		g_1[v].push_back(u);
	}
	for(int i = 1; i <= n; i ++){
		dfs_1(i, i, 0, 0);
	}
	int ans = inf;
	for(int i = 1; i < (1 << n) - 1; i ++){
		vector<int> v, v_1; 
		int ccnt = 0;
		for(int j = 1; j <= n; j ++){
			a_1[j] = (i >> (j - 1)) & 1;
			if(a_1[j]) v.push_back(j);
			else v_1.push_back(j);
			ccnt += a_1[j];
		}
		if(ccnt != k) continue;
		int cnt = 0;
		for(int j = 1; j <= n; j ++){
			if(!vis_1[j] && a_1[j]){
				dfs_2(j, 0);
				cnt ++;
			}
		}
		for(int j = 1; j <= n; j ++){
			vis_1[j] = 0; 
		}
		if(cnt > 2) continue;
		int mx = 0;
		for(auto j : v_1){
			int mn = inf;
			for(auto k : v){
				mn = min(mn, get_dis(j, k));
			}
			mx = max(mx, mn);
		}
		ans = min(ans, mx);
//		cout << ans;
//		return ;
	}
	cout << ans << '\n';
}
int main(){
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	freopen("hub.in", "r", stdin); 
	freopen("hub.out", "w", stdout); 
	int c, t; cin >> c >> t;
	while(t --){
		sol_1();	
	}
	return 0;
} 
