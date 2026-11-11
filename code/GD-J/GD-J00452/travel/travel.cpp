#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,c1,s2,c2;
	cin >> s1 >> c1 >> s2 >> c2;
	if(s1 == s2){
		cout << '1';
		string ss1,ss2;
		ss1 = c1[0] + c1[1];
		ss2 = c2[0] + c2[1];
		if(ss1 == ss2){
			cout << '1';
			char ss3 = c1[2];
			char ss4 = c2[2];
			if(ss3 >= 'A' && ss3 <= 'C' && ss4 >= 'A' && ss4 <= 'C'){
				cout << '1';
				if(ss3 == 'A' && ss4 == 'B'){
					cout << '1';
				}
				else if(ss3 == 'B' && ss4 == 'C'){
					cout << '1';
				}
				else{
					cout << 0;
				}
			}
			else if(ss3 >= 'D' && ss3 <= 'F' && ss4 >= 'D' && ss4 <= 'F'){
				cout << "11";
			}
			else{
				cout << "00";
				return 0;
			}
		}
		else{
			cout << "000";
			return 0;
		}
	}
	else{
		cout << "0000";
	}
	return 0;
} 
