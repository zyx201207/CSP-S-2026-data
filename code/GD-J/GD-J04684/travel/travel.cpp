#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4;
int js=0;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> s1 >> s2 >> s3 >> s4;
	if(s1==s3){
		if(s1=="01"||s1=="16"){
			cout << "0000";
			return 0;
		}else{
			cout << "1";
		}
	}else{
		cout <<"0000";
		return 0;
	}
	for(int i = 0;i < 2;i++){
		if(s2[i]==s4[i]){
			js++;
		}
	}
	if(js==2){
		cout << "1";
	}else{
		cout << "000";
		return 0;
	}
	if(int(s2[2]) <= 67 && int(s4[2]) <= 67){
		cout << "1";
	}else{
		if(int(s2[2]) >=68 && int(s4[2]) >=68){
			cout << "1";
		}else{
			cout << "00";
			return 0;
		}
	}
	if(int(s2[2]) +1 == int(s4[2]) && s2[2]!='C'){
		cout << "1";
	}else{
		if(int (s2[2] + 2) == int(s4[2]) && s2[2] == 'D'){
			cout << "1";
		}else{
			cout << "0";
		}
	}
	
	return 0;
}
