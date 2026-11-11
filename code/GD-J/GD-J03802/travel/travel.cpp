#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
char a,b;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	bool d = 0, f = 0;
	cin >> c1 >> s1 >> c2 >> s2;
	a = s1[2];
	b = s2[2];
	
	if(c1 == c2) cout << '1';
	else{
		cout << "0000";
		return 0;
	}
	
	if(s1[0] == s2[0] && s1[1] == s2[1]){
		cout << '1';
		d = 1;
	}
	else{
		cout << "000";
		return 0;
	}
	
	if(d == 1 && ((a <= 'C' && b <= 'C') || (a >= 'D' && b >= 'D'))){
			cout << '1';
			f = 1;
	}else{
		cout << "00";
		return 0;
	}

	if(f == 1){
		if(abs(a - b) == 1){
			cout << '1';
			return 0; 
		}
	}
	cout << 0; 
	return 0;
} 
