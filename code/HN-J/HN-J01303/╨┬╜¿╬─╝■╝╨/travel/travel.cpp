#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4;//ÏäÊýs1,s3;×ùÎ»s2,s4. 
bool flag=true;
bool flag1=true;
bool flag2=true; 
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> s1 >> s2 >> s3 >> s4;
	for(int i=0;i<s1.size();i++){
		if(s1[i]-'0'==s3[i]-'0'){
			flag=true;
		}
		else{
			flag=false;
			break;
		}
	}
	if(flag){
		cout << "1";
	}
	else{
		cout << "0";
	}
	for(int i=0;i<2;i++){
		if(s2[i]-'0'==s4[i]-'0'){
			flag1=true;
		}
		else{
			flag1=false;
			break;
		}
	} 
	if(flag1){
		cout << "1";
	}
	else{
		cout << "0";
	}
	if(((s2[2]=='A'||s2[2]=='B'||s2[2]=='C')&&(s4[2]=='A'||s4[2]=='B'||s4[2]=='C'))||((s2[2]=='B'||s2[2]=='D')&&(s4[2]=='C'||s4[2]=='B'))){
		cout << "1";
	}
	else{
		cout <<  "0";
	}
	if((s2[2]=='A'&&s4[2]=='B')||(s2[2]=='B'&&(s4[2]='A'||s4[2]=='C'))||(s2[2]=='C'&&s4[2]=='B')||(s2[2]=='D'&&s4[2]=='F')||(s2[2]=='F'&&s4[2]=='D')){
		cout << "1";
	}
	else{
		cout << "0";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
