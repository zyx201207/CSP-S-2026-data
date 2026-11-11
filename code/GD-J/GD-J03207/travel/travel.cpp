//100 pts
#include<bits/stdc++.h>
using namespace std;
//#define ll long long
//#define pii pair<int,int>
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7; //998244353
string c1, s1, c2, s2;
void q1(string a, string b) {
	if (a == b) cout << 1;
	else cout << 0;
	return ;
}
void q2(string a, string b, string c, string d) {
	string b2 = b.substr(0, 2), d2 = d.substr(0, 2);
	if (a == c && b2 == d2) cout << 1;
	else cout << 0;
	return ;
}
void q3(string a, string b, string c, string d) {
	string b2 = b.substr(0, 2), d2 = d.substr(0, 2);
	char b1 = b[2], d1 = d[2];
	if (a == c && b2 == d2) {
		if ((b1 == 'A' || b1 == 'B' || b1 == 'C') && (d1 == 'A' || d1 == 'B' || d1 == 'C')) {
			cout << 1;
		} else if ((b1 == 'D' || b1 == 'F') && (d1 == 'D' || d1 == 'F')) {
			cout << 1;
		} else {
			cout << 0;
		}
	} else {
		cout << 0;
	}
	return ;
}
void q4(string a, string b, string c, string d) {
	string b2 = b.substr(0, 2), d2 = d.substr(0, 2);
	char b1 = b[2], d1 = d[2];
	if (a == c && b2 == d2) {
		if ((b1 == 'A' || b1 == 'B' || b1 == 'C') && (d1 == 'A' || d1 == 'B' || d1 == 'C')) {
			if ((b1 == 'A' && d1 == 'B') || (b1 == 'B' && d1 == 'C')) {
				cout << 1;
			} else if ((d1 == 'A' && b1 == 'B') || (d1 == 'B' && b1 == 'C')) {
				cout << 1;
			} else {
				cout << 0;
			}
		} else if ((b1 == 'D' || b1 == 'F') && (d1 == 'D' || d1 == 'F')) {
			if (b1 == 'D' && d1 == 'F') {
				cout << 1;
			} else if (d1 == 'D' && b1 == 'F') {
				cout << 1;
			} else {
				cout << 0;
			}
		} else {
			cout << 0;
		}
	} else {
		cout << 0;
	}
	return ;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	q1(c1, c2);
	q2(c1, s1, c2, s2);
	q3(c1, s1, c2, s2);
	q4(c1, s1, c2, s2);
	return 0;
}
