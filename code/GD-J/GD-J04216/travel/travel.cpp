#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool pd1(){
	for(int i=0;i<=1;i++){
		if(c1[i]!=c2[i])return 0;
	}
	return 1;
}
bool pd2(){
	for(int i=0;i<=1;i++){
		if(s1[i]!=s2[i])return 0;
	}
	return 1;
}
bool pd3(){
	if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C'){
		if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'){
			return 1;
		}
		else {
			return 0;
		}
	}
	else {
		if(s2[2]=='D'||s2[2]=='F'){
			return 1;
		}
		else {
			return 0;
		}
	}
	return 0;
}
bool pd4(){
	if((s2[2]=='B'&&(s1[2]=='A'||s1[2]=='C'))|| (s1[2]=='B'&&(s2[2]=='A'||s2[2]=='C'))|| ((s1[2]=='F'&&s2[2]=='D')||(s2[2]=='F'&&s1[2]=='D'))){
		return 1;
	}
	return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(pd1()){
		cout<<"1";
		if(pd2()){
			cout<<"1";
			if(pd3()){
				cout<<"1";
				if(pd4()){
					cout<<"1";
				}
				else {
					cout<<"0";
				}
			}
			else {
				cout<<"00";
			}
		}
		else {
			cout<<"000";
		}
	}
	else {
		cout<<"0000";
	}
	return 0;
} 
