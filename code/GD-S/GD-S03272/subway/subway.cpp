#include <bits/stdc++.h>
#define int long long
#define N 505
#define M 500005
#define INF 1000000000000
using namespace std;
//n是路线,m是点数 

int c,n,m,d,q;
int w[M];
int mindist[M];
int aa[M],at[M];

map<int,int> ma[2]; 

struct Node{
	int v,w;
}; 
vector<Node> g[M]; 

void bfs(int s,int t){
	mindist[s] = 0;
	queue<Node> q;
	q.push({s,0});
	while (q.size()){
		int u = q.front().v;
		int w = q.front().w;
		q.pop();
		
		if (u == t) continue;
		
		if (w > mindist[u]) continue;
		for (int i=0;i<g[u].size();++i){
			int v = g[u][i].v;
			int new_w = w + g[u][i].w;
			if (new_w >= mindist[v]) continue;
			q.push({v,new_w});
			mindist[v] = new_w; 
		}
	}
}
	

signed main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i=1;i<=m;++i) cin >> w[i];
	
	
	if (c <= 15){ 
		for (int i=1;i<=n;++i){
			int k; cin >> k;
			for (int j=1;j<=k;++j) cin >> aa[j] >> at[j];
			for (int x=1;x<=k;++x){
				for (int y=x+1;y<=k;++y){
					g[aa[x]].push_back({aa[y],at[x]+at[y]});
					g[aa[y]].push_back({aa[x],at[x]+at[y]});
				}
			}
		}
		
		
		
		while (q--){
			for (int i=1;i<=m;++i) mindist[i] = INF;
			
			int u,v; cin >> u >> v;
			bfs(u,v);
			cout << w[u] + w[v] + mindist[v] << '\n';
		}
	}
	else if (c == 20 || c == 21){
		vector<int> zai[2];
		for (int i=0;i<n;++i){
			int k; cin >> k;
			for (int j=1;j<=k;++j){
				int a,t; cin >> a >> t;
				ma[i][a] = t;
				zai[i].push_back(a);
			}
		}
		while (q--){
			int u,v; cin >> u >> v;
			int ans = INF;
			if (ma[0].find(u) != ma[0].end() && ma[0].find(v) != ma[0].end()) ans = min(ans,ma[0][u]+ma[0][v]);
			if (ma[1].find(u) != ma[1].end() && ma[1].find(v) != ma[1].end()) ans = min(ans,ma[1][u]+ma[1][v]);
			
			
			for (int i=0;i<zai[0].size();++i){
				int x = zai[0][i];
				if (ma[1].find(x) != ma[1].end()){
					if (ma[0].find(u) != ma[0].end() && ma[1].find(v) != ma[1].end()) ans = min(ans,ma[0][u]+ma[0][x]+ma[1][x]+ma[1][v]);
					if (ma[1].find(u) != ma[1].end() && ma[0].find(v) != ma[0].end()) ans = min(ans,ma[1][u]+ma[1][x]+ma[0][x]+ma[0][v]);
				}
			}
			ans += w[u] + w[v];
			cout << ans << '\n';
		}
	}
	
	
	
	return 0;
}




