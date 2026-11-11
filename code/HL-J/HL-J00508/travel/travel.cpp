#include <bits/stdc++.h>
using namespace std;
bool gd(char a, char b){
	if(a >= 'A' && a <= 'C' && b >= 'A' && b <= 'C'){
		return 1;
	}
	if((a == 'D' || a == 'F') && (b == 'D' || b == 'F')){
		return 1;
	}
	return 0;
}
bool xl1(char a, char b){
	if(a-b==1||a-b==-1||(a=='D'&&b=='F')||(a=='F'&&b=='D')){
		return 1;
	}
	return 0;
}
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string s1, s2, r1, r2;
	cin >> s1 >> r1 >> s2 >> r2;
	if(s1 == s2){
		cout << 1;
		if(r1[0]==r2[0]&&r1[1]==r2[1]){
			cout << 1;
			if(gd(r1[2], r2[2])){
				cout << 1;
				if(xl1(r1[2], r2[2])){
					cout << 1;
				}else{
					cout << 0;
				}
			}else{
				cout << "00";
			}
		}else{
			cout << "000";
		}
	}else{
		cout << "0000";
	}
	return 0;
}
