#include<bits/stdc++.h>
using namespace std;
int main(){
	string c1,s1,c2,s2;
	int ans = 0;
	cin >> c1>>s1>>c2>>s2;
	if(c1 == c2){
		cout << 1;
		ans = 1;
		if(s1[0] == s2[0] && s1[1] == s2[1]){
			cout << 1;
			ans = 1;
			
			if((s1[2] == 'A' || s1[2] == 'B' || s1[2] == 'C') && (s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C')){
				cout << 1;
				ans = 1;
				if(s1[2] == 'A' && s2[2] == 'B'){
					ans = 1;	
				}else if(s1[2] == 'B' && s2[2] == 'A'){
					ans = 1;
				}else if(s1[2] == 'B' && s2[2] == 'C'){
					ans = 1;
				}else if(s1[2] == 'C' && s2[2] == 'B'){
					ans = 1;
				}else ans = 0;
			}else if((s1[2] == 'D' || s1[2] == 'F') && (s2[2] == 'D' || s2[2] == 'F')){
				cout << 1;
				ans = 1;
				if(s1[2] == 'D' && s2[2] == 'F'){
					ans = 1;
				}else if(s1[2] == 'F' && s2[2] == 'D'){
					ans = 1;
				}else{
					ans = 0;
				}
			}else{
				ans = 0;
				cout << 0;
			}
			 
			
		}else{
			ans = 0;
			cout << "00";
		}
	}else{
		cout << "000";
		
	}
	cout << ans;
	
	return 0;
}
