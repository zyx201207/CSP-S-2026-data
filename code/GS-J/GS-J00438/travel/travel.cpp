#include<bits/stdc++.h>
using namespace std;\
char c1[2],s1[3],c2[2],s2[3];
bool flag;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%s%s%s%s",c1,s1,c2,s2);
	for(int i=0;i<2;++i){if(c1[i]!=c2[i]){flag=1;}}
	printf("%d",flag==1?0:1);
	
	for(int i=0;i<2;++i){if(s1[i]!=s2[i]){flag=1;}}
	printf("%d",flag==1?0:1);
	
	if(s1[2]<='C') {if(s2[2]>'C'){flag=1;}}
	else if(s2[2]<='C'){flag=1;}
	printf("%d",flag==1?0:1);
	
	if(flag==1){
		printf("0");
		return 0;
	}
	
	if((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='C')||(s1[2]=='D'&&s2[2]=='F')||(s1[2]=='B'&&s2[2]=='A')||(s1[2]=='C'&&s2[2]=='B')||(s1[2]=='F'&&s2[2]=='D')){printf("1");}
	else{printf("0");}
	return 0;
}

