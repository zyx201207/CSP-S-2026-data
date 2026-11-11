#include <bits/stdc++.h>//我错了你其实不是图论专题我眼睛瘸了呜呜但是我的脚崴了可能真要瘸了好痛呜呜………
using namespace std;
const int _ = 2000010;
int dep[_ << 1], lg[_ << 1], fa[_ << 1][22], ans, x, y;
int k, t, n, h[_], tot, nxt[_ << 1], to[_ << 1], dis[_];
bool v[_];
vector<int> c;
inline void dfs(int x, int bfr){
	dep[x] = dep[bfr] + 1;
	fa[x][0] = bfr;
	for(int i = 1; i <= lg[n]; i ++){
		fa[x][i] = fa[fa[x][i - 1]][i - 1];
	}
	for(int i = h[x]; i; i = nxt[i]){
		int y = to[i];
		if(y ^ bfr){
			dis[y] = dis[x] + 1;
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
int cnt;
void cc(int x, int bfr){
	int o = 0;
	for(int i = h[x]; i; i = nxt[i]){
		int y = to[i];
		if(y ^ bfr){
			if(v[y] && ! v[x]){
				cnt ++;
			}
			cc(y, x);
		}
	}
	return ;
}
inline void suan(){
	int as = 0;
	cnt = 0;
	if(v[1]){
		cnt=1;
	}
	cc(1, 0);
	if(cnt > 2){
		return ;
	}
//	for(auto x : c){
//		cout << x<<' ';
//	}cout<<'\n';
	for(int i = 1; i <= n; i ++){
		if(! v[i]){
			int num = 1000000000;
			for(auto x : c){
				int lc = lca(i, x);
				num = min(num, dep[i] + dep[x] - dep[lc] * 2);
			}
			as = max(as, num);
		}
	}
//	cout<<as<<'\n';
	ans = min(ans, as);
	return ;
}
inline void baoli(int nw, int ok){
	if(ok == k){
		suan();
		return ;
	}
	if(nw == n){
		return ;
	}
	c. push_back(nw + 1);
	v[nw + 1] = 1;
	baoli(nw + 1, ok + 1);
	c. pop_back();
	v[nw + 1] = 0;
	baoli(nw + 1, ok);
	return ;
}
inline void add(int x, int y){
	to[++ tot] = y;
	nxt[tot] = h[x];
	h[x] = tot;
	return ;
}
int main(){//但是倒闭了！！！
	freopen("hub.in", "r", stdin);
//	freopen("0.out", "w", stdout);
	freopen("hub.out", "w", stdout);
	ios :: sync_with_stdio(0), cin. tie(0), cout. tie(0);
cin >> t >> t;
for(int i = 1; i <= _ - 5; i ++){
	lg[i] = __lg(i);
}
while(t --){
	c. clear();
	ans = 2000000000;
	for(int i = 1; i <= n; i ++){
		h[i] = dis[i] = dep[i] = 0;
	}
	tot = 0;
	cin >> n >> k;
	for(int i = 1; i < n; i ++){
		cin >> x >> y;
		add(x, y), add(y, x);
	}
	dfs(1, 0);
	ans = 2000000000;
	baoli(0, 0);
	cout << ans << '\n';
}
	return 0;
}
/*
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10

*/
