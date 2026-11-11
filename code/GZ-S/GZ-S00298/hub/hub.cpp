// GZ-S00298 ÓÎ¾°ÖÇ 
#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
typedef long long ll;
int c, T;
int n, k;
vector<int> g[N];
int dep[N];
int p[N];
vector<int> eg[N];
int find(int x){
	if(x != p[x]){
		p[x] = find(p[x]);
	}
	return p[x];
} 
bool vis[N];
int scc_cnt;
void dfs(int u){
	vis[u] = 1;
	eg[scc_cnt].push_back(u);
	for(int j : g[u]){
		if(!vis[j]){
			dfs(j);
		}
	}	
}
int zu[N][20];
void dfs1(int u, int fa){
	zu[u][0] = fa;
	for(int i = 1; i <=  20; i++){
		zu[u][i] = zu[zu[u][i - 1]][i - 1];
	}
	dep[u] = dep[fa] + 1;
	for(int j : g[u]){
		if(j == fa)continue;
		dfs1(j , u);
	}
} 
int LCA(int x, int y){
	if(dep[x] < dep[y]){
		swap(x, y);
	}
	for(int i = 20; i >= 0; i--){
		if(dep[x] - dep[y] >= (1 << i)){
			x = zu[x][i];
		}
	}
	if(x == y){
		return x;
	} 
	for(int i = 20; i >= 0; i--){
		if(zu[x][i] != zu[y][i]){
			x = zu[x][i];
			y = zu[y][i];
		}
	}
	return zu[x][0];
} 
int main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout); 
	scanf("%d%d", &c, &T);
	while(T--){
		ll ans = 1e18;
		for(int i = 1; i <= n; i++){
			g[i].clear();
			p[i] = i;
		}

		scanf("%d%d", &n, &k);
		for(int i = 1; i < n; i++){
			int x, y;
			scanf("%d%d", &x, &y);
			g[x].push_back(y);
			g[y].push_back(x);
		}
		dep[1] = 0;
		dfs1(1, 0);
		for(int msk = 0; msk < (1ll << n); msk++){
			int cnt = 0;
			scc_cnt = 0;		
			for(int i = 1; i <= scc_cnt; i++){
				eg[i].clear();
			}
			vector<int> S; 
			for(int i = 1; i <= n; i++){
				if((msk >> (i - 1)) & 1){
					S.push_back(i), cnt++;
				}
				vis[i] = 0;
			}
			if(cnt != k)continue;
			for(int i = 1; i <= n; i++){
				if(!vis[i]){
					scc_cnt++;
					dfs(i);
				}
			}
			if(scc_cnt > 2)continue; 
			int malen = 1;
			for(int i = 0; i < S.size(); i++){
				for(int j = i + 1; j < S.size(); j++){
					malen = max(malen, dep[S[i]]  + dep[S[j]]  - dep[LCA(S[i], S[j])]);
				} 
			}
			ans = min(ans, (ll)malen); 
		}
		printf("%lld\n", ans); 
	}
	return 0;
} 
