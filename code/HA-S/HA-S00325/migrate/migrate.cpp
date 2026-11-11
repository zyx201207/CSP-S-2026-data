#include <bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){
	int x;
	cin >> x;
	return x;
}
const int N = 2000005;
int n, d;
int x[N];
const int M = 5005;
struct SON{
	int ver, nxt;
}o[M * M];
int tot, head[M];
inline void add_edge(int u, int v){
	o[++tot] = SON{v, head[u]};
	head[u] = tot;
}
int dis[M], cnt[M];
bool vis[M];
inline void BFS(int st){
	for(int i = st; i <= n; i++) dis[i] = n, cnt[i] = 0, vis[i] = false;
	dis[st] = 0, cnt[st] = 1;
	queue<int> q;
	q.push(st);
	while(!q.empty()){
		int u = q.front(); q.pop();
		if(vis[u]) continue;
		vis[u] = true;
		for(int i = head[u]; i; i = o[i].nxt){
			int v = o[i].ver;
			if(dis[v] > dis[u] + 1) dis[v] = dis[u] + 1, cnt[v] = cnt[u], q.push(v);
			else if(dis[v] == dis[u] + 1){
				if(cnt[u] == 3) cnt[v] = 3;
				else{
					cnt[v] += cnt[u];
					if(cnt[v] > 3) cnt[v] = 3;
				}
			}
		}
	}
}
inline void solve_A(){
	tot = 0;
	for(int i = 1; i <= n; i++) head[i] = 0;
	for(int i = 1; i <= n; i++){
		int j = i + 1;
		while(j <= n && x[j] - x[i] <= d) add_edge(i, j++);
	}
	int ans = 0;
	for(int i = 1; i <= n; i++){
		BFS(i);
		for(int j = i; j <= n; j++) if(cnt[j] == 2) ans++; 
	}
	cout << ans << '\n';
}
inline int check_B(){
	for(int i = 1; i <= n; i++) if(x[i] - x[1] <= d && x[n] - x[i] <= d) return i;
	return 0;
}
inline int get(int pos){
	int l = pos, r = n;
	while(l < r){
		int mid = (l + r + 1) >> 1;
		if(x[mid] - x[pos] <= d) l = mid;
		else r = mid - 1;
	}
	return l;
}
inline void solve_B(int mid){
	if(mid == 1){
		cout << 0 << '\n';
		return ;
	}
	long long ans = 0;
	for(int i = 1; i < mid; i++){
		if(mid + 2 <= n && x[mid + 2] - x[i] <= d) continue;
		if(x[mid + 1] - x[i] <= d){
			int r = get(mid - 1);
			ans += n - r;
		}
		else{
			int r = (mid - 2 ? get(mid - 2) : mid), r_ = get(mid - 1);
			ans += r_ - r;
		}
	}
	cout << ans << '\n';
}
inline void solve(){
	n = read(), d = read();
	for(int i = 1; i <= n; i++) x[i] = read();
	if(n <= 5000) solve_A();
	else{
		int mid = check_B();
		if(mid) solve_B(mid);
	}
}
signed main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	for(int test = read(), T = read(); T; T--) solve();
	return 0;
}
