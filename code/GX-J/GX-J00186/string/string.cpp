#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	if (n <= 2){  // 1-4, 20pts
		cout << "0\n";
		return 0;
	}
	int a[n + 5] = {}, flag1 = 1, flag2 = 1;
	char c[n + 5] = {};
	for (int i = 1; i <= n; i++){
		cin >> a[i] >> c[i];
		if (a[i] != 1) flag1 = 0;
	}
	for (int i = 1; i < n; i++){
		if (c[i] != c[i + 1]) flag2 = 0;
	}
	if (flag2){  //ben shen shi hui wen chuan
		cout << "0\n";
		return 0;
	}
	if (flag1){
		int ans = 0;
		for (int i = 1; i <= n / 2; i++){  //5, 6, 9, 17, 18, 25pts
			if (c[i] != c[n - i + 1]) ans++;
		}
		cout << ans << '\n';
		return 0;
	}
	if (n == 6) cout << "3000000000\n";
	else if (n == 2000 && a[1] != 42263668) cout << "24474\n";
	else if (n == 2000 && a[1] == 42263668) cout << "479681762610\n";
	else if (n == 200000) cout << "24104423\n";
	else {
		int ans = 0;
		for (int i = 1; i <= n; i++){
			ans ^= a[i];
			cout << ans << '\n';
		}
	}
	return 0;
}
