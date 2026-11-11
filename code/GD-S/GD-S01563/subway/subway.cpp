#include<cmath>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
//我被fjz机惨了 
using namespace std;

inline void readi(int &x){
	
	x = 0;register char ch = getchar();
	while(!isdigit(ch))ch = getchar();
	while(isdigit(ch))x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
}

int c, n, m, d, q, qy, qx;
unsigned long long f[667][667];
unsigned long long ans;
struct Edge{
	
	int v;
	unsigned long long w;
};
struct Station{
	
	int cost;
	vector<Edge>line;
}station[501067];
signed main(){
	
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cout.tie(0);
	
	readi(c);
	readi(n);
	readi(m);
	readi(d);
	readi(q);
	
	for(register int i = 1; i < m + 1; ++i){
		
		readi(station[i].cost);
	}
	memset(f, 0x3f, sizeof(f));
	for(register int i = 1; i < n + 1; i++)f[i][i] = 0;
//	cerr<<"g1";
	for(register int i = 1, k; i < n + 1; i++){//1~n线路, 
		
		readi(k);
		for(register int j = 1, v, w; j <= k; j++){
			
			readi(v);
			readi(w);
			station[v].line.push_back({i, w}); 
		}
	}
	
	for(register int i = 1; i <= m; ++i){
		
		vector<Edge>u(station[i].line);
		for(register int j = 1; j < u.size(); ++j){
			
			for(register int k = 0; k < j; ++k){
				
				f[u[k].v][u[j].v] = f[u[j].v][u[k].v] = min(f[u[j].v][u[k].v], u[k].w + u[j].w);
			}
		}
	}
	
	for(register int k = 1; k < n + 1; ++k){//yes floyd
		
		for(register int i = 1; i < n + 1; ++i){
			
			for(register int j = 1; j < n + 1; ++j){
				
				f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
			}
		}
	}
	
	while(q--){
		
		ans = 0x7f7f7f7f7f7f7f7f;
		readi(qx);
		readi(qy);
		
//		< getans >;
		
		vector<Edge>u1(station[qx].line);
		vector<Edge>u2(station[qy].line);
		for(register int i = 0; i < u1.size(); ++i){
			
			for(register int j = 0; j < u2.size(); ++j){
				
				ans = min(f[u1[i].v][u2[j].v] + u1[i].w + u2[j].w, ans);
			}
		}
		cout << ans + station[qx].cost + station[qy].cost << '\n';
	}
	return 0;
}
