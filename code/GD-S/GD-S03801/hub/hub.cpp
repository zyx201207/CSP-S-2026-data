#include <cstdio>
#include <vector>
#include <algorithm>
#define N 205
using namespace std;

int C, T, n, k, a, b, i, ans;
vector<int> e[N];
vector<pair<int, int> > f;
bool ab[N];
int dis[N][N], ff[N], cnt[N];
void init(int u, int fa, int rt){
	for(int v:e[u]){
		if(v != fa){
			dis[rt][v] = dis[rt][u] + 1;
			init(v, u, rt);
		}
	}
}
int fnd(int x){
	if(ff[x] == x)	return x;
	return ff[x] = fnd(ff[x]);
}
void dfs(int x, int y){
	if(x > n){
		for(int i=1; i<=n; i++)	ff[i] = i;
		for(auto j:f){
			ff[fnd(j.first)] = fnd(j.second);
		}
		int cb = 0;
		for(int i=1; i<=n; i++){
			cnt[i] = 0;
		}
		for(int i=1; i<=n; i++)	cnt[fnd(i)] = 1;
		for(int i=1; i<=n; i++)	cb += cnt[i];
		if(cb > 2)	return;
		int cc = 0;
		for(int i=1; i<=n; i++){
			if(ab[i])	continue;
			int s = 1e9;
			for(int j=1; j<=n; j++){
				if(ab[j])	s = min(s, dis[i][j]);
			} 
			cc = max(cc, s);
		}
		ans = min(ans, cc);
		return;
	}
}
int main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	scanf("%d%d", &C, &T);
	while(T--){
		ans = 1e9;
		scanf("%d%d", &n, &k);
		f.clear();
		for(i=1; i<n; i++){
			scanf("%d%d", &a, &b);
			e[a].push_back(b), e[b].push_back(a);
			f.push_back({a, b});
		}
		for(i=1; i<=n; i++)	init(i, 0, i);
		dfs(1, 0);
		printf("%d\n", ans);
	}
	return 0;
}
