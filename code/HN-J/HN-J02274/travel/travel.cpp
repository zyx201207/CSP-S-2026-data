#include <bits/stdc++.h>
using namespace std;

void fileIO(const string &s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	fileIO("travel");
	
	int c1, c2;
	string s1, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if(s1[2] == 'F') s1[2] = 'E';
	if(s2[2] == 'F') s2[2] = 'E';
	
	if(c1 != c2) cout << "0000\n";
	else if(s1.substr(0, 2) != s2.substr(0, 2)) cout << "1000\n";
	else if((s1[2] < 'D') ^ (s2[2] < 'D')) cout << "1100\n";
	else if(abs(s1[2] - s2[2]) > 1) cout << "1110\n";
	else cout << "1111\n";
} 
