#include<bits/stdc++.h>
using namespace std;
string c1,c2;
string s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	bool flag = true;
	if(c1 == c2){
		cout << 1;
		
		if(s1[0] == s2[0] && s1[1] == s2[1]){
			cout << 1;
			
			if((s1[2]-'A' == 5 || s1[2]-'A' == 3) && (s2[2]-'A' == 5 || s2[2]-'A' == 3)){
				cout << 1;
				
				if(flag == true){
					if((s1[2] == 'D' && s2[2] == 'F') || (s1[2] == 'F' && s1[2] == 'D')){
						cout << 1;
					}else if(abs(s1[2] - s2[2]) == 1){
						cout << 1;
					}else{
						cout << 0;
					}
				}
			}else if((s1[2]-'A' >= 0 && s1[2]-'A' <= 2) && (s2[2] -'A' >=0 && s2[2]-'A' <=2)){
				cout << 1;
				
				if(flag == true){
					if((s1[2] == 'D' && s2[2] == 'F') || (s1[2] == 'F' && s1[2] == 'D')){
						cout << 1;
					}else if(abs(s1[2] - s2[2]) == 1){
						cout << 1;
					}else{
						cout << 0;
					}
				}
			}else{
				cout << 0 << 0;
				flag = false;
			}
		}else{
			cout << 0 << 0 << 0;
		}
	}
	else{
		cout << 0 << 0 << 0 << 0;
	}
	return 0;
} 
