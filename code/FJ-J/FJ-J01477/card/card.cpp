#include <bits/stdc++.h>
using namespace std;
int n, m, a[500001], ans[500001];
int a1[500001];
void clear() {
	for(int i = 1; i <= n; i++) a1[i] = 0;
}
void del(int l, int r) {
	for(int i = l; i <= r; i++) {
		a1[i] = 0;
	}
}
void copy(int start) {
	int k = 1;
	for(int i = start; i <= n; i++) {
		a1[k] = a[i];
		k++;
	}
}
void game(int x) {
	clear(); copy(x);
	if(x == n) {
		ans[a[n]]++;
		return;
	}
	for(int l = x; l <= n-1; l++) {
		for(int r = l+1; r <= n; r++) {
			if(a1[l] == a1[r]) {
				del(l, r-1);
			}
		}
	}
	for(int i = 1; i <= n; i++) {
		ans[a1[i]]++;
	}
	
}
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) {
		game(i);
	}

	for(int i = 1; i <= m; i++) {
		cout << ans[i] << ' ';
	}
	return 0;
}