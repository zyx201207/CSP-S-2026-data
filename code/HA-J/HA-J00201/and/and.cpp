#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	long long n, m, a[200005], maxn = -1;
	cin >> n >> m;
	for (long long i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	if (m == 1) cout << a[n];
	if (m == n) {
		long long ans = 1;
		for (long long i = 1; i <= n; i++) {
			ans &= a[i];
		}
		cout << ans << endl;
	} 
	if (m == 2) {
		for (long long i = 1; i <= n; i++) {
			for (long long j = 1; j <= n; j++) {
				if (i == j) continue;
				if ((a[i] & a[j]) >= maxn) {
					maxn = (a[i] & a[j]);
				}
			}
		}
		cout << maxn << endl;
	}
	if (m == 3) {
		for (long long i = 1; i <= n; i++) {
			for (long long j = 1; j <= n; j++) {
				for (long long k = 1; k <= n; k++) {
					if (i == j || j == k || k == i) continue;
					if ((a[i] & a[j] & a[k]) >= maxn) {
						maxn = (a[i] & a[j] & a[k]);
					}
				}
			}
		}
		cout << maxn << endl;
	}
	if (m == 4) {
		for (long long i = 1; i <= n; i++) {
			for (long long j = 1; j <= n; j++) {
				for (long long k = 1; k <= n; k++) {
					for (long long l = 1; l <= n; l++) {
						if (i == j || i == k || i == l || j == k || j == l || k == l) continue;
						if ((a[i] & a[j] & a[k] & a[l]) >= maxn) {
							maxn = (a[i] & a[j] & a[k] & a[l]);
						}
					}
				}
			}
		}
		cout << maxn << endl;
	}
	if (m == 5) {
		for (long long i = 1; i <= n; i++) {
			for (long long j = 1; j <= n; j++) {
				for (long long k = 1; k <= n; k++) {
					for (long long l = 1; l <= n; l++) {
						for (long long r = 1; r <= n; r++) {
							if (i == j || i == k || i == l || i == r ||j == k || j == l || j == r|| k == l || k == r || l == r) continue;
							if ((a[i] & a[j] & a[k] & a[l] & a[r]) >= maxn) {
								maxn = (a[i] & a[j] & a[k] & a[l] & a[r]);
							}
						}
					}
				}
			}
		}
		cout << maxn << endl;
	}
	if (m == 6) {
		for (long long i = 1; i <= n; i++) {
			for (long long j = 1; j <= n; j++) {
				for (long long k = 1; k <= n; k++) {
					for (long long l = 1; l <= n; l++) {
						for (long long r = 1; r <= n; r++) {
							for (long long o = 1; o <= n; o++) {
								if (i == j || i == k || i == l || i == r || i == o ||j == k || j == l || j == r || j == o || k == l || k == r || k == o|| l == r || l == o || r == o) continue;
								if ((a[i] & a[j] & a[k] & a[l] & a[r] & a[o]) >= maxn) {
									maxn = (a[i] & a[j] & a[k] & a[l] & a[r] & a[o]);
								}
							}
						}
					}
				}
			}
		}
		cout << maxn << endl;
	}
	if (m == 7) {
		for (long long i = 1; i <= n; i++) {
			for (long long j = 1; j <= n; j++) {
				for (long long k = 1; k <= n; k++) {
					for (long long l = 1; l <= n; l++) {
						for (long long r = 1; r <= n; r++) {
							for (long long o = 1; o <= n; o++) {
								for (long long q = 1; q <= n; q++) {
									if (i == j || i == k || i == l || i == r || i == o || i == q ||j == k || j == l || j == r || j == o || j == q || k == l || k == r || k == o || k == q || l == r || l == o || l == q || r == o || r == q || o == q) continue;
									if ((a[i] & a[j] & a[k] & a[l] & a[r] & a[o] & a[q]) >= maxn) {
										maxn = (a[i] & a[j] & a[k] & a[l] & a[r] & a[o] & a[q]);
									}
								}
							}
						}
					}
				}
			}
		}
		cout << maxn << endl;
	}
	if (m == 8) {
		for (long long i = 1; i <= n; i++) {
			for (long long j = 1; j <= n; j++) {
				for (long long k = 1; k <= n; k++) {
					for (long long l = 1; l <= n; l++) {
						for (long long r = 1; r <= n; r++) {
							for (long long o = 1; o <= n; o++) {
								for (long long q = 1; q <= n; q++) {
									for (long long b = 1; b <= n; b++)
										if (i == j || i == k || i == l || i == r || i == o || i == q || i == b ||j == k || j == l || j == r || j == o || j == q || j == b || k == l || k == r || k == o || k == q || k == b|| l == r || l == o || l == q || l == b || r == o || r == q || r == b|| o == q || o == b || q == b) continue;
										if ((a[i] & a[j] & a[k] & a[l] & a[r] & a[o] & a[q] & a[b]) >= maxn) {
											maxn = (a[i] & a[j] & a[k] & a[l] & a[r] & a[o] & a[q] & a[b]);
										}
								}
							}
						}
					}
				}
			}
		}
		cout << maxn << endl;
	}
	return 0;
}
