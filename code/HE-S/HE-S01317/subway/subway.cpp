#include <bits/stdc++.h>//我正在写的是图论专题吗？
using namespace std;//注意空间不要大也不要小！！！
const int _ = 511111;//会有 1e6+500 个点;
int dep[_ << 1], lg[_ << 1], fa[_ << 1][22], shu, f[_ << 1], c, n, m, d, q, x, y, cnt, h[_ << 1], nxt[_ << 2], tot, to[_ << 2];
long long dis[_ << 1], len[_ << 2];//于是双向边会有 2e6 条;
struct hhh{
	int x, y, z;
}e[_ << 2];//会输进去 1e6 条边;
inline bool bbb(hhh x, hhh y){
	return x. z < y. z;
}
inline void add(int x, int y, long long z){
	to[++ tot] = y;
	nxt[tot] = h[x];
	h[x] = tot;
	len[tot] = z;
	return ;
}
inline int find(int x){
	return ((f[x] == x) ? x : (f[x] = find(f[x])));
}
inline bool merge(int x, int y){
	x = find(x), y = find(y);
	if(x ^ y){
		f[x] = y;
		return 1;
	}
	return 0;
}
inline void dfs(int x, int bfr){
	dep[x] = dep[bfr] + 1;
	fa[x][0] = bfr;
	for(int i = 1; i <= lg[shu]; i ++){
		fa[x][i] = fa[fa[x][i - 1]][i - 1];
	}
	for(int i = h[x]; i; i = nxt[i]){
		int y = to[i];
		if(y ^ bfr){
			dis[y] = dis[x] + len[i];
			dfs(y, x);
		}
	}
	return ;
}
inline int lca(int x, int y){
	if(dep[x] < dep[y]){
		swap(x, y);
	}
	while(dep[x] > dep[y]){
		x = fa[x][lg[dep[x] - dep[y]]];
	}
	if(x == y){
		return x;
	}
	for(int i = lg[dep[x]]; i >= 0; i --){
		if(fa[x][i] ^ fa[y][i]){
			x = fa[x][i], y = fa[y][i];
		}
	}
	return fa[x][0];
}
int main(){
//	system("fc 0.out subway7.ans");
	freopen("subway.in", "r", stdin);
//	freopen("0.out", "w", stdout);
	freopen("subway.out", "w", stdout);
	ios :: sync_with_stdio(0), cin. tie(0), cout. tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i ++){
		cin >> x;
		e[++ cnt] = {i, i + m, x};
	}
	shu = m * 2;
	for(int i = 1; i <= n; i ++){
		cin >> c;
		for(int j = 1; j <= c; j ++){
			cin >> x >> y;
			e[++ cnt] = {x + m, shu + i, y};
		}
	}
	
	sort(e + 1, e + cnt + 1, bbb);
//	for(int i = 1; i <= cnt; i ++){
//		cout << e[i]. x << ' ' << e[i]. y << ' ' << e[i]. z << '\n';
//	}
	shu += n;
//	cout<<shu<<'\n';
	for(int i = 1; i <= shu; i ++){
		f[i] = i;
		lg[i] = __lg(i);
	}
	int ok = 0;
//	cout<<cnt<<'\n';
	for(int i = 1; i <= cnt && ok < shu - 1; i ++){
		if(merge(e[i]. x, e[i]. y)){
			add(e[i]. x, e[i]. y, e[i]. z), add(e[i]. y, e[i]. x, e[i]. z);
			ok ++;
//			cout << i<<' ' <<e[i]. x << ' ' << e[i]. y <<' '<< '\n';
		}
	}
	dfs(1, 0);
//	for(int i = 1; i <= shu; i ++){
//		cout << dis[i] << ' ';
//	}cout<<'\n';
//	cout<<"RAIN";
	for(int i = 1; i <= q; i ++){
		cin >> x >> y;
		int lc = lca(x, y);
		cout << dis[x] + dis[y] - dis[lc] * 2 << '\n';
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

*/
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

*/
