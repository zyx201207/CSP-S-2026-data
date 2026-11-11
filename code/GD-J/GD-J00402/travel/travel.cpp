#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2,s3,s4;
	cin>>s1>>s2>>s3>>s4;
	if(s1==s3){
		printf("1");
		if(s2[0]==s4[0]&&s2[1]==s4[1]){
			printf("1");
			if((s2[2]<='C'&&s4[2]<='C')||(s2[2]>='D'&&s4[2]>='D')){
				printf("1");
				if((s2[2]=='D'&&s4[2]=='F')||(s2[2]=='F'&&s4[2]=='D')){
					printf("1");
				}else if((s2[2]=='B')||(s4[2]=='B')){
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
