#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	int c1, s1, c2, s2;
	char r1, r2;
	scanf("%d %d%c %d %d%c", &c1, &s1, &r1, &c2, &s2, &r2);
	if(c1 != c2) {
		cout << "0000";
		return 0;
	}
	if(s1 != s2) {
		cout << "1000";
		return 0;
	}
	if('A' <= min(r1, r2) && min(r1, r2) <= 'C' && 'D' <= max(r1, r2) && max(r1, r2) <= 'E') {
		cout << "1100";
		return 0;
	}
	if(abs(r1 - r2) != 1) {
		cout << "1110";
		return 0;
	}
	cout << "1111";
	return 0;
} 
