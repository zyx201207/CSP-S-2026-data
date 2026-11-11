#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
const int M = 3e5 + 5;
int a[N], cnt[M];
int pos[N], last[M];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1;i <= n;i++) {
		cin >> a[i];
	}
	for (int i = n;i >= 1;i--) {
		if (last[a[i]] == 0) last[a[i]] = i;
		else pos[i] = last[a[i]];
	}
	for (int i = 1;i <= n;i++) {
		for (int j = i;j <= n;j++) {
			if (pos[j] != 0) j = pos[j];
			cnt[a[j]]++;
		}
	}
	for (int i = 1;i <= m;i++) {
		cout << cnt[i] << " ";
	}
	return 0;
}
