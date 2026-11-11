#include<bits/stdc++.h>
using namespace std;
string s1,s2,ss1,ss2;
bool check(char x,char y){
	if(x=='D'||x=='F'){
		if(y=='D'||y=='F') return true;
		else return false;
	}else{
		if(y=='A'||y=='B'||y=='C') return true;
		else return false;
	}
	return false;
}
bool check1(char x,char y){
	if(x=='F'&&y=='D') return true;
	if(x=='D'&&y=='F') return true;
	if(x=='C'&&y=='B') return true;
	if(x=='B'&&(y=='C'||y=='A')) return true;
	if(x=='A'&&y=='B') return true;
	return false;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>ss1>>s2>>ss2;
	if(s1==s2){
		printf("1");
		if(ss1[0]==ss2[0]&&ss1[1]==ss2[1]){
			printf("1");
			if(check(ss1[2],ss2[2])){
				printf("1");
				if(check1(ss1[2],ss2[2])){
					printf("1");
				}else{
					printf("0");
				}
			}else{
				printf("00");
			}
		}else{
			printf("000");
		}
	}else{
		printf("0000");
	}
	return 0;
}
