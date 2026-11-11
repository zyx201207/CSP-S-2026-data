#include<bits/stdc++.h>
using namespace std;

string a, b, c, d;

signed main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> a >> b >> c >> d;
	if(a == c) {
		cout << 1;
		if(b[0] + b[1] == d[0] + d[1]) {
			cout << 1;
			if(b[2] <= 'C' && d[2] <= 'C') {
				cout << 1;
				if(b[2] + 1 == d[2] || d[2] + 1 == b[2]) cout << 1;
				else cout << 0;
			}
			else if(b[2] >= 'D' && d[2] >= 'D') cout << "11";
			else cout << "00";
		}
		else cout << "000";
	}
	else cout << "0000";
	return 0;
}

