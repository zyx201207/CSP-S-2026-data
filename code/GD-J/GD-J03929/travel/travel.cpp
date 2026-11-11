#include <bits/stdc++.h>
#define inc(i, l, r) for(int i = l; i <= r; ++i)
#define dec(i, l, r) for(int i = l; i >= r; --i)
using namespace std;

string ans = "0000";
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(nullptr);
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2) {
		ans[0] = '1';
	}
	if((s1.substr(0, 2) == s2.substr(0, 2)) && (ans[0] == '1')) {
		ans[1] = '1';
	}
	if((('A' <= s1[2] && s1[2] <= 'C') && ('A' <= s2[2] && s2[2] <= 'C')) && (ans[1] == '1')) {
		ans[2] = '1'; 
	} else if((('D' <= s1[2] && s1[2] <= 'F') && ('D' <= s1[2] && s1[2] <= 'F')) && (ans[1] == '1')) {
		ans[2] = '1'; 
	}
	
	if((ans[2] == '1') && abs(s1[2] - s2[2]) == 1) {
		ans[3] = '1';
	}
	cout << ans << '\n';
	return 0;
} 
