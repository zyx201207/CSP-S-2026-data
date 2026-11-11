#include<cstring>
#include<iostream>
#define int long long
const int N = 500 + 5;
const int M = 5e5 + 5;
const int E = M * 20;
int c,n,m,d,q,f[N][N],hdm[M],hdn[N],totn,totm,a[M];
struct node {
	int v,w,nxt;
} gm[E],gn[E];
inline void in(int & n) {
	int res = 0;
	char ch = getchar();
	while(ch < '0' || ch > '9') ch = getchar();
	while('0' <= ch && ch <= '9') res = res * 10 + ch - '0',ch = getchar();
	n = res;
}
inline void out(int x) {
	if(x > 10) out(x / 10);
	putchar(x % 10 + '0');
}
inline int Min(int &a,int b) {
	if(a > b) a = b;
	return a;
}
inline void Floyd() {
	for(int i = 1; i <= n; i ++)
		f[i][i] = 0;
	for(int i = 1; i <= m; i ++)
		for(int it1 = hdm[i]; it1 != -1; it1 = gm[it1].nxt)
			for(int it2 = hdm[i]; it2 != it1; it2 = gm[it2].nxt)
				Min(f[gm[it1].v][gm[it2].v],Min(f[gm[it2].v][gm[it1].v],gm[it1].w + gm[it2].w));
	for(int k = 1; k <= n; k ++)
		for(int i = 1; i <= n; i ++)
			for(int j = 1; j <= n; j ++)
				Min(f[i][j],f[i][k] + f[k][j]);
}
inline int query(int u,int v) {
	int ans = 0x3f3f3f3f3f3f3f3f;
	for(int it1 = hdm[u]; it1 != -1; it1 = gm[it1].nxt)
		for(int it2 = hdm[v]; it2 != -1; it2 = gm[it2].nxt)
			Min(ans,f[gm[it1].v][gm[it2].v] + gm[it1].w + gm[it2].w);
	return ans + a[u] + a[v];
}
inline void add(int u,int v,int w) {
	gn[++ totn].nxt = hdn[u],hdn[u] = totn;
	gn[totn].v = v,gn[totn].w = w;
	gm[++ totm].nxt = hdm[v],hdm[v] = totm;
	gm[totm].v = u,gm[totm].w = w;
}
signed main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(f,0x3f,sizeof f);
	memset(hdm,-1,sizeof hdm);
	memset(hdn,-1,sizeof hdn);
	in(c),in(n),in(m),in(d),in(q);
	for(int i = 1; i <= m; i ++) in(a[i]);
	for(int i = 1; i <= n; i ++) {
		int k;
		in(k);
		for(int j = 1; j <= k; j ++) {
			int v,w;
			in(v),in(w);
			add(i,v,w);
		}
	}
	Floyd();
	while(q --) {
		int u,v;
		in(u),in(v);
		out(query(u,v));
		putchar('\n');
	}
}
