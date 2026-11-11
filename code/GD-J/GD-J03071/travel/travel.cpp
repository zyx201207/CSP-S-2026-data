#include<bits/stdc++.h>
using namespace std;
char c1[4],s1[5],c2[4],s2[5];
int x;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	for(int i=1;i<=3;i++) scanf("%c",&c1[i]);
	for(int i=1;i<=4;i++) scanf("%c",&s1[i]);
	for(int i=1;i<=3;i++) scanf("%c",&c2[i]);
	for(int i=1;i<=4;i++) scanf("%c",&s2[i]);
	if(c1[1]!=c2[1]||c1[2]!=c2[2]){
		printf("0000");
		return 0;
	}
	if(s1[1]!=s2[1]||s1[2]!=s2[2]){
		printf("1000");
		return 0;
	}
	if(s1[3]<='C'&&s2[3]>'C'||s1[3]>'C'&&s2[3]<='C'){
		printf("1100");
		return 0;
	}
	x=abs(s1[3]-s2[3]);
	if(s1[3]<='C'&&s2[3]<='C'&&x>1){
		printf("1110");
		return 0;
	}
	printf("1111");
	return 0;
} 

