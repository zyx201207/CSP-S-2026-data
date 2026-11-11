#include<bits/stdc++.h>
using namespace std;

int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	freopen("travel.in" , "r", stdin ); 
	freopen("travel.out", "w", stdout);
	
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	
	if (c1 != c2) 
		cout << "0000\n";
	else if (s1[0] != s2[0] || s1[1] != s2[1])
		cout << "1000\n";
	else if (!(('D' <= s1[2] && s1[2] <= 'F' || 'D' <= s2[2] && s2[2] <= 'F') 
		|| ('A' <= s1[2] && s1[2] <= 'C' || 'A' <= s2[2] && s2[2] <= 'C')))
		cout << "1100\n";
	else if (abs(s1[2] - s2[2]) != 1)
		cout << "1110\n";
	else
		cout << "1111\n"; 
	
	
	return 0;
} 
