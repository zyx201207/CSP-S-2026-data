#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const int N = 1e5 + 10;
int a[2 * N];

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int hhh;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int maxx = 0;
	if(m == 2) {
		for(int i = 1; i <= n; i++) {
			for(int j = i; j <= n; j++) {
				maxx = max(maxx, a[i] & a[j]);
			}
		}
	}
	if(m == 1) {
		for(int i = 1; i <= n; i++) {
			maxx = max(a[i], maxx);
		}
	}
	else {
		if(m == n) {
			maxx = a[1];
			for(int i = 1; i <= n; i++) {
				maxx &= a[i];
			}
		}
		if(m == n - 1) {
			for(int i = 1; i <= n; i++) {
				for(int j = 1; j <= n; j++) {
					if(j == i) {
						maxx = a[j + 1];
						continue;
					}
				}
			}
		}
	}

	return 0;
}

