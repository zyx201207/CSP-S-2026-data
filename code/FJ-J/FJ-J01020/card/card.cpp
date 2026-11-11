#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 10;

int a[N];

int cnt[N];

int v[N];

int top = 0;

int n, m;

int main() {
	
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);

	cin >> n >> m;
	
	int op = 1;
	
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
		if (1 <= i) {
			if (a[i - 1] > a[i]) {
				op = 0;
			}
		}
	}
	
	if (op == 1) {
		for (int i = 1; i <= n; i ++) {
			if (i == n || a[i] != a[i + 1]) {
				cout << i << " ";
			}
		}
		cout << "\n";
		return 0;
	}
	
	for (int i = 1; i <= n; i ++) {
		memset(v, 0, sizeof(v));
		top = 0;
		for (int j = i; j <= n; j ++) {
			for (int k = 1; k <= top; k ++) {
				if (v[k] == a[j]) {
					top = k - 1;
					break;
				}
			}
			v[++ top] = a[j];
		}
		for (int j = 1; j <= top; j ++) {
			cnt[v[j]] ++;
		}
	}
	
	for (int i = 1; i <= m; i ++) {
		cout << cnt[i] << " ";
	}
	cout << "\n"; 

	return 0;
}

