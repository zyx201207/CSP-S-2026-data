#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s12,s2,s22;
	cin >> s1 >> s12 >> s2 >> s22;
	if (s1 == s2){
		cout << 1;
	}else{
		cout << "0000";
		return 0; 
	}
	if (s12[0] + s12[1] == s22[0] + s22[1]){
		cout << 1;
	}else{
		cout << "000";
		return 0;
	}
	if ((s12[2] <= 'C' && s22[2] <= 'C') || (s12[2] >= 'D' && s22[2] >= 'D')){
		cout << 1;
	}
	else{
		cout << "00";
		return 0;
	}
	if (abs(s12[2] - s22[2]) == 1){
		cout << 1;
	}else{
		cout << 0;
		return 0;
	} 
}
