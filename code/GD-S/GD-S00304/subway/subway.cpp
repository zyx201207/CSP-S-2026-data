#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e2 + 5;
const int M = 5e5 + 5;
int n, m, p, x, y, minn, w[M], d[N][N];
struct node{
	int a;
	int t;
};
vector<node> G[N];
vector<node> id[M];
signed main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%lld", &n);
	scanf("%lld", &n);
	scanf("%lld", &m);
	scanf("%lld", &p);
	scanf("%lld", &p);
	for (int i = 1; i <= m; i++){
		scanf("%lld", &w[i]);
	}
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			if (i != j) d[i][j] = 1e18;
		}
	}
	for (int i = 1; i <= n; i++){
		int k;
		cin >> k;
		for (int j = 1; j <= k; j++){
			int l, x;
			scanf("%lld", &l);
			scanf("%lld", &x);
			G[i].push_back({l, x});
			id[l].push_back({i, x});
			for (node l : id[l]){
				int v = l.a;
				int w = l.t;
				d[i][v] = min(d[i][v], x + w);
				d[v][i] = d[i][v];
			}
		}
	}
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			for (int k = 1; k <= n; k++){
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
				d[j][i] = d[i][j];
			}
		}
	}
	while (p--){
		scanf("%lld", &x);
		scanf("%lld", &y);
		minn = 1e18;
		for (node xx : id[x]){
			for (node yy : id[y]){
				int u = xx.a;
				int v = yy.a;
				int uw = xx.t;
				int vw = yy.t;
				if (d[u][v] == 1e18) continue;
				minn = min(minn, d[u][v] + uw + vw);
			}
		}
		printf("%lld\n", minn + w[x] + w[y]);
	}
	return 0;
}
