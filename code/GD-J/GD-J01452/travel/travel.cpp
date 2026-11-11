#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travle.in", "r", stdin);
	freopen("travle.out", "w", stdout);
	string s1, s2, c1, c2;
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2){
		cout << 1;
		if(s1[0] == s2[0] && s1[1] == s2[1]){
			cout << 1;
			if(s1[2] == 'A' || s1[2] == 'B' || s1[2] == 'C'){
				if(s2[2] == 'D' || s2[2] =='F'){
					cout << "00";
					return 0;
				}
				else cout << 1;
			}
			else{
				if(s2[2] != 'D' && s2[2] != 'F'){
					cout << "00";
					return 0;
				}
				else cout << 1;
			}
			if(abs(s1[2] - s2[2]) == 1)cout << 1;
			else cout << 0;
		}
		else {
			cout << "000";
			return 0;
		}
	}
	else cout << "0000";
	return 0;
}
