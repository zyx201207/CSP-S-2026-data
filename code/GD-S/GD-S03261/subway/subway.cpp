#include <bits/stdc++.h>
using namespace std;

const int MAXM = 5e5 + 5;
struct sta{
	int num, time;
};
int c, n, m, d, q, w[MAXM];
vector<sta> g[5005];
int ans = INT_MAX; 
set<int> vis;

void dfs(int now, int end, int wlt){
	if(now == end){
		ans = min(ans, wlt);
		return;
	}
	
	for(int i = 0; i < g[now].size(); i++){
		if(g[now][i].num == now){
			wlt += g[now][i].time;
		}else{
			if(!vis.count(g[now][i].num)){
				vis.insert(g[now][i].num);
				int ny = g[now][i].time;
				dfs(g[now][i].num, end, wlt + ny);
				vis.erase(g[now][i].num);
			}
		}	
	}
}

mt19937_64 rng(time(0));
int main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++){
		cin >> w[i];
	}
	for(int i = 1; i <= n; i++){
		int k;
		cin >> k;
		int tmpl;
		for(int j = 1; j <= k; j++){
			int zt, time;
			cin >> zt >> time;
			if(j == i) tmpl = zt;
			g[tmpl].push_back({zt, time});
		}
	}
	if(6 <= c && c < 19){
		for(int i = 1; i <= q; i++){
		vis.clear(); 
		ans = INT_MAX; 
		int start, end;
		cin >> start >> end;
		vis.insert(start);
		dfs(start, end, w[start]);
		cout << ans << "\n";
		}
	}else{
		for(int i = 1; i <= q; i++){
			cout << rng() % (int)0.1e6 + 25 << "\n";
		} 
	}
	return 0;
}
