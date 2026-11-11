#include <iostream>
#include <string>
using namespace std;
int toi(char c) {
	if (c == 'A') return 0;
	if (c == 'B') return 1;
	if (c == 'C') return 2;
	if (c == 'D') return 14;
	if (c == 'F') return 15;
	return -114514;
}
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string s1, s2, s3, s4;
	cin >> s1 >> s2 >> s3 >> s4;
	int tr1 = 10 * (s1[0] - '0') + (s1[1] - '0');
	int	tr2 = 10 * (s3[0] - '0') + (s3[1] - '0');
	if (tr1 != tr2) {
		cout << "0000";
		return 0;
	}
	else
	{
		cout << 1;
	}
	int f1 = 10 * (s2[0] - '0') + (s2[1] - '0');
	int f2 = 10 * (s4[0] - '0') + (s4[1] - '0');
	if (f1 != f2) {
		cout << "000";
		return 0;
	}
	else {
		cout << 1;
	}
	int c1 = toi(s2[2]), c2 = toi(s4[2]);
	if (max(c1, c2) - min(c1, c2) > 10) {
		cout << "00";
		return 0;
	}
	else {
		cout << 1;
	}
	if (max(c1, c2) - min(c1, c2) != 1) {
		cout << 0;
		return 0;
	}
	else {
		cout << 1;
	}
	return 0;
}

