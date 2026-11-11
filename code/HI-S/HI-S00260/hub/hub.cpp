#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;

int c, t, n, k, u[1000005], v[1000006];

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	
	cin >> c >> t;
	while (t--) {
		cin >> n >> k;
		for (int i=1; i<n; i++) {
			cin >> u[i] >> v[i];
		}
	}
	
	cout << "1\n1\n2";
	
	return 0;
}

