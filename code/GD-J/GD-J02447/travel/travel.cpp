#include <bits/stdc++.h>

using namespace std;

string c1, s1, c2, s2;
int column[3];
void init() {
	column[1] = (s1[0] - '0') * 10 + (s1[1] - '0');
	column[2] = (s2[0] - '0') * 10 + (s2[1] - '0');
}
bool condition3() {
	if (s1[2] <= 'C' && s2[2] <= 'C') return true;
	else if (s1[2] >= 'D' && s2[2] >= 'D') return true;
	return false;
}
bool condition4() {
	if (s1[2] == 'D' || s2[2] == 'D') return true;
	else if (s1[2] == 'B' || s2[2] == 'B') return true;
	return false;
}
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout); 
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> c1 >> s1 >> c2 >> s2;
	init();
	if (c1 == c2) {//同车厢 
		cout << 1;
		if (column[1] == column[2]) {//同排 
			cout << 1;
			if (condition3()) {//通道的同侧 
				cout << 1;
				if (condition4()) {//相邻 
					cout << 1 << '\n';
				} else {//不是相邻 
					cout << "0" << '\n';
				}
			} else {//不是通道的同侧 
				cout << "00" << '\n';
			}
		} else {//不是同排 
			cout << "000" << '\n';
		}
	} else {//不是同车厢 
		cout << "0000" << '\n';
	}
} 
