#include <bits/stdc++.h>
using namespace std;
char c_1[16], s_1[16], c_2[16], s_2[16];
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	scanf("%s%s%s%s", c_1 + 1, s_1 + 1, c_2 + 1, s_2 + 1);
	if (c_1[1] != c_2[1] || c_1[2] != c_2[2]) {
		cout << "0000" << endl;
	} else {
		cout << "1";
		if (s_1[1] == s_2[1] && s_1[2] == s_2[2]) {
			cout << "1";
			if ((s_1[3] == 'D' && s_2[3] == 'F') || (s_1[3] == 'F' && s_2[3] == 'D') || (s_1[3] == 'A' && s_2[3] == 'B') || (s_1[3] == 'B' && s_2[3] == 'A') || (s_1[3] == 'A' && s_2[3] == 'C') || (s_1[3] == 'C' && s_2[3] == 'A') || (s_1[3] == 'B' && s_2[3] == 'C') || (s_1[3] == 'C' && s_2[3] == 'A'))
				cout << "1";
			else
				cout << "0";
		} else
			cout << "00";
		int a = 0, b = 0, c = 0, d = 0;
		a = (s_1[1] - '0') * 10 + (s_1[2] - '0');
		b = (s_2[1] - '0') * 10 + (s_2[2] - '0');
		c = (s_1[3] - 'A' + 1);
		d = (s_2[3] - 'A' + 1);
		if (abs(b - a) == 1 && c == d)
			cout << "1";
		else
			if (a == b && abs(c - d) == 1 && max(c, d) != 4)
				cout << "1";
			else
				cout << "0";
	}
}
