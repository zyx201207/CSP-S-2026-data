#include<bits/stdc++.h>
using namespace std;
string c1, s1, c2, s2;
bool f1(char c) {
	if (c == 'A' || c == 'B' || c == 'C') return true;
	return false;
}
bool f2(char c) {
	if (c == 'D' || c == 'F') return true;
	return false;
}
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2) cout << 1;
	else cout << 0;
	if (s1[0] == s2[0] && s1[1] == s2[1] && c1 == c2) cout << 1;
	else cout << 0;
	if (f1(s1[2]) != f2(s2[2]) && c1 == c2 && s1[0] == s2[0] && s1[1] == s2[1]) cout << 1;
	else cout << 0;
	if (s1[2] > s2[2]) swap(s1, s2);
	if ((s1[2] == 'A' && s2[2] == 'B' || s1[2] == 'B' && s2[2] == 'C' || s1[2] == 'D' && s2[2] == 'F') && c1 == c2 && s1[0] == s2[0] && s1[1] == s2[1]) cout << 1;
	else cout << 0; 
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
