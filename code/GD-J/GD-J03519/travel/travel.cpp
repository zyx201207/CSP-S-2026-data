#include<bits/stdc++.h>
using namespace std;
int main(){
	char c1,c2,c3,c4,c5,c6,c7,c8,c9,c10;
	
	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1>>c2>>c3>>c4>>c5>>c6>>c7>>c8>>c9>>c10;
	
	if (c1==c6 && c2 == c7){
		cout << '1';
	}
	else {
		cout <<'0';
	}
	if (c3==c8 && c4 == c9){
		cout << '1';
	}
	else {
		cout <<'0';
	}
	if ((c5>='A' && c5<='C' && c10>='A' && c10<='C' && c3==c8 && c4 == c9) || (c5>='D' && c5<='F' && c10>='D' && c10<='F' && c3==c8 && c4 == c9)){
		cout <<'1';
	}
	else {
		cout <<'0';
	}
	if (abs(c10 - c5)== 1 && (c5 != 'C' || c10 != 'D' || c5 != 'C' || c10 != 'D')){
		cout << '1';
	}
	else {
		cout <<'0';
	}
	
	
	cout << endl;
	return 0;
}
