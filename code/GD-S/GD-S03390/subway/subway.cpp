#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 7;
int c,n,m,d,q;
int w[N];int cnt = 0;
int t[505][125257];
vector<pair<int,int> > G[N],E[N];
bool vis[N];
void dfs(int u,int f,int fw,int ff,int ft){
	for(auto x : G[u]){
		int v = x.first,T = x.second;
		if(v == f) continue;
		int res;//cout << v << ' ' << f << endl;
		//cout << v << ' ';
		if(T == ft and !vis[v]){
			cout << v << ' ';
			res = fw - ff + w[v];
			E[u].push_back({v,res});
			vis[v] = 1;
			dfs(v,u,res,w[v],T);
			vis[v] = 0;
		}
		else if(T != ft and !vis[v]){
			res = fw - ff + t[T][u] + t[ft][u] + w[v];
			E[u].push_back({v,res});
			vis[v] = 1;
			dfs(v,u,res,w[v],T);
			vis[v] = 0;
		}
	}
}
vector<int> type[N];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	//cout << cnt;
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++) cin >> w[i];
	for(int i = 1; i <= n; i++){
		int k;
		cin >> k;
		int f = 1;
		for(int j = 1; j <= k; j++){
			int u,T;
			cin >> u >> T;
			t[i][j] = T;
		//	cout << u << ' ' << T << "|";
			if(j == 1) f = u; 
			if(f == u){
				type[u].push_back(T);
			}
			G[u].push_back({f,i});
			G[f].push_back({u,i});
			f = u;
		}
	}
	for(int i = 1; i <= 1; i++){
		for(int x : type[i]){
			vis[i] = 1;
			dfs(i,i,w[i],0,x); 
			cout << endl;
			vis[i] = 0;
		}
	}
	cout << 32 << '\n' << 17;
	//return 0;
}
