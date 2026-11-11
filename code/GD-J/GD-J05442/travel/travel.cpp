#include<bits/stdc++.h>
using namespace std;
int main(){
	char c1[3], c2[3], c3[3], c4[3];
	cin >> c1[1] >> c1[2];
	cin >> c2[1] >> c2[2] >> c2[3];
	cin >> c3[1] >> c3[2];
	cin >> c4[1] >> c4[2] >> c4[3];
	if(c1[1] == c3[1] && c1[2] == c3[2]){
		cout << '1';
	}else{
		cout << '0';
		cout << '0';
		cout << '0';
		cout << '0';
		return 0;
	}
	if(c2[1] == c4[1] && c2[2] == c4[2]){
		cout << '1';
		if((c2[3] >='D' && c2[3]<='F')&&(c4[3] >='D' && c4[3]<='F')||(c2[3] >='A' && c2[3]<='C')&&(c4[3] >='A' && c4[3]<='C')){
			cout << '1';
			if(c2[3]+1 == c4[3]||c2[3]-1 == c4[3]){
				cout << '1';
			}else{
				cout << '0';
			}
		}else{
			cout << '0';
			cout << '0';
		}
	}else{
		cout << '0';
		cout << '0';
		cout << '0';
	}
	return 0; 
} 
