#include <bits/stdc++.h>
#include <string>
using namespace std;

int rl(char ch) {
	// 1:left  2:right  -1: wrong
	if (ch == 'A' || ch == 'B' || ch == 'C') return 1;
	if (ch == 'D' || ch == 'F') return 2;
	return -1;
}

bool isNear(char ch1, char ch2) {
	int rl1 = rl(ch1), rl2 = rl(ch2);
	if (rl1 != rl2) printf("上一步出问题了!!!\n");
	if (rl1 == 1 && rl2 == 1 && abs(ch1 - ch2) == 1) return true;
	if (rl1 == 2 && rl2 == 2) return true;
	return false;
}

string travel(string c1, string s1, string c2, string s2) {
	string res = "0000";
	if (c1 != c2) return res;
	res[0] = '1';
	if (s1[0] != s2[0] || s1[1] != s2[1]) return res;
	res[1] = '1';
	if (rl(s1[2]) != rl(s2[2])) return res;
	res[2] = '1';
	if (!isNear(s1[2], s2[2])) return res;
	res[3] = '1';
	return res; 
}

int main() {
	freopen("treavel.in", "r", stdin);
	freopen("treavel.out", "w", stdout);
	
	string c1,s1,c2,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	cout << travel(c1, s1, c2, s2) << endl;
	
	return 0;
} 
