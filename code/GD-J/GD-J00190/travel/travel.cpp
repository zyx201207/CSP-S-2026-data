#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
string s1, s2, s3, s4;
signed main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> s1 >> s2 >> s3 >> s4;
	if(s1 != s3) {
		cout << "0000";
		return 0;
	}
	cout << "1";
	if(s2[0] - '0' == s4[0] - '0' && s2[1] - '0' == s4[1] - '0') {
		cout << "1";
		if( 'A' <= s2[2] && 'C' >= s2[2] ) {
			if( s4[2] >= 'D' && s4[2] <= 'F' ) {
				cout << "00";
			}
			else {
				cout << "1";
				if(s2[2] == s4[2] + 1 || s2[2] == s4[2] - 1) cout << "1";
				else cout << "0";
			}
		}
		else {
			if( 'A' <= s2[2] && 'C' >= s2[2] ) {
				cout << "00";
			}
			else {
				cout << "1";
				if(s2[2] == s4[2] + 1 || s2[2] == s4[2] - 1) cout << "1";
				else cout << "0";
			}
		}
	}
	else cout << "000";
}
