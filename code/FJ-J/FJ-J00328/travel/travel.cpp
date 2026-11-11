#include <iostream>
#include <string>
using namespace std;
char checkside(char c) {
	if (c == 'A' || c == 'B' || c == 'C') return 'L';
	else return 'R';
}
bool sameside(string c1, string s1, string c2, string s2) {
	if (c1 != c2) return false; 
	if (s1.substr(0, 2) != s2.substr(0, 2)) return false;
	if (checkside(s1[2]) != checkside(s2[2])) return false;
	return true;
}
bool IsNext(string c1, string s1, string c2, string s2) {
	if (!sameside(c1, s1, c2, s2)) return false;
	if ('A' <= (char)(s1[2] - 1) && (char)(s1[2] - 1) <= 'F') if (s2[2] == (char)(s1[2] - 1)) return true;
	else if ('A' <= (char)(s1[2] + 1) && (char)(s1[2] + 1) <= 'F') if (s2[2] == (char)(s1[2] + 1)) return true;
	return false;
}
int main() {
	freopen("travel.in", "r", stdin); freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	cout << (c1 == c2) << (c1 == c2 && s1.substr(0, 2) == s2.substr(0, 2)) << sameside(c1, s1, c2, s2) << IsNext(c1, s1, c2, s2); 
	return 0;
}
