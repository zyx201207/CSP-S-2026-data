#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	
	bool f1 = (c1 == c2), f2 = (s1[0] == s2[0] && s1[1] == s2[1]);
	
	if (f1){
		cout << 1;
		if (f2){
			cout << 1;
			if ((s1[2] >= 'A' && s2[2] <='C')||(s1[2] >= 'D' && s2[2] <='E')){
				cout << 1;
				if(abs(s1[2]-s2[2]) == 1){
					cout << 1;
				}else cout << 0;
			}else cout << 0 << 0;
		}else{
			cout << 0 << 0 << 0;
		}
	}else cout << 0 << 0 << 0 << 0; 
	return 0;
} 
