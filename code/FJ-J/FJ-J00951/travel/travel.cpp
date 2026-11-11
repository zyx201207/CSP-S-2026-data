#include <bits/stdc++.h>
using namespace std;
string a, b, c, d;
int chk1() {
	if (a == c) return 1;
	else return 0;
}
int chk2() {
	if (!chk1()) return 0;
	else if (b.substr(0, 2) == d.substr(0, 2)) return 1;
	else return 0;
}
int chk3() {
	if (!chk2()) return 0;
	else if ((b[2] == 'A' || b[2] == 'B' || b[2] == 'C') && (d[2] == 'D' || d[2] == 'E')) return 0;
	else if ((d[2] == 'A' || d[2] == 'B' || d[2] == 'C') && (b[2] == 'D' || b[2] == 'E')) return 0;
	else return 1;
}
int chk4() {
	if (!chk3()) return 0;
	else if (b[2] == 'A' && d[2] == 'B') return 1;
	else if (b[2] == 'B' && (d[2] == 'A' || d[2] == 'C')) return 1;
	else if (b[2] == 'C' && d[2] == 'B') return 1;
	else if (b[2] == 'D' && d[2] == 'E') return 1;
	else if (b[2] == 'E' && d[2] == 'D') return 1;
	else return 0;
}
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> a >> b >> c >> d;
	cout << chk1() << chk2() << chk3() << chk4();
	return 0;
} 
