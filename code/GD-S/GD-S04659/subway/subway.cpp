#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,m,c,d,q;
int w[N],pr[25];
vector <int>t[N];
vector <int>a[N];
//void dfs(int x,int y,int o) {
	//pr[o] += 
//	for(auto u : a[x]) {
//		dfs(u,y);
//	}
//}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1; i<=m; i++) cin>>w[i];
	for(int i=1; i<=d; i++) {
		for(int j=1; j<=i; j++) {
			int x,y;
			cin>>x>>y;
			a[i].push_back(x);
			t[i].push_back(y);
		}
	}
	for(int i=1; i<=q; i++) {
		int x,y;
		cin>>x>>y;
		/*queue <int> qu;
		qu.push(x);
		while(!q.empty()){
			if(u==y)
			int u = qu.front();
			qu.pop();
			for(auto v : a[u]){
				qu.push(v);
			}
		}
		}*/
	}
}
