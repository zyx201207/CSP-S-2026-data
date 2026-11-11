#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N = 2e6 + 7;
int c, t, x[N];

int max(int a, int b){
	return a > b ? a : b;
}

signed main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);cin.tie(0), cout.tie(0);
	cin >> c >> t;
	while (t--){
		int n, d;
		cin >> n >> d;
		for (int i = 1; i <= n; i++) cin >> x[i];
		
//		cout << "n = " << n << " d = " << d << "  ²îÖµy = " << x[2] - x[1] << "\n"; 
//		cout << x[2] << " " << x[1] << "\n";
		
		int y = x[2] - x[1];
		int b = 2 * d / y;
		if (d < 2 * y) cout << "0\n";
		else cout << max(0, n - b + 1) << "\n";
	}
	return 0;
}
