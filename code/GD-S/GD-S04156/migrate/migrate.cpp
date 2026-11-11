#include <iostream>
using namespace std;

const int N = 2e6 + 5;
int c, t;
int n, d, x[N];

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while(t--) {
		bool A = 1;
		cin >> n >> d;
		for(int i = 1; i <= n; i++) {
			cin >> x[i];
		}
		int d1 = x[2] - x[1];
		for(int i = 3; i <= n; i++) {
			if(x[i] - x[i - 1] != d1) A = 0;
		}
		if(A) {
			int lb = lower_bound(x + 1, x + n + 1, d) - x;
			if(d1 > d) cout << 0;
			else cout << n - lb - 1;
		}
	}
}
