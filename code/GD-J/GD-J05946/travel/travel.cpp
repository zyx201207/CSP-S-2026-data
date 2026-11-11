#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	
	if (c1 == c2) cout << 1;
	else {
		cout << "0000"; 
		return 0;
	}
	
	if (s1[0] == s2[0] && s1[1] == s2[1]) cout << 1;
	else {
		cout << "000";
		return 0;
	} 
	
	if ( ((char)s1[2] >= 'D' && (char)s2[2] >= 'D')
		|| ((char)s1[2] <= 'C' && (char)s2[2] <= 'C') )
		cout << 1;
	else {
		cout << "00";
		return 0;
	} 
	
	if (abs(s1[2] - s2[2]) == 1) cout << 1;
	else cout << 0; 
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
