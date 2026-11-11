#include<bits/stdc++.h>
using namespace std;
char c1[5],s1[5],c2[5],s2[5];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%s %s %s %s",&c1,&s1,&c2,&s2);
	if(c1[0]==c2[0]&&c1[1]==c2[1]){
		printf("1");
	}else{
		printf("0000");
		return 0;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]){
		printf("1");
	}else{
		printf("000");
		return 0;
	}
	if(s1[2]=='D'){
		if(s2[2]=='F'){
			printf("11");
			return 0;
		}else{
			printf("00");
			return 0;
		}
	}else if(s1[2]=='F'){
		if(s2[2]=='D'){
			printf("11");
			return 0;
		}else{
			printf("00");
			return 0;
		}
	}else if(s2[2]=='D'||s2[2]=='F'){
		printf("00");
		return 0;
	}else{
		printf("1");
	}
	if((s1[2]=='A'&&s2[2]=='C')||(s1[2]=='C'&&s2[2]=='A')){
		printf("0");
	}else{
		printf("1");
	}
	return 0;
}
