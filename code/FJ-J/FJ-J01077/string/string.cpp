#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, ans = 0;
vector<pair<char, int> > str;
signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for(int i = 0; i < n; i++) {
		int s; char c;
		cin >> s >> c;
		str.push_back(make_pair(c, s));
	}
	int L = 0, R = str.size() - 1;
	while(L < R) {
		auto x = str[L], y = str[R];
		if(x.first == y.first) {
			if(x.second < y.second) {
				str[R].second -= str[L].second;
				L++;
			} else if(x.second > y.second) {
				str[L].second -= str[R].second;
				R--;
			} else {
				L++;
				R--;
			}
		} else {
			if(x.second >= y.second) {
				ans += y.second;
				str[R].first = x.first;
			} else {
				ans += x.second;
				str[L].first = y.first;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
// ÎªÉ¶ÎÒÄÜ¿¨1h+°¡ 
