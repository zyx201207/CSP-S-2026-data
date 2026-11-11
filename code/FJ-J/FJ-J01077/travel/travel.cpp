#include <bits/stdc++.h>
using namespace std;
const char side1[] = "ABC", side2[] = "DF";
string c1, s1, c2, s2;
bool same_side(char ch1, char ch2) {
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++) {
			if(ch1 == side1[i] && ch2 == side1[j]) {
				return true;
			}
		}
	}
	for(int i = 0; i < 2; i++) {
		for(int j = 0; j < 2; j++) {
			if(ch1 == side2[i] && ch2 == side2[j]) {
				return true;
			}
		}
	}
	return false;
}
bool near(char ch1, char ch2) {
	if(ch1 == 'A' && ch2 == 'B') return true;
	if(ch1 == 'B' && ch2 == 'C') return true;
	if(ch1 == 'D' && ch2 == 'F') return true;
	return false;
}
bool check1() {
	return c1 == c2;
}
bool check2() {
	return c1 == c2 && 
	       s1[0] == s2[0] && s1[1] == s2[1];
}
bool check3() {
	return c1 == c2 && 
	       s1[0] == s2[0] && s1[1] == s2[1] && 
	       same_side(s1[2], s2[2]);
}
bool check4() {
	return c1 == c2 && 
	       s1[0] == s2[0] && s1[1] == s2[1] && 
	       same_side(s1[2], s2[2]) &&
		   (near(s1[2], s2[2]) || near(s2[2], s1[2]));
}
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	cout << check1() << check2() << check3() << check4();
	cout << endl;
	return 0;
}
// 如何将简单的代码写得又臭又长 be like 
