#include<bits/stdc++.h>
using namespace std;
char c1[2],s1[3],c2[2],s2[3],k;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%c%c%c%c%c%c%c%c%c%c%c%c%c",&c1[0],&c1[1],&k,&s1[0],&s1[1],&s1[2],&k,&c2[0],&c2[1],&k,&s2[0],&s2[1],&s2[2]);
	if(!(c1[0]==c2[0]&&c1[1]==c2[1])){
		printf("0000");
	}else if(!(s1[0]==s2[0]&&s1[1]==s2[1])){
		printf("1000");
	}else if(!((s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]>='D'))){
		printf("1100");
	}else if(!(s1[2]-s2[2]==1||s1[2]-s2[2]==-1)){
		printf("1110");
	}else{
		printf("1111");
	}
	return 0;
}
