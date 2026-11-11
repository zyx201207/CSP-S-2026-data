#include<bits/stdc++.h>
using namespace std;
#define int long long
string sr1, sr2, sx1, sx2;
signed main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> sr1 >> sr2 >> sx1 >> sx2;
	if (sr1[0] == sx1[0] && sr1[1] == sx1[1]) {
		cout << "1";
	} else {
		cout << "0000";
		return 0;
	}
	if (sr2[0] == sx2[0] && sr2[1] == sx2[1]) {
		cout << "1";
	} else {
		cout << "000";
		return 0;
	}
	if ((sr2[2] == 'A' || sr2[2] == 'B' || sr2[2] == 'C') && (sx2[2] == 'A' || sx2[2] == 'B' || sx2[2] == 'C')) {
		cout << "1";
	} else if ((sr2[2] == 'D' || sr2[2] == 'F') && (sx2[2] == 'D' || sx2[2] == 'F')) {
		cout << "1";
	} else {
		cout << "00";
		return 0;
	}
	if ((sr2[2] == 'C' && sx2[2] == 'A') || (sr2[2] == 'A' && sx2[2] == 'C')) {
		cout << "0";
	} else {
		cout << "1";
	}
	return 0;
}
