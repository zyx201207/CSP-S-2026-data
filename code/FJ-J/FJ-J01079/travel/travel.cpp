#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

string c1, s1, c2, s2;

int k(char c) {
	if (c == 'A' || c == 'B' || c == 'C') return 1;
	else return 2;
}

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> c1 >> s1 >> c2 >> s2;
	
	if (c1[0] == c2[0] && c1[1] == c2[1]) {
		cout << 1;
	} else {
		cout << 0;
	}
	
	if ((c1[0] == c2[0] && c1[1] == c2[1]) && (s1[0] == s2[0] && s1[1] == s2[1])) {
		cout << 1;
	} else {
		cout << 0;
	}
	
	if (((c1[0] == c2[0] && c1[1] == c2[1]) && (s1[0] == s2[0] && s1[1] == s2[1])) 
	&& (k(s1[2]) == k(s2[2]))) {
		cout << 1;
	} else {
		cout << 0;
	}
	
	if (((((c1[0] == c2[0] && c1[1] == c2[1]) && (s1[0] == s2[0] && s1[1] == s2[1])) 
	&& (k(s1[2]) == k(s2[2])))) && abs(s1[2] - s2[2]) == 1) {
		cout << 1;
	} else {
		cout << 0;
	}
	
	cout << '\n';
	
	return 0;
}
