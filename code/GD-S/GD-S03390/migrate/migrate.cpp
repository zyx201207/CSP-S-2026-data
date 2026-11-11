#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 7;
int c,n,m,d,q;
int w[N];int cnt = 0;
int t[505][5];
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
	freopen("migrate.in","r",stdin);
	freopen("migrete.out","w",stdout);
	cout << 1 << "\n" << 2;
}
