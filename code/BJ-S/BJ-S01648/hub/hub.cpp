// Calm down.
// Think TWICE, code ONCE.
#include<bits/stdc++.h>
#define pb push_back
#define popcnt __builtin_popcountll
#define debug printf("Passed line %d\n", __LINE__)

using namespace std;
typedef long long ll;
typedef vector<int> vint;
typedef pair<int, int> PII;

template<typename T> inline void read(T &x){
	x = 0; bool F = 0; char c = getchar();
	for (;!isdigit(c);c = getchar()) if (c == '-') F = 1;
	for (;isdigit(c);c = getchar()) x = x*10+(c^48);
	if (F) x = -x;
}

template<typename T1, typename ...T2> inline void read(T1 &x, T2 &...y){read(x), read(y...);}

template<typename T> inline void checkmax(T &x, const T &y){if (x<y) x = y;}

template<typename T> inline void checkmin(T &x, const T &y){if (x>y) x = y;}

const int N = 4005;
int fa[N], dep[N], d1[N], save[N], n, lim, k;
vint to[N];

void dfs1(int u, int f){
	fa[u] = f;
	for (int v: to[u]) if (v!=f) dfs1(v, u);
}

void dfs3(int u, int f){
	d1[u] = d1[f]+1, save[u] = (d1[u]>k);
	for (int v: to[u]) if (v!=f) dfs3(v, u), save[u] |= save[v];
	// printf("save %d = %d", u, save[u]);
}

void dfs2(int u, int f, int &sum, int &d){
	dep[u] = 0; int x = 0;
	for (int v: to[u]){
		if (v == f) continue;
		dfs2(v, u, sum, d);
		checkmax(dep[u], dep[v]);
		x += save[v];
	}
	dep[u]++;
	if (dep[u]>k){
		sum++;
	}
	if (x>=2) checkmin(d, d1[u]);//, printf("must u %d %d\n", u, d1[u]);
}

inline bool check(int u, int mid){
	k = mid; int s = 0, cnt = 0, val, d;
	d1[0] = -1, dfs3(u, 0);
	for (int v: to[u]){
		val = 0, d = 2*k+1;
		dfs2(v, u, val, d);
		if (v == fa[u]){
			// printf("val %d d %d\n", val, d);
			if (dep[v]>k) s += max(1, val - d + 1);
		}
		else cnt += !!val, s += val;
	}
	// printf("s %d\n", s);
	return (cnt<=1 && s<lim);
}

inline void solve(){
	read(n, lim); int u, v;
	for (int i = 1;i<=n;i++) to[i].clear();
	for (int i = 1;i<n;i++) read(u, v), to[u].pb(v), to[v].pb(u);
	dfs1(1, 0); int ans = n;
	// check(4, 1);
	for (int i = 1;i<=n;i++){
		while (ans && check(i, ans-1)) ans--;
	}
	printf("%d\n", ans);
}

int main(){
	// freopen("input.txt", "r", stdin);
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int c, t; read(c, t);
	while (t--) solve();
	return 0;
}