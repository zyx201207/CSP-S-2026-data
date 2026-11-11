#include<bits/stdc++.h> 
using namespace std;

#define endl "\n"

int change(string s) {
	int res = 0;
	for (int i = 0; i < s.size(); ++i) {
		res = res * 10 + (s[i] - '0');
	}
	return res;
}
void solve() {
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	int id1 = change(c1), id2 = change(c2);
	if (id1 == id2) {
		cout << 1;
	} else {
		cout << "0000";
		return;
	}
	int r1 = change(s1.substr(0, 2)), r2 = change(s2.substr(0, 2));
	if (r1 == r2) {
		cout << 1;
	} else {
		cout << "000";
		return;
	}
	char a1 = s1[2], a2 = s2[2];
	if ((a1 == 'D' && a2 == 'F') || (a1 == 'F' && a2 == 'D') || ('A' <= a1 && a1 <= 'C' && 'A' <= a2 && a2 <= 'C')) {
		cout << 1;
	}
	else {
		cout << "00";
		return;
	}
	
	if ((a1 == 'D' && a2 == 'F') || (a1 == 'F' && a2 == 'D') || ('A' <= a1 && a1 <= 'C' && 'A' <= a2 && a2 <= 'C' && abs(a1 - a2) <= 1)) {
		cout << 1;
	}
	else {			
		cout << "0";
		return;
	}
}
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}
