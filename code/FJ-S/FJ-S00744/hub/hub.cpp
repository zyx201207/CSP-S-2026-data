#include <bits/stdc++.h>
using namespace std;
#define two second
#define one first
#define mp(a,b) make_pair((a),(b))
typedef long long ll;
typedef pair<int, int> pii;
const int maxn = 1e6 + 1;

int n, k;
int head[maxn];
pii edge[maxn<<1];//nxt,to
void add_edge(int u, int v){
	edge[++head[0]] = mp(head[u], v);
	head[u] = head[0];
}

int fa[maxn][20], dep[maxn], ans;
void dfs(int x, int f){
	fa[x][0] = f;
	dep[x] = dep[f] + 1;
	ans = max(ans, dep[x]);
	for(int i = 1; (1<<i) <= dep[x]; i++)
		fa[x][i] = fa[fa[x][i - 1]][i - 1];
	for(int i = head[x]; i; i = edge[i].one){
		if(edge[i].two == f) continue;
		dfs(edge[i].one, x);
	}
}
int lca(int x, int y){
	if(dep[x] < dep[y]) swap(x, y);
	for(int i = log2(dep[x] - dep[y]); i >= 0; i--){
		if(dep[fa[x][i]] >= dep[y])
			x = fa[x][i];
	}if(x == y) return y;
	for(int i = log2(dep[x]); i >= 0; i--){
		if(fa[x][i] != fa[y][i]){
			x = fa[x][i];
			y = fa[y][i];
		}
	}return fa[x][0];
}
bool check(int x){
	if(x < 0) return false;
	vector<int>c;
	return 1;
}

int main(){
	freopen("hub.in", "r", stdin); freopen("hub.out", "w", stdout);
	int c, t; scanf("%d%d", &c, &t);
	while(t--){
		head[0] = ans = 0;
		scanf("%d%d", &n, &k);
		for(int i = 1, u, v; i < n; i++){
			scanf("%d%d", &u, &v);
			add_edge(u, v);
			add_edge(v, u);
		}dfs(1, 0);
		if(k == n){printf("0\n"); continue;}
		if(k == n - 1){printf("1\n"); continue;}
		for(int i = 20; i >= 0; i--)
			if(check(ans - (1<<i)))
				ans -= (1<<i);
		printf("%d\n", ans);
	}return 0;
}
