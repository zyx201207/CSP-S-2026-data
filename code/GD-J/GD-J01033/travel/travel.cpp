#include <bits/stdc++.h>
using namespace std;
using ll = long long;

string s1, s2, s3, s4;

void solve() {
	cin >> s1 >> s2 >> s3 >> s4;
	if(s1 != s3) {
		cout << "0000";
		return;
	}
	if(s2.substr(0, 2) != s4.substr(0, 2)) {
		cout << "1000";
		return;
	}
	if(!((s2[2] <= 'C' && s4[2] <= 'C') || (s2[2] >= 'D' && s4[2] >= 'D'))) {
		cout << "1100";
		return;
	}
	if(abs(s2[2] - s4[2]) != 1) {
		cout << "1110";
		return;
	}
	else cout << "1111";
	return;
}

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	solve();
	
	return 0;
} 
