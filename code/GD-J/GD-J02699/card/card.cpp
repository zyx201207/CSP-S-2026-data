#include <bits/stdc++.h>
using namespace std;

const int N = 3 * 114514;
int n, m, a[N], vis[N], ans = 0;

stack<int> s;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	
	cin >> n >> m;
	
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	
	for (int i = 1; i <= n; i++) {
		memset(vis, 0, sizeof(vis));
		for (int j = 1; j <= n; j++) {
			if (vis[a[i]]) {
				while (a[i] != s.top())
					s.pop();
			} else {
				s.push(a[i]);
				vis[i] = 1;
			}
		}
		while (!s.empty()) {
			if (s.top() == i)
				ans++;
			s.pop();
		}
	}
	
	cout << ans << "\n";
	return 0;
}

