#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e6 + 10;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	int n;
	cin >> n;
	string s = "";
	for(int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		string a;
		cin >> a;
		while(k--){
			s += a;
		}
	}
	int ans = 0, len = s.size();
	string x = "";
	int idx = 0;
	for(int i = len - 1; i >= 0; i--) {
		x[idx++] = s[i];
	}
	for(int i = 0; i < len; i++) {
		if(s[i] != x[i]) {
			ans++;
		}
	}
	ans /= 2;
	cout << ans << '\n';
	return 0;
}
