#include <bits/stdc++.h>
#define MAXM 500005
#define MAXN 505
#define fst first
#define scd second
using namespace std;
using PII = pair<int, int>;
operator <(const PII& a, const PII& b) { return a.fst < b.fst;};
operator ==(const PII& a, const PII& b) { return a.fst == b.fst;};
int c, n, m, d, q, w[MAXM], k[MAXN], x, y, ans, T;
vector<int> a[MAXN], t[MAXN];
set<PII> lines[MAXM];
// fst line_num scd  ord in the line
set<PII> trans[MAXN];
bool vis[MAXN], dis[MAXN];

struct node {
	int ln, dis;
	
	operator <(const node& o) const {
		return dis < o.dis;
	}
} head;
int search(int, int);
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin.tie(0) -> sync_with_stdio(0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1;i <= m;i++){
		cin >> w[i];
	}
	for (int i = 1;i <= n;i++) {
		cin >> k[i];
		a[i].resize(k[i]), t[i].resize(k[i]);
		for (int j = 1;j <= k[i];j++){
			cin >> a[i][j] >> t[i][j];
			T= t[i][j];
			lines[a[i][j]].insert({i, j});
			if (lines[a[i][j]].size() >= 2) {
				for (auto [ln, ord] : lines[a[i][j]]) trans[i].insert({a[i][j], j});
			}
		}
	}
	if (c >= 12 &&c <= 19) {
		for (int i = 1;i <= q;i++){
			cin >> x >> y;
			for (int i = 1;i <= m;i++) vis[i] = 0, dis[i] = 1e9;
			queue<node> q;
			for (auto [ln, ord] : lines[x]) q.push({ln, 1}), vis[ln] = 1;
			while(!q.empty()){
				head = q.front();
				vis[head.ln] = 1;
				q.pop();
				for (auto [cmpln, ord] : lines[y]) {
					if (head.ln == cmpln){
						cout << w[x] + w[y] + T * (head.dis + 1) << endl;
						return 0;
					}
				}
				for (auto [pos, ord1] : trans[head.ln]) {
					for (auto [trans_ln, ord2] : lines[pos]){
						if (!vis[trans_ln]) q.push({trans_ln, head.dis + 1});
					}	
				}
			}
		}
		cout << search(x, y) << endl;
		return 0;
	}
	for (int i = 1;i <= q;i++){
		cin >> x >> y;
		for (int i = 1;i <= m;i++) vis[i] = 0, dis[i] = 1e9;
		cout << search(x, y) << endl;
	}
	return 0;
}
int search(int s, int e){
	priority_queue<node> q;
	for (auto [ln, _] : lines[s]) q.push(node {ln, w[s] + w[e]}), vis[ln] = 1;
	ans = 1e9;
	while(!q.empty()){
		head = q.top();
		vis[head.ln] = 1; 
		q.pop();
		if (lines[e].find({head.ln, 0}) != lines[e].end()){
			ans = min(ans, head.dis);
		}
		for (auto [pos, ord1] : trans[head.ln]) {
			for (auto [trans_ln, ord2] : lines[pos]){
				if (dis[trans_ln] > dis[head.ln] + t[trans_ln][ord2] + t[head.ln][ord1]){
					dis[trans_ln] = dis[head.ln] + t[trans_ln][ord2] + t[head.ln][ord1];
					q.push({trans_ln, dis[head.ln] + t[trans_ln][ord2] + t[head.ln][ord1]});
				}
			}
		}
	}
	return ans;
}