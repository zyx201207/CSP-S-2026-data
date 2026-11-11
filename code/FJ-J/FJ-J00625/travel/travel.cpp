// CCF let me ak csp-j
#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool check1() {
	return (c1 == c2);
}
bool check2()  {
	return (check1() && s1[0] == s2[0] && s1[1] == s2[1]);
}
bool check3() {
	if(!check2()) return false;
	if((s1[2] == 'A' || s1[2] == 'B' || s1[2] == 'C')  && (s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C')){
		return true;
	}
	if((s1[2] == 'D' || s1[2] == 'E') && (s2[2] == 'D' || s2[2] == 'E')){
		return true;
	}
	return false;
}
bool check4() {
	return (check3() && abs(s1[2] - s2[2]) == 1);
}
int main() { 
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
	cin >> c1 >> s1 >> c2 >> s2;
//	cout << c1 << '\n'<< s1 << '\n'<< c2 <<'\n';TEST
	cout<< check1() << check2() << check3() << check4();
	return 0;
}
