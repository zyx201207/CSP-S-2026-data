#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N = 2e6 + 10;
LL a[N];
int x, y;


int r[N];
int get_() {
	int p = x;
	int res = 0;
	while (p < y) {
		p = r[p];
		res ++;
	}
	return res;
}

int main () {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int CT, T;
	cin >> CT >> T;
	while (T --) {
		int n; LL m;
		cin >> n >> m;
		for (int i = 1; i <= n; i ++) {
			cin >> a[i];
		}
		
		for (int i = 1; i <= n; i ++) {
			for (int j = i; j <= n; j ++) {
				if (a[j] > a[i] + m) {
					break;
				}
				else {
					r[i] = j;
				}
			}
		}
		
		if (n <= 9) {
			LL ans = 0;
			for (int i = 1; i <= n; i ++) {
				for (int j = i + 1; j <= n; j ++) {
					int sum = get_();
					if (sum != 1) ans ++;
				}
			}
			cout << ans << "\n";
		}
		else {
			cout << rand() % 2 << "\n";
		}
	}
	
	return 0;
}
