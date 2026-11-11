#include <bits/stdc++.h>
#define LL long long
using namespace std;
constexpr int N = 5e5 + 10;

int c, n, m, d, q;
int w[N];
vector<int> a[510];
vector<int> b[N];
int x, y;
int ans = 1e9;
bool vis[510];
map<int,map<int, int>> times;

//void bfs(int l, int r){
//	// id, line, cnt; 第 id 个地铁，第 line 条线，总花费 cnt 分钟 
//	queue<array<int,3>> qu;
//	qu.push({l, 0, 0});
//	while(qu.size()){
//		auto t = qu.front();
//		qu.pop();
//		int id = t[0], line = t[1];
//		int cnt = t[2];
//		if(id == r){
//			cnt += times[line][id] + w[id];
//			ans = min(ans, cnt);
//			continue;
//		}
//		cnt += times[line][id];
//		// 换乘
//		for(auto can : b[line]){
//			if(vis[can]) continue;
//			
//		}
//		
//	}
//	return;
//}

void dfs(int id, int line, int cnt){
	// id, line, cnt; 第 id 个地铁，第 line 条线，总花费 cnt 分钟 
	if(id == y){
		cnt += times[line][id] + w[id];
		ans = min(ans, cnt);
		return;
	}
	cnt += times[line][id];
	// 换乘
	for(auto can : b[id]){  // 该站台有 b[id] 条线路 
		if(vis[can]) continue;  // 去过该条线路，则跳过 
 		vis[can] = true; // 标记去过该条线路 
		for(auto go : a[can]){  // 遍历该线路可以去的站台 
			if(a[go].size() == 1) continue;  // 如果目标站台只有 1 条线路，跳过 
			cnt += times[can][id];  // 时间 + 站台到线路 
			dfs(go, can, cnt); // 继续递归 
			cnt -= times[can][id];  // 减去时间，不去这个站 
		}
		vis[can] = false;
	} 
	return;
}

void solve(){
	scanf("%d %d", &x, &y);
//	cin >> x >> y;
//	for(int i = 1;i <= n;i++) vis[i] = false;
	ans = 1e9;
	dfs(x, 0, w[x]);
	cout << ans << '\n';
	return;
}

int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);

	scanf("%d %d %d %d %d", &c, &n, &m, &d, &q);
//	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++) scanf("%d", &w[i]);
	for(int i = 1;i <= n;i++){
		int k;
		scanf("%d", &k);
		for(int j = 1;j <= k;j++){
			int te1, te2;
			scanf("%d %d", &te1, &te2);
//			cin >> te1 >> te2;
			a[i].push_back(te1);
			b[te1].push_back(i);
			times[i][te1] = te2;
		}
	} 
	while(q--){
		solve();
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}

