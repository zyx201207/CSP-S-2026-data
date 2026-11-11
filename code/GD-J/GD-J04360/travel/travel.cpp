#include <iostream>
#include <cstdlib> 
#include <string>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char c1[4],s1[4],c2[4],s2[4];
	scanf("%s%s%s%s",&c1,&s1,&c2,&s2);
	//printf("%s %s %s %s\n",&c1,&s1,&c2,&s2);
	if(c1[0]!=c2[0]||c1[1]!=c2[1])printf("0000\n");
	else if(s1[0]!=s2[0]||s1[1]!=s2[1])printf("1000\n");
	else if((s1[2]=='F'&&s2[2]=='D')||(s1[2]=='D'&&s2[2]=='F')||(s1[2]=='A'&&(s2[2]=='B'||s2[2]=='C'))||((s1[2]=='B')&&(s2[2]=='A'||s2[2]=='C')||(s1[2]=='C'&&(s2[2]=='A'||s2[2]=='B'))))
	printf("111%c",(s1[2]=='F'||s1[2]=='D'||s1[2]=='B'||s2[2]=='B')?'1':'0');//进行一些暴力的写 
	else printf("1100\n");
	return 0; 
}
