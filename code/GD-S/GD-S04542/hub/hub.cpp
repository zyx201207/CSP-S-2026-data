#include <bits/stdc++.h>
using namespace std;
const int N = 5007;
int testcase, T;

int n, k;
vector<int> ed[N]; int x[N], y[N];
//题目输入 

int deg[N], haiba[N];
queue<int> q;
//多源剥叶的方法 

int mp[2][N];

void dfs(int x, int fa) {
	deg[x] = 1;
	for(int y : ed[x]) if(y != fa) {
		dfs(y, x);
		deg[x] ++;
	}
}
void topo(int x, int fa, int tp) {
	if(ed[x].size() == 1) {
		haiba[x] = 1;
		return;
	}
	for(int i = 1; i <= n; i ++) {
		deg[i] = 0;
	}
	dfs(x, fa); deg[x]--;
	for(int i = 1; i <= n; i ++){
		if(deg[i] == 1){
			q.push(i);
			haiba[i] = 1;
		}
	}
	while(q.size()) {
		int x = q.front();
		q.pop();
		if(!deg[x]) continue;
		deg[x] = 0;
		for(int y : ed[x]) {
			if(!deg[y]) continue;
			deg[y]--;
			if(deg[y] == 1) {
				haiba[y] = haiba[x] + 1;
				q.push(y);
			}
		}
	}
	for(int i = 1; i <= n; i ++) {
		mp[tp][haiba[i]] ++;
	}
}
void init() {
	cin >> n >> k;
	for(int i = 1; i < n; i ++) {
		cin >> x[i] >> y[i];
		ed[x[i]].push_back (y[i]);
		ed[y[i]].push_back (x[i]);
	}
}
int solve() {
	init();
	int ans = n;
	for(int i = 1; i < n; i ++) {
		topo(x[i], y[i], 0);
		topo(y[i], x[i], 1);
		int cnt[2] = {0,0};
		for(int v = n; v; v --) {
			cnt[0] += mp[0][v];
			cnt[1] += mp[1][v];
			if(cnt[0] + cnt[1] >= k){
				ans = min(ans, n - v);
			}
		}
	}
	return ans;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin >> testcase >> T;
	testcase = 0, T = 1000;
	while(T --){
		cout << solve() << "\n";
	}
	return 0;
}

