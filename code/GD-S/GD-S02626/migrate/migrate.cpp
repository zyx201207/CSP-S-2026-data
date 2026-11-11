#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e3 + 9;
int c, t, n;
ll d, a[N];

int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while (t--){
		cin >> n >> d;
		ll sum = 0;
		for (int i = 1; i <= n; i++) cin >> a[i];
		if (2 * (a[2] - a[1]) > d || n < 4) cout << "0\n";
		else {
			int t = 4;
			while (t <= n){
				sum += n - t + 1;
				t += 2;
			}
			cout << sum << endl;
		}
	}
	return 0;
}
