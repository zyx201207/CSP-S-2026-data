#include<bits/stdc++.h>
using namespace std;
string c1, s1, c2, s2;
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2) cout << 1;
	else {
		cout << "0000";
		return 0;
	}
	string p1, p2;
	p1 = s1[0] + s1[1];
	p2 = s2[0] + s2[1];
	if(p1 == p2) cout << 1;
	else {
		cout << "000";
		return 0;
	}
	bool l1 = (s1[2] <= 'C');
	bool l2 = (s2[2] <= 'C'); 
	if(l1 == l2) cout << 1;
	else {
		cout << "00";
		return 0;
	}
	s1[2] = (s1[2] == 'D' ? 'E' : s1[2]);
	s2[2] = (s2[2] == 'D' ? 'E' : s2[2]);
	if(abs(s1[2] - s2[2]) == 1) cout << 1;
	else cout << 0;
	return 0; 
}
