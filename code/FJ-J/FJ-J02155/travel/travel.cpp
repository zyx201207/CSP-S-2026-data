#include<bits/stdc++.h>
using namespace std;
string a, b, c, d;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> a >> b >> c >> d;
	if (a != c) {
		cout << "0000";
		return 0;
	}
	if (((a[0] * 10 + a[1]) != 1) && ((a[0] * 10 + a[1]) != 16)) {
		cout << "1";
		if (b[0] == d[0] && b[1] == d[1]) {
			cout << "1";
			if (b[2] == 'A' && d[2] == 'B') {
				cout << "11";
			}else if (b[2] == 'A' && d[2] == 'C') {
				cout << "10";
			}else if (b[2] == 'B' && d[2] == 'C') {
				cout << "11";
			}else if (b[2] == 'D' && d[2] == 'F') {
				cout << "11";
  			}else if (d[2] == 'A' && b[2] == 'B') {
				cout << "11";
			}else if (d[2] == 'A' && b[2] == 'C') {
				cout << "10";
			}else if (d[2] == 'B' && b[2] == 'C') {
				cout << "11";
			}else if (d[2] == 'D' && b[2] == 'F') {
				cout << "11";
			}else{
				cout << "00";
			}
		}else{
			cout << "000";
		}
	}
	return 0;
}
