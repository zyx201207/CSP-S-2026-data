#include <bits/stdc++.h>
using namespace std;
bool check(char a, char b) {
	if(a > b) swap(a, b);
	if((a == 'A' && b == 'B') || (a == 'A' && b == 'C') || (a == 'B' && b == 'C') || (a == 'D' && b == 'E')) return 1;
	return 0;
}
bool check1(char a, char b) {
	if(a > b) swap(a, b);
	if((a == 'A' && b == 'B') || (a == 'B' && b == 'C') || (a == 'D' && b == 'E')) return 1;
	return 0;
}
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	int c1, c2;
	string s1, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	int r1 = 0, r2 = 0;
	for(int i = 0; i < s1.length(); i ++) {
		if('0' <= s1[i] && s1[i] <= '9') {
			r1 = r1 * 10 + s1[i] - '0'; 
		}
	}
	for(int i = 0; i < s2.length(); i ++) {
		if('0' <= s2[i] && s2[i] <= '9') {
			r2 = r2 * 10 + s2[i] - '0'; 
		}
	}
	char k1 = s1[s1.length() - 1], k2 = s2[s2.length() - 1];
	if(c1 == c2) cout << 1;
	else cout << 0;
	if(r1 == r2 && c1 == c2) cout << 1;
	else cout << 0;
	if(r1 == r2 && c1 == c2 && check(k1, k2)) cout << 1;
	else cout << 0;
	if(r1 == r2 && c1 == c2 && check1(k1, k2)) cout << 1;
	else cout << 0;
	return 0;
}
