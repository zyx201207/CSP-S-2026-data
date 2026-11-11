#include<bits/stdc++.h>
#define For(i, x, y) for (int i = x; i <= (int)y; i++)
#define foR(i, x, y) for (int i = x; i >= (int)y; i--)
#define fin(x) freopen(x, "r", stdin)
#define fou(x) freopen(x, "w", stdout)
#define fre(x) fin(x".in"); fou(x".out");
#define ios cin.tie(0) -> sync_with_stdio(false);
#define itn int
#define tin int
#define tni int
#define nti int
#define nit int
#define imnt int
#define inmt int
using ll = long long;
using lll = __int128_t;
using namespace std;
int side(char x) {
	switch (x) {
		case 'A':
			return 1;
		case 'B':
			return 1;
		case 'C':
			return 1;
		case 'D':
			return 2;
		case 'F':
			return 2;
	}
}
bool chk(char x, char y) {
	if (x == 'A' && y == 'B' || x == 'B' && y == 'C' || x == 'D' && y == 'F') return true;
	swap(x, y);
	if (x == 'A' && y == 'B' || x == 'B' && y == 'C' || x == 'D' && y == 'F') return true;
	return false;
}
int main() {
	fre("travel")
	ios
	int id1, id2;
	string s1, s2;
	cin >> id1 >> s1 >> id2 >> s2;
	if (id1 != id2) cout << "0000";
	else {
		int num1, num2;
		char a1, a2;
		num1 = (s1[0] - '0') * 10 + (s1[1] - '0');
		num2 = (s2[0] - '0') * 10 + (s2[1] - '0');
		a1 = s1[2], a2 = s2[2];
		if (num1 != num2) cout << "1000";
		else if (side(a1) != side(a2)) cout << "1100";
		else if (!chk(a1, a2)) cout << "1110";
		else cout << "1111";
	}
}
