#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5, M = 3e5 + 5;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int a[N];
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	int sta[N], top = 0;
	int ans[M] = {0};
	bool used[M] = {false};
	for (int s = 1; s <= n; ++s) {
		top = 0;
		memset(used, false, sizeof(used));
		for (int i = s; i <= n; ++i) {
			if (used[a[i]]) {
				while (sta[top] != a[i] && top != 0) {
					used[sta[top]] = 0;
					--top;
				}
			} else sta[++top] = a[i], used[a[i]] = 1;
		}	
		for (int j = 1; j <= top; ++j) {
			++ans[sta[j]];
		}
	}
	
	for (int i = 1; i <= m; ++i) {
		cout << ans[i] << ' ';
	}
	cout << '\n';
	return 0;
}

