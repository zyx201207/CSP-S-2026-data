#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out","w",stdout);
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2){
		cout << 1;
	}
	else{
		cout << "0000";
		return 0;
	}
	if(s1.substr(0,2) == s2.substr(0,2)){
		cout << 1;
	}
	else{
		cout << "000";
		return 0;
	}
	char p1 = s1[2], p2 = s2[2];
	if(p1 >= 'D' && p2 <= 'C' || p1 <= 'C' && p2 >= 'D'){
		cout << "00";
		return 0;
	}
	else {
		cout << 1;
	}
	if(abs(p1-p2) == 1){
		cout << 1;
	}
	else{
		cout << 0;
	}
}
