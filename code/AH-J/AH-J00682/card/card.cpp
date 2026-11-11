#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 5e5 + 5;
int n, m;
int a[N], c[N];
bool vis[N];
int find(int x, int j) {
	for (int i = j; i <= n; i++) {
		if (a[i] == x) {
			return i;
		}
	}
	return j;
}
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		memset(vis, 0, sizeof vis);
		for (int j = i; j <= n; j++) {
			if (vis[a[j]]) {
				int t = find(a[j], i);
				for (int k = t; k <= j; k++) {
					vis[a[k]] = 0;
				}
			}
			vis[a[j]] = 1;
		}
		for (int j = i; j <= n; j++) {
			if (vis[a[j]]) {
				c[a[j]]++;
				vis[a[j]] = 0;
			}
		}
	}
	for (int i = 1; i <= m; i++) {
		cout << c[i] << ' ';
	}
	return 0;
}
