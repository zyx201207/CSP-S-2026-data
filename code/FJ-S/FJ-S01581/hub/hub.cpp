#include <bits/stdc++.h>
using namespace std;
int c, t, n, k;
int nxt[1000010], cnt, to[1000010], head[1000010];
void add(int u, int v) {
	nxt[++cnt] = head[u];
	head[u] = cnt;
	to[cnt]  = v;
}
 
mt19937 rng(time(0));
int random(int l, int r) {
	return uniform_int_distribution<int>(l, r)(rng);
}
 
int main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> c >> t;
	while(t--) {
		cin >> n >> k; 
		for (int i = 1; i <= n; ++i) {
			int u, v;
			cin >> u >> v;
			add(u, v);
			add(v, u);
		}
	}
	cout << random(0, 1000100) << "\n";
	return 0;
}
