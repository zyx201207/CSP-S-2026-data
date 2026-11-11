#include<bits/stdc++.h>
using namespace std;
int C_1,C_2;
char s1[5],s2[5];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	// t:1s,m:1G
	cin >> C_1;
//	cout << C_1;
	cin >> s1[1] >> s1[2] >> s1[3] >> C_2 >> s2[1] >> s2[2] >> s2[3];
	if(C_1==C_2){
		cout << 1;
	}
	else{
		cout << "0000";
		return 0;
	}
	if(s1[1]==s2[1] && s1[2]==s2[2]){
		cout << 1;
	}
	else{
		cout << "000";
		return 0;
	}
	if(((s1[3]=='A'||s1[3]=='B'||s1[3]=='C')&&(s2[3]=='B'||s2[3]=='A'||s2[3]=='C'))||((s1[3]=='D'||s1[3]=='F')&&(s2[3]=='D'||s2[3]=='F'))){
		cout << 1;
	}
	else{
		cout << "00";
		return 0;
	}
	if((s1[3]=='A'&&s2[3]=='B')||(s1[3]=='B'&&s2[3]=='C')||(s2[3]=='A'&&s1[3]=='B')||(s2[3]=='B'&&s1[3]=='C')||(s2[3]=='D' && s1[3]=='F')||(s2[3]=='F' && s1[3]=='D')){
		cout << 1;
	}
	else{
		cout << 0;
	}
	return 0;
}
