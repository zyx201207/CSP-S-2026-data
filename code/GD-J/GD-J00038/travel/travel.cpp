#include <iostream>

using namespace std;

string s1, c1, s2, c2;
int to[256];

bool check(char x, char y, char z) {
	return (x >= y and x <= z);
}

void init() {
	to['A'] = 1;
	to['B'] = 2;
	to['C'] = 3;
	to['D'] = 4;
	to['F'] = 5;
}

int Abs(int x) {
	return x < 0 ? -x : x;
}

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	cin >> s1 >> c1 >> s2 >> c2;
	
	init();
	
	if (s1 == s2) {
		string t1 = "  ";
		t1[0] = c1[0];
		t1[1] = c1[1];
		string t2 = "  ";
		t2[0] = c2[0];
		t2[1] = c2[1];
		if (t1 == t2) {
			char seat1 = c1[2], seat2 = c2[2];
			if ((check(seat1, 'A', 'C') and check(seat2, 'A', 'C')) or (check(seat1, 'D', 'F') and check(seat2, 'D', 'F'))) {
				if (Abs(to[(int)seat1] - to[(int)seat2]) == 1) {
					cout << "1111" << '\n';
				} else {
					cout << "1110" << '\n';
				}
			} else {
				cout << "1100" << '\n';
			}
		} else {
			cout << "1000" << '\n';
		}
	} else {
		cout << "0000" << '\n';
	}
	
	return 0;
}

