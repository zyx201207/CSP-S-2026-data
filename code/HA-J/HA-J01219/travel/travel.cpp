#include <bits/stdc++.h>
using namespace std;

int to_math(string x){
	int a = 0;
	a = 10*(x[0]-'0') + x[1]-'0';
	return a;
}

bool aaa(string s1, string s2){
	if (s1[2] > 'C' && s2[2] > 'C'){
		return 1;
	}else if (abs(s1[2]-s2[2]) == 1){
		return 1;
	}else {
		return 0;
	}
}

int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	string c1, s1, c2, s2; cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2){
		cout << 1;
		if (to_math(s1) == to_math(s2)){
			cout << 1;
			if ((s1[2]>'C' && s2[2]>'C') || (s1[2]<'D' && s2[2]<'D')){
				cout << 1;
				if (aaa(s1, s2)){
					cout << 1;
				}else {
					cout << 0;
				}
			}else {
				cout << "00";
			}
		}else {
			cout << "000";
		}
	}else {
		cout << "0000";
	}
	
	return 0;
} 
