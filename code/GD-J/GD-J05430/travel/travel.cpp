#include<bits/stdc++.h>
using namespace std;
string c_1,s_1,c_2,s_2;
bool flag=1;
bool ck(char x,char y){
	if((x=='A'||x=='B'||x=='C')&&(y=='A'||y=='B'||y=='C')){
		return 1;
	}
	else if((x=='D'||x=='F')&&(y=='D'||y=='F')){
		return 1;
	}
	else{
		return 0;
	}
}
bool ck_2(char x,char y){
	if(x=='A'&&y=='B'){
		return 1;
	}
	if(x=='B'&&(y=='A'||y=='C')){
		return 1;
	}
	if(x=='C'&&y=='B'){
		return 1;
	}
	if(x=='D'&&y=='F'){
		return 1;
	}
	if(x=='F'&&y=='D'){
		return 1;
	}
	return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c_1>>s_1>>c_2>>s_2;
	if(c_1==c_2){
		cout<<"1";
	}
	else{
		cout<<"0";
		flag=0;
	}
	if(s_1[0]==s_2[0]&&s_1[1]==s_2[1]&&flag){
		cout<<"1";
	}
	else{
		cout<<"0";
		flag=0;
	}
	char n=s_1[2],m=s_2[2];
	if(ck(n,m)&&flag){
		cout<<"1";
	}
	else{
		cout<<"0";
		flag=0;
	}
	if(flag&&ck_2(n,m)){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	return 0;
}
