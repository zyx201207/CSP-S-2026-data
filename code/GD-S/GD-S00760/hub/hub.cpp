#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
//多测记得清空 
int read(){
	int dat = 0,f = 1;char c = getchar();
	for(;!isdigit(c);c = getchar()) if(c == '-') f = -1;
	for(;isdigit(c);c = getchar()) dat = dat * 10 + (c - '0');
	return dat * f; 
}
int n,k,_,popcnt[1 << 10];
vector <int> e[N];
int lowbit(int k){
	return k & -k;
}
int is[15],dis[15],vis[15];
void dfs(int now){
	vis[now] = 1;
	for(auto nxt : e[now]){
		if(vis[nxt] || !is[nxt]) continue;
		dfs(nxt);
	}
}
bool check(){
	int res = 0;
	for(int i = 1; i <= n; i++){
		if(is[i] && !vis[i]){
			dfs(i);
			++res;
			if(res > 2) return false;
		}
	}
	return true;
}
int calc(int base){
	queue <int> q;while(!q.empty()) q.pop();
	for(int i = 1; i <= n; i++){
		if(base & (1 << i - 1)) is[i] = 1,q.push(i);
		else is[i] = 0;
		dis[i] = vis[i] = 0;
	}
	if(!check()) return 1e9;
	for(int i = 1; i <= n; i++) vis[i] = (is[i] ? 1 : 0);
	while(!q.empty()){
		int now = q.front();q.pop();
		for(auto nxt : e[now]){
			if(vis[nxt]) continue;
			vis[nxt] = 1;
			dis[nxt] = dis[now] + 1;
			q.push(nxt);
		}
	}
	int res = 0;
	for(int i = 1; i <= n; i++){
		res = max(res,dis[i]);
	}
	return res;
}
void subtask1(){
	int base = (1 << n) - 1,ans = 1e9;
	for(int i = 1; i <= base; i++) popcnt[i] = popcnt[i ^ lowbit(i)] + 1;
	for(int i = 1; i <= base; i++){
		if(popcnt[i] != k) continue;
		int f = calc(i);
		ans = min(ans,f);
	}
	cout << ans << '\n';
}
int up_cal(int f1,int f2){
	if(f1 % f2 == 0) return f1 / f2;
	return f1 / f2 + 1;
}
void subtask2(){
	int ans = 1e9,f = (n + 1) / 2;
	if(f <= k){
		cout << 1 << '\n';
		return;
	}
	for(int i = 0; i <= f; i++)	ans = min(ans,up_cal(max(i,f - k - i),2) + 1);
	cout << ans << '\n';
}
//int dep[N],bel[N],cnt;
//bool check2(int x){
//	dfs2(1,0);
//	if(cnt > k) return false;
//	 
//}
//void subtask3(){
//	int l = 1,r = n,ans = 0;
//	while(l <= r){
//		int mid = (l + r) >> 1;
//		if(check2(mid)){
//			r = mid - 1;
//			ans = mid;
//		}
//		else l = mid + 1;
//	}
//	cout << ans << '\n';
//}
void solve(){
	n = read(),k = read();
	for(int i = 1; i < n; i++){
		int u = read(),v = read();
		e[u].push_back(v);e[v].push_back(u);
	}
	if(n == k) cout << 0 << '\n';
	else if(_ >= 1 && _ <= 3) subtask1();
	else if(_ == 13 || _ == 14) subtask2();
	for(int i = 1; i <= n; i++) e[i].clear();
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	_ = read();int T = read();
	while(T--) solve();
	return 0;
}
