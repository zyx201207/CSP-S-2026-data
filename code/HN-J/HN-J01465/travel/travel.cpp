#include<bits/stdc++.h>
using namespace std;
int num1, num2;
string s1, s2;
void solve() {
	cin >> num1 >> s1 >> num2 >> s2;
	if (num1 != num2) {
		cout << "0000";
	} else {
		if (s1[0] != s2[0] || s1[1] != s2[1]) {
			cout << "1000";
		} else {
			if ((s1[2] <= 'C' && s2[2] >= 'D') || (s1[2] >= 'D' && s2[2] <= 'C')) {
				cout << "1100";
			} else {
				char ch1 = s1[2], ch2 = s2[2];
				if (ch1 > ch2) {
					swap(ch1, ch2);
				}
				if ((ch1 == 'A' && ch2 == 'B') || (ch1 == 'B' && ch2 == 'C') || (ch1 == 'D' && ch2 == 'F')) {
					cout << "1111";
				} else {
					cout << "1110";
				}
			}
		}
	}
}
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout); 
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
	int T = 1;
//	cin >> T;
	while (T--) {
		solve();
	}
} 
