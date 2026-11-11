#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
int n, m, a[N], f[N];
bool vis[N];
vector<int> v;
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	if (n >= 10000) {
		for (int i = 1; i <= n; i++)
			f[a[i]] += i;
		for (int i = 1; i <= m; i++) cout << f[i] << " ";
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		memset(vis, false, sizeof(vis));
		for (int j = i; j <= n; j++) {
			if (vis[a[j]] == true) {
				while (v[v.size() - 1] != a[j]) {
					vis[v[v.size() - 1]] = false;
					v.pop_back();
				}
			} else {
				v.push_back(a[j]);
				vis[a[j]] = true;
			}
		}
		for (auto j : v) f[j]++;
		v.resize(0);
	}
	for (int i = 1; i <= m; i++)
		cout << f[i] << " ";
	return 0;
} 
// 10 3 3 1 2 1 3 2 3 1 2 1
