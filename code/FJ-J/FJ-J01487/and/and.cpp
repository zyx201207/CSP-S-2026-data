#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	vector<int> a(n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	int maxand = 0x7fffffff;
	vector<bool> vis(n, false);
	for(int i = 0; i < m; i++) {
		int _now = -1;
		while (vis[++_now]);
		for (int j = 0; j < n; j++) {
			if (!vis[j]) {
				//cout << maxand << ' ' << a[j] << ' ' << a[_now] << ' ' << (maxand & a[j])  << ' ' << (maxand & a[_now]) << '\n';
				//printf("%x\n%x\n%x\n", maxand, a[j], a[_now]);
				if ((maxand & a[j]) > (maxand & a[_now])) {
					//cout << "yes" << '\n';
					_now = j;
				}
			}
		}
		vis[_now] = true;
		maxand &= a[_now];
		//cout << "_now:" << _now << ' ' << maxand << '\n'; 
	}
	cout << maxand << '\n';
	return 0;
}
