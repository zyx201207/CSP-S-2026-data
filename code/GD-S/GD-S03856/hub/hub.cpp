#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int n, k;
bool check (const vector<int> &li, const vector<int> &mx, const vector<int> &dx,
		 	const vector<vector<int>> &e, int d) {
	int l = 1, r = li.size() - 1;
	int maxl = 0, maxr = 0;
	while (l <= r) { maxl = max(maxl, mx[l]);if (maxl > d) { l--; break; } maxl++; l++;}
	while (r > l) { maxr = max(maxr, mx[r]); if (maxr > d) { r++; break; } maxr++; r--;}
	if (l == r) return true;
	
	maxl = 0, maxr = 0; int ml = l + (k - 2) + 1, mr = r - 1;
//	cout << "in check : ml = " << ml << " mr = " << mr << " d = " << d << endl
//		 << " l = " << l << " r = " << r << endl;
	while (ml <= mr) { maxl++; maxl = max(maxl, mx[ml]);if (maxl > d) { ml--; break; } ml++;}
	while (mr > ml) { maxr++; maxr = max(maxr, mx[mr]); if (maxr > d) { mr++; break; } mr--;}
	
	if (ml >= mr) return true; 
	return false;
}
int main () {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);	
	
	int c, T; cin >> c >> T;
	while (T--) {
		cin >> n >> k;
		if (k == n) { cout << 0 << '\n'; continue;	}
		vector<vector<int>> e(n + 1);
		for (int i = 1; i < n; i++) {
			int u, v; cin >> u >> v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		
		int x = 1, y = 1;
		vector<int> dx(n + 1), dy(n + 1);
		
		queue<int> q; q.push(x);
		while (!q.empty()) {
			int u = q.front(); q.pop();
			for (int v : e[u]) if (!dx[v])	dx[v] = dx[u] + 1, q.push(v);
		}
		
		y = max_element(dx.begin() + 1, dx.end()) - dx.begin();
		
		q.push(y);
		while (!q.empty()) {
			int u = q.front(); q.pop();
			for (int v : e[u]) if (!dy[v])	dy[v] = dy[u] + 1, q.push(v);
		}
		x = max_element(dy.begin() + 1, dy.end()) - dy.begin();
		
		q.push(x); dx.assign(n + 1, 0);
		while (!q.empty()) {
			int u = q.front(); q.pop();
			for (int v : e[u]) if (!dx[v])	dx[v] = dx[u] + 1, q.push(v);
		}
		
		vector<int> li(dx[y] + 2);
		for (int i = 1, u = x, fa = 0; i < dx[y] + 1; i++) {
			li[i] = u;
			for (int v : e[u])
				if (v != fa && dx[v] + dy[v] == dx[y]) {
					fa = u, u = v;
					break;
				}
		} li[dx[y] + 1] = y;
		
		vector<char> vis(n + 1);
		vector<int> mx(n + 1);
		for (int i = 1; i < (int)li.size(); i++) {
			int be = (i != 1 ? i - 1 : i), af = (i != (int)li.size() - 1 ? i + 1 : i);
//			cout << "i = " << i << ' ' << be << ' ' << af << endl;
			vis[li[be]] = true; vis[li[af]] = true;
			
			for (int v : e[li[i]]) if (!vis[v]) q.push(v); 
			while (!q.empty()) {
				int u = q.front(); q.pop();
				vis[u] = true;
//				cout << u << endl;
				mx[i] = max(mx[i], dx[u] - dx[i]);
				for (int v : e[u]) if (!vis[v]) q.push(v);
			}
		}
		int l = 0, r = ceil((double)dx[y] / 3), mid, res = -1;
		while (l <= r) {
			mid = (l + r) / 2;
			if (check(li, mx, dx, e, mid)) r = mid - 1, res = mid;
			else l = mid + 1;
		}
		cout << res << '\n';
	}
	return 0;
} 


