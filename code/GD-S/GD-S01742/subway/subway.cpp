#include<bits/stdc++.h>
using namespace std;

int c, n, m, d, q, w[500001], a[501][20001], k[501], t[501][20001];
long long f[500001];
vector<int> e[501], e1[500001];

void dfs(int i){
	for(auto x : e1[i]){
		for(auto y : e[x]){
			if(f[y] > f[i] + t[x][i] + t[x][y]){
				f[y] = f[i] + t[x][i] + t[x][y];
				dfs(y);
			}
		}
	}
}
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
	for(int i = 1; i <= m; i++)
		scanf("%d", &w[i]);
	for(int i = 1; i <= n; i++){
		scanf("%d", &k[i]);
		for(int j = 1; j <= k[i]; j++){
			scanf("%d", &a[i][j]);
			scanf("%d", &t[i][a[i][j]]);
			e[i].push_back(a[i][j]);
			e1[a[i][j]].push_back(i);
		}
	}
	for( ; q--; ){
		int s, t;
		scanf("%d%d", &s, &t);
		for(int i = 1; i <= m; i++)
			f[i] = 1e18;
		f[s] = 0;
		dfs(s);
		printf("%lld\n", f[t] + w[s] + w[t]);
	}
	return 0;
}
