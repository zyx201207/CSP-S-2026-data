#include<bits/stdc++.h>
using namespace std;

string c1, s1, c2, s2;

bool same_side(char ch1, char ch2) {
	if(ch1 == 'A' || ch1 == 'B' || ch1 == 'C') {
		return ch2 == 'A' || ch2 == 'B' || ch2 == 'C';
	}
	if(ch1 == 'F' || ch1 == 'D') {
		return ch2 == 'F' || ch2 == 'D';
	}
	return 0;
}
bool is_near(char ch1, char ch2) {
	if(ch1 == 'A') {
		return ch2 == 'B';
	}
	if(ch1 == 'B') {
		return ch2 == 'A' || ch2 == 'C';
	}
	if(ch1 == 'C') {
		return ch2 == 'B';
	}
	if(ch1 == 'D') {
		return ch2 == 'F';
	}
	if(ch1 == 'F') {
		return ch2 == 'D';
	}
	return 0;
}

signed main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2) {
		cout << 1;
	}	
	else {
		cout << 0;
	}
	string h1, h2;
	h1 = s1[0] + s1[1];
	h2 = s2[0] + s2[1];
	if(c1 == c2 && h1 == h2) {
		cout << 1;
	}
	else {
		cout << 0;
	}
	if(c1 == c2 && h1 == h2 && same_side(s1[2], s2[2])) {
		cout << 1;
	}
	else {
		cout << 0;
	}
	if(c1 == c2 && h1 == h2 && same_side(s1[2], s2[2]) && is_near(s1[2], s2[2])) {
		cout << 1;
	}
	else {
		cout << 0;
	}
	return 0;
} 
