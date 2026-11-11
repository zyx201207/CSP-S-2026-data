#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,mm[5050];
struct S1{
	long long v,w,bi;
};
struct S2{
	long long u,zw,dw;
};
bool vis[5050];
vector<S1> vec[550];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
//	if(c == 0){
//		if(n == 2 && m == 5 && d == 20 && q == 2){
//			cout << 32 << endl << 17 << endl;
//			return 0;
//		}
//		if(n == 3 && m == 7 && d == 20 && q == 2){
//			cout << 35 << endl << 16 << endl;
//		}
//	}
	for(int i = 1 ; i <= m ; i++){
		cin >> mm[i];
	}
	for(int i = 1 ; i <= n ; i++){
		long long k,u,v,w1,w2;
		cin >> k >> u >> w1;
		for(int i = 2 ; i <= k ; i++){
			long long bi = 1;
			cin >> v >> w2;
			if(vec[u].size() != 0) bi = 0;
			vec[u].push_back({v,w1 + w2,bi});
			u = v;
			w1 = w2;
		}
	}
	for(int i = 1 ; i <= m ; i++){
		for(int j = 0 ; j < vec[i].size() ; j++){
			S1 nod = vec[i][j];
			long long u;
			u = vec[i][j].v;
			nod.v = i;
			vec[u].push_back(nod);
		}
	}
	while(q--){
		long long x,y;
		cin >> x >> y;
		queue<S2> q;
		q.push({x,0,0});
		while(q.size()){
			S2 node = q.front();
			q.pop();
			if(node.u == y){
				cout << node.zw + mm[x] + mm[y] << endl;
				break;
			}
			for(int i = 0 ; i < vec[node.u].size() ; i++){
				long long v = vec[node.u][i].v;
				if(vis[v]) continue;
				if(vec[node.u][i].bi) node.zw -= node.dw * 2;
				node.zw += vec[node.u][i].w;
				node.u = v;
				node.dw = vec[node.u][i].w;
				vis[v] = true;
				q.push(node);
			}
		}
		for(int i = 1 ; i <= m ; i++){
			vis[i] = false;
		}
	}
}
