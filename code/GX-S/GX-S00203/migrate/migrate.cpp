#include <iostream>

using namespace std;

int n;
long long d;
const int MAXN = 2000000;
long long xs[MAXN];

long long process() {
	long long res;
	int m = d / (xs[1] - xs[0]);
	if (m < 2) {
		res = 0LL;
	} else if (m == 2) {
		res = n*1LL - 3LL;
	} else {
		res = n*1LL - 2LL*m + 1;
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	for(int i = 0; i < t; i++) {
		cin >> n >> d;
		for(int j = 0; j < n; j++) {
			cin >> xs[j];
		}
		cout << process() << endl;
	}
	return 0;
}
