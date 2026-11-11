#include<bits/stdc++.h>
using namespace std;
string s, si, c, ci;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c >> s >> ci >> si;
	if(c == ci){
		cout << 1;
		if(s[1] == si[1]&&s[0] == si[0]) {
			cout << 1;
			if((s[2] <= 'C'&&s[2] >= 'A')&&(si[2] <= 'C'&&si[2] >= 'A')||(s[2] == 'F'&&si[2] == 'D')||(s[2] == 'D'&&si[2] == 'F')){
				cout << 1;
				if((si[2] == 'B'&&(s[2] == 'A'||s[2] == 'C'))||(s[2] == 'B'&&(si[2] == 'A'||si[2] == 'C'))||((s[2] == 'F'&&si[2] == 'D')||(s[2] == 'D'&&si[2] == 'F'))){
					cout << 1;
				}else{
					cout << 0;
					return 0;
				}
			}else{
				cout << "00";
				return 0;
			}
		}else{
			cout << "000";
			return 0;
		}
		
	} else{
		cout << "0000";
	}
	return 0;
}
