#include<bits/stdc++.h>
using namespace std;
const int M = 5e5 + 10, N = 505;
const long long oo = 1e18;
struct edge{
	int x;
	long long t;
}e[N];
struct node{
	int num;
	long long t;
};
int op, n, m, d, q, cnt[N], vis[N], idq;
long long w[M], val[N][N], f[N][N];
bool ok[N][N];
vector<node> a[M];
long long dfs(int st, int ed) {
	if(st == ed) return 0;
 	if(f[st][ed] != oo) return f[st][ed];
	for(int i = 1; i <= n; i++) {
		if(vis[i] == idq || ok[st][i] == false) continue;
		vis[i] = idq;
		if(f[i][ed] == oo) f[i][ed] = dfs(i, ed);
		f[st][ed] = min(f[st][ed], f[i][ed] + val[st][i]);
	}
	if(ok[st][ed]) f[st][ed] = min(f[st][ed], val[st][ed]);
	return f[st][ed];
}
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> op >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++) cin >> w[i];
	for(int i = 1; i <= n; i++) {
		cin >> cnt[i];
		for(int j = 1; j <= cnt[i]; j++) {
			cin >> e[i].x >> e[i].t;
			a[e[i].x].push_back((node){i, e[i].t});
		}
	}
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++) val[i][j] = val[j][i] = oo, f[i][j] = f[j][i] = oo;
	for(int i = 1; i <= m; i++) {
		if(a[i].size() <= 1) continue;
		for(int j = 0; j < a[i].size(); j++) {
			for(int k = 0; k < j; k++) {
				int eg1 = a[i][j].num, eg2 = a[i][k].num;
				long long tm1 = a[i][j].t, tm2 = a[i][k].t;
				ok[eg1][eg2] = ok[eg2][eg1] = true;
				val[eg1][eg2] = min(val[eg1][eg2], tm1 + tm2), val[eg2][eg1] = min(val[eg2][eg1], tm1 + tm2);
			}
		}
	}
	for(int i = 1; i <= n; i++) f[i][i] = 0, ok[i][i] = true, val[i][i] = 0;
	while(q--) {
		int st, ed;
		cin >> st >> ed;
		long long sum = w[st] + w[ed], res = oo;
		for(auto p : a[st]) {
			for(auto q : a[ed]) {
				if(f[p.num][q.num] == oo) {
					vis[p.num] = ++idq;
					f[p.num][q.num] = dfs(p.num, q.num);
				}
				res = min(res, f[p.num][q.num] + sum + p.t + q.t);
			}
		} 
		cout << res << '\n';
	}
 
		
	return 0;
}
