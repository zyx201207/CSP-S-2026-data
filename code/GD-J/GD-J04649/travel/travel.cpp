#include<bits/stdc++.h>
#define int long long
using namespace std;

bool fa(char s){
	return s >= 'A' && s <= 'C';
}

bool fb(char s){
	return s >= 'D' && s <= 'F';
}

signed main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	cout << (c1 == c2);
	cout << ((c1 == c2) && (s1[0] == s2[0] && s1[1] == s2[1]));
	cout << (((c1 == c2) && (s1[0] == s2[0] && s1[1] == s2[1])) && ((fa(s1[2]) && fa(s2[2])) || (fb(s1[2]) && fb(s2[2]))));
	cout << ((((c1 == c2) && (s1[0] == s2[0] && s1[1] == s2[1])) && ((fa(s1[2]) && fa(s2[2])) || (fb(s1[2]) && fb(s2[2])))) && (abs(s1[2] - s2[2]) == 1));
	return 0;
}
