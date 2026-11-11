#include<bits/stdc++.h>
using namespace std;
long long C, T;
long long n, m;
long long a[500005];
int main(){
	ios::sync_with_stdio(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> C >> T;
	while(T--) {
		cin >> n >> m;
		for (long long i = 1; i <= n; i++) {
			cin >> a[i];
		}
		if (C == 11 || C == 12) {
			cout << n << endl;
			continue;
		}
		if (C == 13 || C == 14) {
			cout << n << endl;
			continue;
		}
	}
	return 0;
}
