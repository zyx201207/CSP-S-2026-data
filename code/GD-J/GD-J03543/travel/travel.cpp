#include <bits/stdc++.h>
using namespace std;

int main() {
	string s1,s2;
	int c1,c2;
	int a=0,b=0,c=0,d=0;
	freopen("travel.in","r",stdin);
	freopen("travel.our","w",stdout);
	cin >>c1 >>s1 >>c2 >>s2;
	if(c1 == c2){
		cout << 1;
		if(s1[1]==s2[1] && s1[0] == s2[0]) {
			cout << 1;
			if(s1[2] == 'F'||s1[2] == 'D'){a =1;}
			if(s2[2] == 'F'||s2[2] == 'D'){b =1;}
			if(a == b) {
				cout << 1;
				if(a == 0){
					if(s1[2] == 'A'||s1[2] == 'C'){c =1;}
					if(s2[2] == 'A'||s2[2] == 'C'){d =1;}
					if(c !=1||d!=1){
						cout<<1;
					}else{cout << 0;}
				}else{cout << 1;}
			}else{cout << "00";}
		}else{cout << "000";}
	} else {cout << "0000";}
	
	return 0;
} 
