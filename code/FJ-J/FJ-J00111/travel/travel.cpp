#include<stdio.h>
#include<string>
#include<iostream>
#include<math.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		printf("1");
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			printf("1");
			if(s1[2]-'A'<3&&s2[2]-'A'<3||s1[2]-'A'>=3&&s2[2]-'A'>=3){
				printf("1");
				if(s1[2]-'A'<3&&abs(s1[2]-s2[2])==1||s1[2]-'A'>=3&&abs(s1[2]-s2[2])==2){
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
