#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2e5 + 5;

int n, m;

ll a[N];

int num_of_zero[45];

bool influence[N][45];

ll ans = -0x7fffffff;

void dfs (int k, ll result, int step) {
	if (step == m) {
		ans = max (ans, result);
		return ;
	}
	for (int i = k; i <= n; i++) {
		dfs (i + 1, result & a[i], step + 1);
	}
	return ;
}
bool be_used[N];
int main () {
	freopen ("and.in", "r", stdin);
	freopen ("and.out", "w", stdout);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort (a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++) {
		ll v = a[i], BIT = 0;
		while (v) {
			BIT++;
			int p = v % 2;
			v /= 2;
			num_of_zero[BIT] += (!p);
			influence[i][BIT] = p;
		}
		BIT++;
		for (; BIT <= 31; BIT++) {
			num_of_zero[BIT]++;
		}
	}
	if (n * n * m <= 10000000) {
		for (int i = 1; i <= n - m + 1; i++) {
			dfs (i + 1, a[i], 1); 
		}
		cout << ans;
	}
	else {
		int ch = n - m;
		for (int i = 31; i >= 1; i--) {
			if (num_of_zero[i] > ch) {
				continue;
			}
			int z = 0;
			for (int j = 1; j <= n; j++) {
				z += (!influence[j][i]);
			}
			if (z < num_of_zero[i]) continue;
			if (z >= num_of_zero[i]) {
				ch -= z;
				for (int j = 1; j <= n; j++) {
					if (!influence[j][i]) {
						for (int k = 1; k <= 31; k++) {
							num_of_zero[k] -= (!influence[j][k]);
						}
					}
				}
			}
		}
		ll ans1 = 0;
		for (int i = 31; i >= 1; i--) {
			ans1 *= 2;
			if (num_of_zero[i] <= 0) {
				ans1 ++;
			}
		}
		cout << ans1;
	}
	return 0;
}
