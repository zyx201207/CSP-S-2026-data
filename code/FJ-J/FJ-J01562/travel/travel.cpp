#include<bits/stdc++.h>
#define endl "\n"
#define IOS ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;

int T;
string c1, s1, c2, s2;

void solve() {
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2) {
		cout << "1";
		int rline=0, xline=0;
		for(int i=0; i<=1; i++) {
			rline = rline * 10 + s1[i];
			xline = xline * 10 + s2[i];
		}
		if(rline == xline) {
			cout << "1";
			if((s1[2] <= 'C' && s2[2] <= 'C')||(s1[2] >= 'D' && s2[2] >= 'D')) {
				cout << "1";
				cout << ((abs((int)s1[2] - (int)s2[2]) == 1)?"1":"0")<< endl;
			} else {
				cout << "00" << endl;
			}
		} else {
			cout << "000"<<endl;
		}
	} else {
		cout << "0000" << endl;
	}
	return;
}

signed main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	IOS;
	T = 1;
//	cin >> T;
	while(T--) {
		solve();
	}
	return 0;
}

