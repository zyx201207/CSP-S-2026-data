#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e3 + 5;
const int LOG = 20;
vector<int> g[maxn];
int depth[maxn];
int f[maxn][LOG];
bool vis[maxn];
int d[maxn];

void dfs(int u,set<int>& chose){
	vis[u] = true;
	for(int i = 0;i<g[u].size();i++){
		int v =g[u][i];
		if(vis[v]) continue;
		if(chose.find(v) == chose.end()) continue;
		dfs(v , chose);
	}
}

bool check(const vector<int>& chose){
	memset(vis , false , sizeof(vis));
	set<int> tmpchose;
	for(int i = 0;i<chose.size();i++){
		tmpchose.insert(chose[i]);
	}
	int cnt = 0;
	for(int i = 0;i<chose.size();i++){
		if(!vis[chose[i]]){
			if(cnt == 2){
				cnt ++;
				break;
			}
			dfs(chose[i] , tmpchose);
			cnt ++;
		}
		
	}
	return cnt <= 2;
	
}

void fdfs(int u,int fa){
	depth[u] = depth[fa] + 1;
	f[u][0] = fa;
	for(int i = 1;i<LOG;i++){
		f[u][i] = f[f[u][i-1]][i-1];
	}
	for(int i = 0;i<g[u].size();i++){
		int v = g[u][i];
		if(v == fa) continue;
		fdfs(v , u);
	}
}

int lca(int u,int v){
	if(depth[u] < depth[v]) swap(u,v);
	//depth[u] > depth[v]
	for(int i = LOG -1;i>=0;i--){
		if(depth[f[u][i]] >= depth[v]) u =f[u][i];
	}
	if(u == v) return u;
	for(int i = LOG - 1;i>=0;i--){
		if(f[u][i] != f[v][i]){
			u = f[u][i];
			v = f[v][i];
		}
	}
	return f[u][0];
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("hub.in" , "r" , stdin);
	freopen("hub.out" , "w" , stdout);
	int c,t;
	cin >> c >> t;
	while(t--){
		int n , k; //城市数量 ， 基地数量 
		cin >> n >> k;
		for(int i = 1;i<=n-1;i++){
			int u,v;
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		fdfs(1 ,1);
		
		long long sum = 0; //暴力计算dsum
		for(int i = 1;i<=n;i++){
			for(int j = 1;j<=n;j++){
				d[i] = max(d[i] , depth[i] + depth[j] - 2*depth[lca(i,j)]);
			}
			sum += d[i];
		} 
		
		long long ans = 0x3f3f3f3f3f3f3f3f;
		for(int mask = 0;mask < (1LL << 10);mask ++){
			//暴力计算 
			vector<int> chose;
			for(int i = 0;i<min(10,n);i++){
				if(mask & (1LL << i)){
					chose.push_back(i+1);
				}
			}
			if(chose.size() > k) continue;
			if(!check(chose)) continue;
			long long res =sum;
			for(int i = 0;i<chose.size();i++){
				res -= d[i];
			}
			ans = min(ans , res);
		}
		cout << ans << endl;
		for(int i = 0;i<=n;i++){
			for(int j = 0;j<LOG;j++){
				f[i][j] = 0;
			}
			depth[i] = 0;
			g[i].clear();
		}
	}
	return 0;
}
