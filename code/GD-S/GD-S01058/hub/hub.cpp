#include <bits/stdc++.h> 
using namespace std;
using ll = long long;
#define pii pair<int ,int>
#define ft first
#define sd second
ll read() {
	ll n = 0 ,f = 1; char c = getchar();
	while (c < '0' || c > '9') f = (c == '-') ? -f : f ,c = getchar();
	while (c >= '0' && c <= '9') n = n * 10 + c - '0' ,c = getchar();
	return n * f;
}
template<class T> inline void chkmx(T &x ,T y) { if (y > x) x = y; }
template<class T> inline void chkmn(T &x ,T y) { if (y < x) x = y; }

const int inf = 1e9;
const int N = 1e6 + 10 ,M = 20;

int n ,k ,a ,b;
vector<int> G[N] ,p;
int dis[N] ,vis[N] ,dep[N];

int dfs(int u ,int par ,int lim) {
	dis[u] = 0; int res = 0;
	for (auto v : G[u]) if (v != par && v != a && v != b)
		res += dfs(v ,u ,lim) + (dis[v] >= lim) ,chkmx(dis[u] ,dis[v] + 1);
	return res;
}
bool find(int u ,int par ,int tar) {
	p.push_back(u);
	if (u == tar) return 1;
	for (auto v : G[u]) if (v != par) {
		if (find(v ,u ,tar)) return 1;
	}
	p.pop_back();
	return 0; 
}
void dfs2(int u ,int par) {
	vis[u] = 1 ,chkmn(dep[u] ,dep[par] + 1);
	for (auto v : G[u]) if (v != par && v != a && v != b) dfs2(v ,u);
}

bool check(int x) {
	int res = inf;
	for (a = 1;a <= n;a++) for (b = 1;b <= n;b++) if (a != b) {
		p.clear() ,find(a ,0 ,b);
		if ((int)p.size() == 2) continue;
		for (int i = 1;i <= n;i++) dep[i] = inf;
		dep[a] = dep[b] = 0 ,dfs2(p[1] ,a) ,dfs2(p[(int)p.size() - 2] ,b);
		int mx = 0;
		for (int i = 1;i <= n;i++) if (vis[i]) chkmx(mx ,dep[i]);
		if (mx <= x) {
			int val = 2 + dfs(a ,p[1] ,x) + dfs(b ,p[(int)p.size() - 2] ,x);
			chkmn(res ,val);
		}
		for (int i = 1;i <= n;i++) vis[i] = 0;
	}
	for (int i = 1;i <= n;i++) chkmn(res ,1 + dfs(i ,0 ,x));
	return res <= k;
}


void solve() {
	n = read() ,k = read();
	for (int i = 1 ,u ,v;i < n;i++)
		u = read() ,v = read() ,
		G[u].push_back(v) ,G[v].push_back(u);
	int l = 0 ,r = n - 1 ,ans = n - 1;
	while (l <= r) {
		int mid = l + r >> 1;
		if (check(mid)) ans = mid ,r = mid - 1;
		else l = mid + 1;
	}
//	check(2);
	printf("%d\n",ans);
	for (int i = 1;i <= n;i++) G[i].clear();
}

int main() {
//	freopen("hub3.in" ,"r" ,stdin);
	freopen("hub.in" ,"r" ,stdin);
	freopen("hub.out" ,"w" ,stdout);
	int c = read() ,T = read();
	while (T--) solve();
	return 0;
}
/*
0 1
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

其实应该直接去打正解的，可惜了！！！ 
正解根本不难，其实不比这个暴力难写多少，策略有问题。
痛失 AK。 
*/
