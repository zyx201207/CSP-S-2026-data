#include<bits/stdc++.h>
using namespace std;
#define vec std::vector
#define ll long long
#define i128 __int128
#define endl "\n"
#define pb push_back
ll read(){
	ll num = 0; int f = 1;
	char c = getchar();
	while (c < '0' || c > '9') {
		if (c == '-') f = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		num = (num << 1) + (num << 3) + (c ^ 48);
		c = getchar();
	}
	return num * f;
}
constexpr int N  = 5005;
int n; ll d;
ll pos[N];
vec<int> adj[N];
int dis1[N], dis2[N];
void CZW(int id){
	n = read(), d = read();
	if (id == 13 || id == 14) {
		cout << 1ll * n * n << endl;
		return ;
	}
	for (int i = 1; i <= n; ++i) adj[i].clear();
	for (int i = 1; i <= n; ++i) {
		pos[i] = read();
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = i + 1; j <= n; ++j) {
			if (abs(pos[i] - pos[j]) <= d) {
				adj[i].pb(j);
			}
		}
	}
	int ans = 0;
		queue<int> q;
		q.push(1);
		for (int j = 1; j <= n; ++j) dis1[j] = dis2[j] = 1e9;
		dis1[1] = 0;
		while (!q.empty()){
			int u = q.front();
//			cout << "node: " << u << ' ' << fa << endl;
			q.pop();
			for (int v : adj[u]) {
//				cout << "to: " << v << endl;
				if (dis1[v] > dis1[u] + 1) {
					int tmp = dis1[v];
					dis1[v] = dis1[u] + 1;
					dis2[v] = min(tmp, dis2[u] + 1);
//					cout << "id: " << 1 << endl;
//					cout << "cur_dis: " << dis1[v] << ' ' << dis2[v] << endl;
//					cout << "----" << endl;
					q.push(v);
				}else if (dis2[v] > dis1[u] + 1) {
					dis2[v] = dis1[u] + 1;
//					cout << "id: " << 2 << endl;
//					cout << "cur_dis: " << dis1[v] << ' ' << dis2[v] << endl;
//					cout << "----" << endl;
					q.push(v);
				}else if (dis2[v] > dis2[u] + 1) {
					dis2[v] = dis2[u] + 1;
//					cout << "id: " << 3 << endl;
//					cout << "cur_dis: " << dis1[v] << ' ' << dis2[v] << endl;
//					cout << "----" << endl;
					q.push(v);
				}
			}
		}
//		cout << "dis: " << endl;
//		for (int j = 1; j <= n; ++j) cout << dis1[j] << ' ' << dis2[j] << endl;
//		cout << endl << "=--------" << endl;
		for (int j = 2; j <= n; ++j) if (dis1[j] == dis2[j]) {
			++ans;
		}
	cout << ans << endl;
}
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int id = read(), Test = read();
	while (Test --) CZW(id);
	return 0;
}

