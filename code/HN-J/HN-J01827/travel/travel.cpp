#include <bits/stdc++.h>
using namespace std;
bool ll4(char s1,char s2){
	switch(s1){
		case 'A':{
			if(s2=='B') return true;
			return false;
		}
		case 'B':{
			if(s2=='A'||s2=='C') return true;
			return false;
			break;
		}
		case 'C':{
			if(s2=='B') return true;
			return false;
			break;
		}
		case 'D':{
			if(s2=='F') return true;
			return false;
			break;
		}
		case 'F':{
			if(s2=='D') return true;
			break;
		}
	}
}
bool ll3(string s1,string s2){
	if(s1[0]==s2[0]&&s1[1]==s2[1]){
		switch(s1[2]){
			case 'A':{
				if(s2[2]=='B'||s2[2]=='C') return true;
				return false;
				break;
			}
			case 'B':{
				if(s2[2]=='A'||s2[2]=='C') return true;				return false;
				return false;
				break;
			}
			case 'C':{
				if(s2[2]=='A'||s2[2]=='B') return true;
				return false;
				break;
			}
			case 'D':{
				if(s2[2]=='F') return true;
				return false;
				break;
			}
			case 'F':{
				if(s2[2]=='D') return true;
				return false;
				break;
			}
		}
	}
}
bool ll2(string s1,string s2){
	if(s1[0]==s2[0]&&s1[1]==s2[1]) return true;
	return false;
}
bool ll1(string c1,string c2){
	if(c1[0]==c2[0]&&c1[1]==c2[1]) return true;
	return false;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(ll1(c1,c2)){
		printf("1");
		if(ll2(s1,s2)){
			printf("1");
			if(ll3(s1,s2)){
				printf("1");
				if(ll4(s1[2],s2[2])){
					printf("1");
				}
				else printf("0");
			}
			else printf("00");
		}
		else printf("000");
	}
	else printf("0000");
	printf("\n");
	return 0;
}
