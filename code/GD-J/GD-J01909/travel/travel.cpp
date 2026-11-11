#include <bits/stdc++.h>
using namespace std;
string r1, r2, s1, s2;
int r, s;
void abc(){
	if(r2[2] == 'A')
		r = 1;
	else if(r2[2] == 'B')
		r = 2;
	else if(r2[2] == 'C')
		r = 3;
	else if(r2[2] == 'D')
		r = 4;
	else if(r2[2] == 'F')
		r = 5;
	if(s2[2] == 'A')
		s = 1;
	else if(s2[2] == 'B')
		s = 2;
	else if(s2[2] == 'C')
		s = 3;
	else if(s2[2] == 'D')
		s = 4;
	else if(s2[2] == 'F')
		s = 5;
	return;
}
int main(){
//	freopen("travel5.in", "r", stdin);
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> r1 >> r2 >> s1 >> s2;
	abc();
	if(r1 == s1){
		cout << "1";
		if(r2[0] == s2[0] && r2[1] == s2[1]){
			cout << "1";
			if((r <= 3 && s <= 3) || (r > 3 && s > 3)){
				cout << "1";
				if(abs(r - s) == 1){
					cout << "1";
				}
				else{
					cout << "0";
				}
			}
			else{
				cout << "00";
			}
		}
		else{
			cout << "000";
		}
	}
	else{
		cout << "0000";
	}
	return 0;
}
