#include <bits/stdc++.h>
using namespace std;
string c1;
string s1;
string c2;
string s2;

int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1;
	cin >> s1;
	cin >> c2;
	cin >> s2;
	char a = s1[2];
	char b = s2[2];
	if(c1 == c2){
		cout << "1";
		if(s1[0] == s2[0] && s1[1] == s2[1]){
			cout << "1";
			if((a <= 67 && b <= 67) || (a >= 68 && b >= 68)){
				cout << "1";
				if(a-1 == b || a+1 == b){
					cout << "1";
				}
				else{
					cout << "0";
					return 0;
				}
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
		return 0;
	}
	return 0;
}
