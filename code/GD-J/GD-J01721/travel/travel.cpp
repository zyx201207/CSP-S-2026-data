#include<bits/stdc++.h>
using namespace std;

int c1, s1;
char s11, s22;
int c2, s2;
int c10, c20;
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> s11 >> c2 >> s2 >> s22;
	if(c1 == c2){
		cout << 1;
	}else{
		cout << "0000";
		return 0;
	}
	if(s1 == s2){
		cout << 1;
	}else{
		cout << "000";
		return 0;
	}
	bool a=0;
	if(s11 >= 'A' && s11 <= 'C' && s22 >= 'A' && s22 <= 'C' || s11 >= 'D' && s11 <= 'F' && s22 >= 'D' && s22 <= 'F'){
		cout << 1;
		if(s11 == 'D' && s22 == 'F' || s11 == 'F' && s22 == 'D' || int(s11) == int(s22)+1 || int(s22) == int(s11)+1){
			a = 1;
		}
	}else cout << 0;
	if(a) cout << 1;
	else cout << 0;
	return 0;
} 
