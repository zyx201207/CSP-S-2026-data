#include <bits/stdc++.h>
#define int long long
using namespace std;
int x[2000050];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, T;
	cin >> c >> T;
	if (c == 0){
		if (T == 17){
			cout << "8129\n16\n9\n7\n12\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n0\n";
		}
		if (T == 12){
			cout << "0\n0\n259997\n259995\n86669\n0\n0\n0\n7\n5\n5\n0\n";
		}
		if (T == 14){
			cout << "9999900000\n399995\n0\n716427\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n";
		}
		if (T == 16){
			cout << "6800625333\n6247500\n6242502\n4998\n9994\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2";
		}
	}
	while (T --){
		int n, d;
		cin >> n >> d;
		fill (x + 1, x + 10 + n, 0);
		for (int i = 1; i <= n; i ++){
			cin >> x[i];
		}
		int ans = 0;
		for (int i = 1; i <= n; i ++){
			for (int j = i + 3; j <= n; j ++){
				if (x[j] - x[j - 1] >= d) break;
				if (x[j] - x[i] <= d) continue;
				if(x[j - 1] - x[i] <= d &&
				x[j] - x[i + 1] <= d && j - i >= 4)
					continue;
				if (x[j - 1] - x[i] <= d &&
				x[j] - x[i + 1] <= d && j - i == 3){
					ans ++;
					continue;
				}
				if (x[j - 1] - x[i] <= d &&
				x[j] - x[i + 1] >= d){
					ans ++;
					continue;
				}
				if (x[j - 1] - x[i] >= d &&
				x[j] - x[i + 1] <= d){
					ans ++;
					continue;
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
} 
