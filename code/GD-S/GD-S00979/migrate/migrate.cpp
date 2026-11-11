#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N1 = 3e2 + 10, N = 2e6 + 10;
int cpos, n, d, x[N], dis1[N1], vis1[N1];
bool wh[N];
bool mp1[N1];
void solve1() {
	cin >> n >> d;
	for (int i = 1; i <= n; i++) cin >> x[i];
	int ans = 0ll;
	for (int i = 1; i <= n; i++) {
		memset(dis1, -1, sizeof dis1);
		queue<pair<int, int> > q;
		q.push({i, 1ll});
		while (!q.empty()) {
			int u = q.front().first, cnt = q.front().second;
			q.pop();
			if (dis1[u] != -1) continue;
			dis1[u] = cnt;
			for (int v = 1; v <= n; v++) 
				if (abs(x[u] - x[v]) <= d && u != v) q.push({v, cnt + 1});
		} 
		q.push({i, 1ll});
		memset(vis1, 0, sizeof vis1);
		memset(mp1, false, sizeof mp1);
		while (!q.empty()) {
			int u = q.front().first, cnt = q.front().second;
			q.pop();
			if (cnt == dis1[u]) vis1[u]++;
			else continue;
			for (int v = 1; v <= n; v++) 
				if (abs(x[u] - x[v]) <= d && u != v) q.push({v, cnt + 1});
		} for (int v = i + 1; v <= n; v++) if (vis1[v] == 2) ++ans;
	} cout << ans << "\n";
}
void solve2() {
	cin >> n >> d;
	for (int i = 1; i <= n; i++) cin >> x[i];
	int B = 0;
	memset(wh, false, sizeof wh);
	for (int i = 1; i <= n; i++)
		if (abs(x[i] - x[1]) <= d && abs(x[n] - x[i]) <= d) ++B, wh[i] = 1;
	if (B != 2) {cout << "0\n"; return ;}
	int BB = 0, ans = 0; 
	for (int i = 1; i <= n; i++) {
		if (wh[i]) {++BB; continue;}
		ans += (n - i - (B - BB));
	}
	cout << ans << "\n"; 
}
signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> cpos;
	if (cpos >= 13 && cpos <= 14) {
		int t;
		cin >> t;
		while (t--) solve2();
		return 0;
	}
	int t;
	cin >> t;
	while (t--) solve1();
	return 0;
}
