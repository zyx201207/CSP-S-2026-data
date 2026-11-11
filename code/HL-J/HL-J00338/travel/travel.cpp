#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	int check = 0,b1 = 0,b2 = 0;
	cin >> c1 >> s1 >> c2 >> s2;
	for(int i = 0;i < 2;i++){
		if(c1[i] == c2[i]) check++;
	}
	if(check == 2){
		cout << "1";
	} 
	else cout << "0"; 
	if(s1[0] == s2[0]&&s1[1] == s2[1]&&check == 2){
		cout << "1";
	}
	else cout << "0";
	if(('A' <= s1[2]&&'C' >= s1[2])&&('A' <= s2[2]&&'C' >= s2[2])){
		if((s1[0] == s2[0]&&s1[1] == s2[1])&&check == 2){
			b1 = 1;
			cout << "1";
		}
		else cout << "0";
	} 
	else if(('D' <= s1[2]&&'F' >= s1[2])&&('D' <= s2[2]&&'F' >= s2[2])){
		if((s1[0] == s2[0]&&s1[1] == s2[1])&&check == 2){
			b2 = 1;
			cout << "1";
		}
		else cout << "0";
	} 
	else{
		cout << "0";
	}
	if(b1 == 1||b2 == 1){
		if(s1[2] - s2[2] == 1||s2[2] - s1[2] == 1) cout << "1";
		else cout << "0";
	}
	else cout << "0";
	
	return 0;
} 
