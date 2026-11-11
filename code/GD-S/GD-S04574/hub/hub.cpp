#include <bits/stdc++.h>
using namespace std;

const int MXN = 1e6;
const int INF = 0x3f3f3f3f;

int c, t, n, k, ns;
vector< int > g[MXN];
int x[MXN], tp, dia[MXN], dst[MXN], s, e, q[MXN], dtp, d[MXN], L[MXN], R[MXN], resf[MXN], resg[MXN], add;
bool removed[MXN];

int read(){
	int x = 0;
	char c = getchar();
	for(;c < '0' || c > '9';) c = getchar();
	for(;c >= '0' && c <= '9';c = getchar()) x = (x << 1) + (x << 3) + (c ^ 48);
	return x;
}

void bfs(int x){
	int i;
	for(i = 0;i < n;++i) dst[i] = INF;
	dst[x] = 0;
	q[s = e = 0] = x;
	for(;s <= e;){
		int u = q[s++];
		for(auto v : g[u])
			if(!removed[v] && dst[v] == INF){
				dst[v] = dst[u] + 1;
				q[++e] = v;
			}
	}
}

void fnd_dia(int x){
	int i;
	bfs(x);
	int a = x;
	for(i = 0;i < n;++i){
		if(dst[i] == INF) continue;
		if(dst[i] > dst[a]) a = i;
	}
	bfs(a);
	int b = a;
	for(i = 0;i < n;++i){
		if(dst[i] == INF) continue;
		if(b == -1 || dst[i] > dst[b]) b = i;
	}
	tp = 0;
	dia[tp++] = b;
	for(;b != a;)
		for(auto u : g[b])
			if(dst[u] == dst[b] - 1){
				b = u;
				dia[tp++] = b;
				break;
			}
}

int dfs(int u, int fa, int x){
	int dep = 0;
	for(auto v : g[u])
		if(!removed[v] && v != fa) dep = max(dep, dfs(v, u, x) + 1);
	if(dep >= x) ++add;
	return dep;
}

bool chck(int x){
	int i;
	int res = INF;
	add = 0;
	for(i = 0;i < tp;++i){
		int dep = dfs(dia[i], -1, x);
		if(dep < x){
			L[i] = i - (x - dep);
			R[i] = i + (x - dep);
		}
		else{
			L[i] = INF;
			--add;
		}
	}
	int lft = INF, rght = -INF;
	for(i = 0;i < tp;++i){
		if(L[i] == INF){
			lft = min(lft, i);
			rght = max(rght, i);
		}
		else{
			lft = min(lft, R[i]);
			rght = max(rght, L[i]);
		}
		resf[i] = max(rght - lft + 1, 1);
	}
	lft = INF;
	rght = -INF;
	for(i = tp - 1;i >= 0;--i){
		if(L[i] == INF){
			lft = min(lft, i);
			rght = max(rght, i);
		}
		else{
			lft = min(lft, R[i]);
			rght = max(rght, L[i]);
		}
		resg[i] = max(rght - lft + 1, 1);
	}
	for(i = 0;i + 1 < tp;++i) res = min(res, resf[i] + resg[i + 1]);
	return res + add <= k;
}

int dfs1(int u, int fa){
	int dep = 0;
	for(auto v : g[u])
		if(!removed[v] && v != fa) dep = max(dep, dfs1(v, u) + 1);
	if(~fa) d[dtp++] = dep;
	return dep;
}

void work(int x, int y){
	dtp = 0;
	removed[x] = 1;
	fnd_dia(y);
	int md = dia[tp >> 1];
	dfs1(md, -1);
	removed[x] = 0;
	removed[y] = 1;
	fnd_dia(x);
	md = dia[tp >> 1];
	dfs1(md, -1);
	removed[y] = 0;
	sort(d, d + dtp, greater< int >());
	ns = min(ns, d[k]);
}

int main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int i, l, r, md;
	c = read();
	for(t = read();t;--t){
		n = read();
		k = read();
		for(i = 0;i < n;++i) g[i].clear();
		for(i = 1;i < n;++i){
			int u = read() - 1, v = read() - 1;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		if(k == n){
			puts("0");
			continue;
		}
		ns = INF;
		if(c <= 10){
			k -= 2;
			for(i = 0;i < n;++i)
				for(auto u : g[i])
					if(i < u) work(i, u);
			printf("%d\n", ns + 1);
		}
		else{
			fnd_dia(0);
			for(i = 0;i < tp;++i) removed[dia[i]] = 1;
			for(l = 0, r = n - 1;l <= r;){
				md = l + r >> 1;
				if(chck(md)) r = md - 1;
				else l = md + 1;
			}
			printf("%d\n", l);
		}
		for(i = 0;i < n;++i) removed[i] = 0;
	}
	return 0; 
}
