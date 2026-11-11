#include <bits/stdc++.h>
using namespace std;
string c1, s1, c2, s2;
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1.size() == 1){
		c1 = '0'+c1;
	}
	if(c2.size() == 1){
		c2 = '0'+c2;
	}
	if(s1.size() == 2){
		s1 = '0'+s1;
	}
	if(s2.size() == 2){
		s2 = '0'+s2;
	}
	int cnt1 = 0;
	for(int i = 0;i <= 1;i++){
		if(c1[i] == c2[i]){
			cnt1++;
		}
	}if(cnt1 == 2){
		cout << 1;
	}
	else{
		cout << 0 << 0 << 0 << 0;
	}
	if(cnt1 == 2){
		int cnt2 = 0;
		for(int i = 0;i <= 1;i++){
			if(s1[i] == s2[i]){
				cnt2++;
			}
		}
		if(cnt2 == 2){
			cout << 1;
		}
		else{
			cout << 0 << 0 << 0;
		}
		if(cnt2 == 2){
			if(s1[2] == 'A'||s1[2] == 'B'||s1[2] == 'C'){
				if(s2[2] == 'A'||s2[2] == 'B'||s2[2] == 'C'){
					cout << 1;
					if(s1[2]<s2[2]){
						if(s1[2]+1 == s2[2]){
							cout << 1;
						}
					}
					else if(s1[2]>s2[2]){
						if(s2[2]+1 == s1[2]){
							cout << 1;
						}
						else{
							cout << 0;
						}
					}	
					else{
						cout << 0;
					}
				}
				else{
					cout << 0 << 0;
				}
			
			}
			else if(s1[2] == 'D'||s1[2] == 'F'){
				if(s2[2] == 'D'||s2[2] == 'F'){
					cout << 1;
					if(s1[2]<s2[2]){
					if(s1[2]+1 == s2[2]){
						cout << 1;
					}
					}
					else if(s1[2]>s2[2]){
					if(s2[2]+1 == s1[2]){
						cout << 1;
					}
					else{
						cout << 0;
					}
					}	
					else{
						cout << 0 << 0;
					}
				}
				
			else{
				cout << 0;
			}
		}
	}
	}
	return 0;
} 
