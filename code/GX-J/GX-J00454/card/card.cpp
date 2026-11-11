#include <bits/stdc++.h>
using namespace std;

const int maxn = 100004 * 5;
bool vis[maxn];
int num[maxn];
int main() {
	freopen ("card.in", "r", stdin);
	freopen ("card.out", "w", stdout);
	
	int n, m;
	vector <int> a, b;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		b[i] = a[i];
		vis[i] = false;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			vis[b[j]];
		}
		for (int j = 1; j <= b.size(); j++) {
			if (vis[j] == false) num[b[j]];
		}
	}
	for (int i = 1; i <= n; i++) cout << num[i] << ' ' << endl;
	return 0;
}
