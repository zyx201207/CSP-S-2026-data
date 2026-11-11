#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
string c1, s1, c2, s2;
int main() {
	
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> c1 >> s1 >> c2 >> s2;
	
	// 1
	if(c1 == c2) cout << "1";
	else {
		cout << "0000";
		return 0;
	}
	
	//2
	int n = (s1[0] - '0') * 10 + (s1[1] - '0');
	int m = (s2[0] - '0') * 10 + (s2[1] - '0');
	if(n == m) cout << "1";
	else {
		cout << "000";
		return 0;
	}
	
	//3
	if(s1[2] == 'A') {
		if(s2[2] == 'B' || s2[2] == 'C') cout << "1";
		else {
			cout << "00";
			return 0;
		}
	}
	
	else if(s1[2] == 'B') {
		if(s2[2] == 'A' || s2[2] == 'C') cout << "1";
		else {
			cout << "00";
			return 0;
		}
	}
	
	else if(s1[2] == 'C') {
		if(s2[2] == 'B' || s2[2] == 'A') cout << "1";
		else {
			cout << "00";
			return 0;
		}
	}
	
	else if(s1[2] == 'D') {
		if(s2[2] == 'F') cout << "1";
		else {
			cout << "00";
			return 0;
		}
	}
	
	else if(s1[2] == 'F') {
		if(s2[2] == 'D') cout << "1";
		else {
			cout << "00";
			return 0;
		}
	}
	
	//4
	if(s1[2] == 'A' && s2[2] == 'B') cout << "1";
	else if(s1[2] == 'B' && s2[2] == 'A') cout << "1";
	else if(s1[2] == 'B' && s2[2] == 'C') cout << "1";
	else if(s1[2] == 'C' && s2[2] == 'B') cout << "1";
	else if(s1[2] == 'D' && s2[2] == 'F') cout << "1";
	else if(s1[2] == 'F' && s2[2] == 'D') cout << "1";
	else cout << "0";
	
	return 0;
} 
