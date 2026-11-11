#include<bits/stdc++.h>
#define int long long
const int N = 2e5 + 10;
using namespace std;
int n, a[N], ans;
char c[N];
signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	string s;
	for(int i = 1; i <= n; i++) {
		cin >> a[i] >> c[i];
		for(int j = 1; j <= a[i]; j++) {
			s += c[i];
		}
	}
	string c = s;
	reverse(c.begin(), c.end());
	if(c == s) {
		cout << 0;
	}
	else{
		for(int i = 0; i < s.size(); i++) {
			if(s[i] != c[i]) ans++;
		}
		cout << ans / 2;
	}
	return 0; 
}
/*

5
1 a
1 b
1 c
1 b
1 a
*/
