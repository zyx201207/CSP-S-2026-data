#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","out",stdout);
	string c1,s1,c2,s2;
	cin >> c1 >> s1 >> c1 >> s2;
	if(c1 == 1 && c2 == 1) break;
	if(c1 == 16 && c2 == 16) break;
	if(c1 == c2 && s1 == s2) break;
	if(c1 == c2){
		cout << '1';
	}else{
		cout << '0000';
		break;
	}
	if(s1.size(2) == s1.size(2)){
		cout << '1';
	}else{
		cout << '000';
		break;
	}
	if(s1.size(3) <= 'C' || s1.size(3) >= 'D' && s2.size(3) <= 'C' || s2.size(3) >= 'D'){
		cout << '1';
	}else{
		cout << '00';
		break
	}
	if(s1.size(3) + 1 != 'D' && s1.size(3) - 1 != 'C'){
		if(s2.size(3) + 1 != 'D' && s2.size(3) - 1 != 'C'){
			if(s1.size(3) + 1 == s2.size(3) || s1.size(3) - 1 == s2.size(3)){
				cout << '1';
			}else{
				cout << 0;
				break;
			}
		}
	}
	return 0;
}
