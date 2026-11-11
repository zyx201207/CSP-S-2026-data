#include <bits/stdc++.h> 
using namespace std;
int main(){
	bool flag1=false,flag2=false,flag3=false;
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	//同一节车厢、同一排、过道的同一侧，并且相邻
	if(c1==c2) {
		cout<<1;
		flag1=true;
	}
	else{
		cout<<0;
	} 
	if(s1[0]==s2[0]&&s1[1]==s2[1]&&flag1==true) {
		cout<<1; 
		flag2=true;
	}
	else{
		cout<<0;
	} 
	if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C'&&s2[2]=='A'||s2[2]=='B'||s2[2]=='C'){
		if(flag2==true) {
			cout<<1;
			flag3=true;
		}
		else {
			cout<<0;
		}
	} 
	else if(s1[2]=='D'||s1[2]=='F'&&s2[2]=='D'||s2[2]=='F'){
		if(flag2==true) {
			cout<<1;
			flag3=true;
		}
		else {
			cout<<0;
		}
	} 
	else {
		cout<<0;
	}
	if(flag3==true&&abs(s1[2]-s2[2])==1) {
		cout<<1;
	}
	else {
		cout<<0;
	}
	return 0;
}
