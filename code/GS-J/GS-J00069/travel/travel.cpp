#include<bits/stdc++.h>
using namespace std;
 
char c1[5],c2[5],s1[5],s2[5]; int sum=0;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%s%s%s%s",c1+1,s1+1,c2+1,s2+1); 
	if(c1[1]!=c2[1]||c1[2] != c2[2]){
		printf("0000");
		return 0;
	}
	if(s1[1] != s2[1]||s1[2] != s2[2]){
		printf("1000");
		return 0;
	}
	if((s1[3]=='F'&&s2[3]=='D')||(s1[3]=='D'&&s2[3]=='F')||(s1[3]!='D'&&s1[3]!='F'&&s2[3]!='D'&&s2[3]!='F')){
		sum=0;
	} else{
		printf("1100");
		return 0;
	}
	if((s1[3]=='A'&&s2[3]=='B')||(s2[3]=='A'&&s1[3]=='B')||(s1[3]=='C'&&s2[3]=='B')||(s2[3]=='C'&&s1[3]=='B')
	||(s1[3]=='D'&&s2[3]=='F')||(s1[3]=='F'&&s2[3]=='D')){
		printf("1111");
	}
	else{
		printf("1110");
	}
	return 0;
}
