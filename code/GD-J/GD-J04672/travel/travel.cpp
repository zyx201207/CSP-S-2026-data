#include<bits/stdc++.h>
using namespace std;
char s[100007];
int c1,c2,p1,p2,s1de,s2de,s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	for(int i=1;i<=4;i++){
		if(i==1){
			scanf("%d",&c1);
		}
		else if(i==3){
			scanf("%d",&c2);
		}
		else{
			scanf("%s",s);
			int pai=10*(s[0]-'0')+(s[1]-'0');
			if(i==2){
				p1=pai;
			}
			if(i==4){
				p2=pai;
			}
			if(s[2]=='A'){
				if(i==2){
					s1de=1;
					s1=1;
				}
				else if(i==4){
					s2de=1;
					s2=1;
				}
			}
			if(s[2]=='B'){
				if(i==2){
					s1de=1;
					s1=2;
				}
				else if(i==4){
					s2de=1;
					s2=2;
				}
			}
			if(s[2]=='C'){
				if(i==2){
					s1de=1;
					s1=3;
				}
				else if(i==4){
					s2de=1;
					s2=3;
				}
			}
			if(s[2]=='D'){
				if(i==2){
					s1de=2;
					s1=5;
				}
				else if(i==4){
					s2de=2;
					s2=5;
				}
			}
			if(s[2]=='F'){
				if(i==2){
					s1de=2;
					s1=6;
				}
				else if(i==4){
					s2de=2;
					s2=6;
				}
			}
		}
	}
	if(c1!=c2){
		printf("0000");
	}
	else{
		printf("1");
		if(p1!=p2){
			printf("000");
		}
		else{
			printf("1");
			if(s1de!=s2de){
				printf("00");
			}
			else{
				printf("1");
				if(abs(s1-s2)>1){
					printf("0");
				}
				else{
					printf("1");
				}
			}
		}
	}
	return 0;
}
