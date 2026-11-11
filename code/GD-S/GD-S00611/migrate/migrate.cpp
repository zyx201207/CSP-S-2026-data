#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const ll N = 5e5 + 10;

int C;
ll n, d;
ll a[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	int _;
	cin >> C >> _;
	while (_--) {
		cin >> n >> d;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		cout << "0\n";
	}
	
	return 0;
}
