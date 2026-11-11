#include <bits/stdc++.h>
using namespace std;

int n;

int main (){
	freopen ("string.in", "r", stdin);
	freopen ("string.out", "w", stdout);
	cin.tie (nullptr) -> sync_with_stdio (false);
	cin >> n;
	string s = " ";
	for (int i = 1; i <= n; i++){
		int a;
		char c;
		cin >> a >> c;
		for (int j = 1; j <= a; j++){
			s = s + c;
		}
	}
	int l = s.size () - 1;
	if (l % 2 == 1){
		long long m = (l + 1) / 2, ans = 0;
		for (int i = 1; i <= m - 1; i++){
			if (s [m - i] != s [m + i]){
				ans++;
			}
		}
		cout << ans;
	}
	else {
		long long ans = 0, m1 = l / 2, m2 = l / 2 + 1;
		for (int i = 0; i <= m1 - 1; i++){
			if (s [m1 - i] != s [m2 + i]){
				ans++;
			}
		}
		cout << ans;
	}
	return 0;
}
