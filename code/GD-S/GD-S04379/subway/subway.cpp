#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 5;

int w[N], l, r, nw = 0x3f3f3f3f;
struct node{
	int id, t;
};
vector<node> k[N];
vector<node> z[N]; 

void dfs(int x, int zd, int pd, int sj, int tp){//pd:1在站找线,pd:2在线去站 
	if(zd == r){
//		cout << pd << '\n' << sj << '\n' << tp << '\n';
		nw = min(nw, sj + tp);
		return;
	}
	if(pd == 1){
//		cout << "yes";
		for(auto u: z[zd]){
			if(u.id == x) continue;
			dfs(u.id, zd, 2, sj + u.t + tp, u.t);
		}
	}
	if(pd == 2){
//		cout << "yes";
		for(auto u: k[x]){
			if(u.id == zd) continue;
//			cout << x << '\n' << u.t << '\n';
//			cout <<"---";
//			for(auto v: k[x]){
//				cout << v.id  << " "<< v.t << '\n';
//			}
//			cout << "---";
			dfs(x, u.id, 1, sj, u.t);
		}
	}
}

signed main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++){
		cin >> w[i];
	}
	for(int i = 1; i <= n; i++){
		int p;
		cin >> p;
		for(int j = 1; j <= p; j++){
			int x, y;
			cin >> x >> y;
			k[j].push_back({x, y});
			z[x].push_back({j, y});
		}
	}
	while(q--){
		cin >> l >> r;
		nw = 0x3f3f3f3f;
		for(auto u: z[l]){
			dfs(u.id, l, 2, u.t, u.t);
			for(auto v: k[u.id]){
				if(v.id == r){
					nw = min(nw, u.t + v.t);
				}
			}
		}
		cout << w[l] + w[r] + nw << '\n';
	}
	return 0;
} 
