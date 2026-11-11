#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2,c ,d;
	string s1,s2,a,b;
	cin >> c1 >> s1 >> c2 >> s2;
	a = s1[2];
	b = s2[2];
	if(s1[2] == 'A'||s1[2] == 'B'||s1[2] == 'C'){
		c = 0;
	}
	else{
		c= 1;
	}
	if(s2[2] == 'A'||s2[2] == 'B'||s2[2] == 'C'){
		d = 0;
	}
	else{
		d= 1;
	}
	
	
	if(c1 == c2 &&s1[0]+s1[1] == s1[0]+s1[1]&&c == d){
		cout << 1110;
	}
	else{
		if(c1 == c2 &&s1[0]+s1[1] == s1[0]+s1[1]){
			cout << 1100;
		}
		else{
			if(c1 == c2){
				cout << 1000;
			}
			else{
				cout << 0000;
			}
		}
	}
	
		
		
		
	return 0;
} 
