#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	
	int n, m;
	cin >> n >> m;
	int a[n], b[m], c[n], cnt[m] = {0};
	bool asc = true;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] < a[i - 1]) asc = false;
		if (a[i] > a[i - 1]) b[a[i]] = i;
	}
	if (asc) {
		for (int i = 0; i < m; i++) {
			cout << n - b[m];
		}
		return 0;
	}
	int k = 0;
	for (int i = 0; i < n; i++) {
		if ((i == 0) || (a[i] != a[i - 1])) {
			c[k] = a[i];
			k++;
		}
	}
	bool flag[m + 10];
	for (int i = 0; i < m + 10; i++) {
		flag[i] = false;
	}
	for (int i = 0; i < n; i++) {
		deque <int> q;
		for (int j = i; j < n; j++) {
			if (flag[c[j]] == false) {
				;
			} else {
				while ((!q.empty()) && q.back() != c[j]) {
					flag[q.back()] = false;
					q.pop_back();
				}
				if (!q.empty()) {
					flag[q.back()] = false;
					q.pop_back();
				}
			}
			q.push_back(c[j]);
			flag[c[j]] = true;
		}
		while (!q.empty()) {
			cnt[q.front() - 1]++;
			q.pop_front();
		}
	}
	for (int i = 0; i < m; i++) {
		cout << cnt[i] << ' ';
	}
	return 0;
}
