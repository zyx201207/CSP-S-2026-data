#include <cstdio>
#include <iostream>
using namespace std;
int c, t;
int n, m;
long long d, k, l;
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> t;
	while(t--){
		cin >> n >> d;
		m = n - 2;
		long long a, b;
		cin >> a >> b;
		k = b - a;
		while(m--){
			long long x;
			cin >> x;
		}
		if(k < 2 * d) cout << "0\n";
		else{
			l = k / d;
			n -= (l - 1);
			cout << n << '\n';
		}
	}
	return 0;
}
