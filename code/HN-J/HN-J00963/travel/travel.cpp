#include <bits/stdc++.h>
using namespace std;

string c1, c2, s1, s2;
int side[200];

int main() {
	side['A'] = 1; 
	side['B'] = 1; 
	side['C'] = 1; 
	side['D'] = 0; 
	side['F'] = 0; 
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	int x1 = (c1 == c2), x2 = (s1[0] == s2[0] && s1[1] == s2[1]), x3 = (side[s1[2]] == side[s2[2]]);
	int x4 = (abs(s1[2] - s2[2]) == 1 || (s1[2] == 'D' && s2[2] == 'F') || (s1[2] == 'F' && s2[2] == 'D'));
	cout << x1 << (x1 && x2) << (x1 && x2 && x3) << (x1 && x2 && x3 && x4);
	return 0;
}

