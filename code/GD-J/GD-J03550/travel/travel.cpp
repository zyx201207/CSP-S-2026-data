#include<bits/stdc++.h>
using namespace std;
string s;
string v;
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int a, b;
	int c = 0, d = 0;
	char e, f;
	cin >> a >> s >> b >> v;
	e = s[2];
	f = v[2];
	if (a == b) { //同一列车厢 
		cout << 1;
	}
	else {
		cout << "0000";
		return 0;
	}
	if ((a == b) && (s[0] == v[0] && s[1] == v[1])) { // 同一排 
		cout << 1;	
	} 
	else {
		cout << 0;
	}
	if ((s[0] == v[0] && s[1] == v[1]) && (((e == 'A' || e == 'B' || e == 'C') && (f == 'A' || f == 'B' || f == 'C')) || ((e == 'D' || f == 'F') && (e == 'F' || e == 'D')))) { //判同一侧   
		cout << 1;
	}
	else {
		cout << 0;
	}
	if ((e == 'C' && f == 'D') || (e == 'D' && f == 'C')) {
		cout << 0;
		return 0;
	} else {
		if (e + 1 == (int)f) {
			cout << 1;
		}else {
			cout << 0;
			return 0;
		}
	}
	return 0;
}
