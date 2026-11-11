#include <bits/stdc++.h>
#define ll long long
using namespace std;
string s1, s2, s3, s4;
int work(string s) {
	int sum = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			sum = sum * 10 + (s[i] - '0');
		}
	}
	return sum;
}
int main() {
	freopen ("travel.in", "r", stdin);
	freopen ("travel.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> s1 >> s2 >> s3 >> s4;
	int a = work(s1), b = work(s2), c = work(s3), d = work(s4);
	int e = s2[2] - 'A' + 1, f = s4[2] - 'A' + 1;
	if (a == c) {
		cout << 1;
		if (b == d) {
			cout << 1;
			if ((e >= 1 && e <= 3 && f >= 1 && f <= 3) || (e >= 4 && e <= 5 && f >= 4 && f <= 5)) {
				cout << 1;
				if (abs(e - f) == 1) cout << 1;
				else cout << 0;
			}else cout << "00";
		} else {
			cout << "000";
		}
	} else cout << "0000";
	return 0;
} 
