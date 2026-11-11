#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define cfalse cin.tie(0)->sync_with_stdio(0)
const int maxn = 6e5 + 5;
const int inf = 1e18;
int c, n, k, ans = 0, fa[maxn], sum = 0;//sum node to other
vector<int>mp[maxn];
vector<int>t;
vector<int>ck;
bool f[maxn];
int find(int x){
	if(fa[x] == x)return fa[x];
	return fa[x] = find(fa[x]);
}
void dfss(int p, int ls, int d){
	if(f[p]){
		sum = min(sum, d);
		return;
	}
	for(auto i : mp[p]){
		if(i == ls) continue;
		dfss(i, p, d + 1);
	}
}
void sol(){
	t.clear();
	ck.clear();
	for(int i = 1; i <= n; i++) fa[i] = i;
	for(int i = 1; i <= n; i++){
		if(!f[i]) continue;
		t.push_back(i);
	}
	for(auto i : t){
//		cout << i << ' ';
		for(auto j : mp[i]){
			if(!f[j]) continue;
			if(find(i) == find(j)) continue;
			fa[find(i)] = find(fa[j]);
		}
	}
//	cout << endl;
	for(auto i : t){
		ck.push_back(find(i));	
	}
	sort(ck.begin(), ck.end());
	int las = ck[0], cnt = 1;
	for(int i = 1; i < (int)ck.size(); i++){
		if(las != ck[i]){
			cnt++;
		}
		las = ck[i];
		if(cnt > 2) return;
	}
	int num = 0;// sol's maxx
//	cout << "yunsuan: " << endl;
	vector<pair<int, int>>deb;
	for(int i = 1; i <= n; i++){
		if(f[i]) continue;
		sum = inf;
		dfss(i, 0, 0);
//		cout << i << ' ' << sum << endl;
		deb.push_back({i, sum});
		num = max(num, sum);
	}
//	if(num == 1){
//		for(auto i : t) cout << i << ' ';
//		cout << "sol" << endl;
//		for(auto i : deb){
//			cout << i.first << ' ' << i.second << endl;
//		} 
//		for(auto i : t) cout << find(i) << ' ';
//		cout << endl;
//	}
	ans = min(ans, num);
}
void dfs(int p, int cnt){
	if(cnt == k) {
		sol(); 
		return;
	}
	if(p > n) return;
	if(n - p + cnt + 1 < k) return;
	f[p] = 1;
	dfs(p + 1, cnt + 1);
	f[p] = 0;
	dfs(p + 1, cnt);
}
void solve(){
//	cout << 114514 << endl;
	for(int i = 1; i <= n; i++) mp[i].clear();
	cin >> n >> k;
	for(int i = 0; i < n - 1; i++){
		int u, v; cin >> u >> v;
		mp[u].push_back(v);
		mp[v].push_back(u);
	}
	ans = inf;
	dfs(1, 0);
	cout << ans << endl;
}
signed main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int T;
	cin >> c >> T;
	while(T--) solve();
    return 0;
}
