#include<bits/stdc++.h>
using namespace std;
string c, s, cc, ss;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> c >> s >> cc >> ss;
	if (c == cc) {
		cout << 1;
		if (s[0] + s[1] == ss[0] + ss[1]) {
			cout << 1;
			if ((s[2] >= 'A' && s[2] <= 'C') && (ss[2] >= 'A' && ss[2] <= 'C')) {
				cout << 1;
				if (s[2] > ss[2]) {
					if (s[2] - 1 == ss[2]) cout << 1;
					else cout << 0;
				} 
				else {
					if (ss[2] - 1 == s[2]) cout << 1;
					else cout << 0; 
				}
			}
			else if ((s[2] >= 'D' && s[2] <= 'E') && (ss[2] >= 'D' && ss[2] <= 'E')) {
				cout << 1;
			}
			else {
				cout << "00";
			}
		}
		else {
			cout << "000";
		}
	}
	else {
		cout << "0000";
	}
} 
//c, s, cc, ss分别表示小 R 的车票上的车厢号、座位号 以及小 X 的车票上的车厢号、座位号
