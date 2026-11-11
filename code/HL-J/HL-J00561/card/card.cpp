#include <bits/stdc++.h>

using namespace std;

int a[500002];
int lst[300002];
long long cnt[300002];
int use[500002];
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		lst[a[i]] = i;
	}
	for (int i = 1; i <= n; i++) {
		use[i]++;
		cnt[a[i]] += use[i];
		if (lst[a[i]]) {
			use[lst[a[i]] + 1] += use[i];
		} else {
			use[i + 1] += use[i];
		}
	}
	for (int i = 1; i <= m; i++) cout << cnt[i] << ' ';
	return 0;
}
