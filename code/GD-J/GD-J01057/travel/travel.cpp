#include <bits/stdc++.h>
using namespace std;
string c1, c2, s1, s2;
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 != c2 || c1 == "1" || c1 == "16" || c2 == "1" || c2 == "16") {
		cout << "0000";
		return 0;
	}else cout << "1";
	string t1 = s1.substr(0, 2), t2 = s2.substr(0, 2);
	if(t1 != t2) {
		cout << "000";
		return 0;
	}else cout << "1";
	t1 = s1.substr(2, 1), t2 = s2.substr(2, 1);
	if(!((t1 == "A" && (t2 == "B" || t2 == "C")) || (t1 == "B" && (t2 == "A" || t2 == "C")) || (t1 == "C" && (t2 == "B" || t2 == "A")) || (t1 == "D" && t2 == "F") || (t1 == "F" && t2 == "D"))) {
		cout << "00";
		return 0;
	}
	else cout << "1";
	if(!((t1 == "A" && t2 == "B") || (t1 == "B" && (t2 == "A" || t2 == "C")) || (t1 == "C" && t2 == "B") || (t1 == "D" && t2 == "F") || (t1 == "F" && t2 == "D"))) {
		cout << "0";
	}
	else cout << "1";
	return 0;
} 
