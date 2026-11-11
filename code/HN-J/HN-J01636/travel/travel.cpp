#include <bits/stdc++.h>
using namespace std;
string c1, s1, c2, s2;
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 != c2){
		cout << "0000" << "\n";
		return 0;
	}
	cout << '1';
	string s1b = s1.substr(0, 2), s2b = s2.substr(0, 2);
	if(s1b != s2b){
		cout << "000" << "\n";
		return 0;
	}
	cout << '1';
	if((s1[2] >= 'A' && s1[2] <= 'C' && s2[2] >= 'A' && s2[2] <= 'C') || (s1[2] >= 'D' && s1[2] <= 'F' && s2[2] >= 'D' && s2[2] <= 'F')){
		cout << '1';
	}
	else{
		cout << "00" << "\n";
		return 0;
	}
	if(abs(s1[2] - s2[2]) != 1){
		cout << '0' << "\n";
		return 0;
	}
	cout << "1";
	return 0;
}
