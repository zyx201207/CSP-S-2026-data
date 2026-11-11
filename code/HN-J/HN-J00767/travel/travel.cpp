#include <string>
#include <cstdio>
#include <iostream>
using namespace std;

int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	int larger, lower;
	if (s1[2] >= s2[2]){
		larger = s1[2];
		lower = s2[2];
	} else {
		larger = s2[2];
		lower = s1[2];
	}

	bool a, b, c, d, ADown, BDown;
	ADown = ('A' <= s1[2] && s1[2] <= 'C');
	BDown = ('A' <= s2[2] && s2[2] <= 'C');
	a = (c1 == c2);
	b = (a && (s1[0] == s2[0]) && (s1[1] == s2[1]));
	c = (b && (ADown == BDown));
	d = (c && (larger - lower == 1));
	
	cout << a << b << c << d;
	
	return 0;
}
