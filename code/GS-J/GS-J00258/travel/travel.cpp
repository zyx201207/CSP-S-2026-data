#include<bits/stdc++.h>
using namespace std;

#define N 15
char c1[N],s1[N],c2[N],s2[N];

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	scanf("%s %s %s %s",c1,s1,c2,s2);
	
	int  flag=0;

    if(c1[0]==c2[0]&&c1[1]==c2[1]){
    	printf("1");
	}else {
		printf("0000");
		return 0;
	}
	
	if(s1[0]==s2[0]&&s1[1]==s2[1]){
		printf("1");
	}else {
		printf("000");
		return 0;
	}
    
    if((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')){
		printf("1");
	}else if((s1[2]=='D'||s1[2]=='F')&&(s2[2]=='D'||s2[2]=='F')){
		printf("1");
		flag=1;
	}else {
		printf("00");
		return 0;
	}
	
    int cha=s1[2]-s2[2];
	if(flag==1){
		printf("1");
	}else if(cha==1||cha==-1){
    	printf("1");
	}else {
		printf("0");
		return 0;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
