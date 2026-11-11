#include<bits/stdc++.h>
using namespace std;
char c1[5],c2[5],s1[5],s2[5];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%s%s%s%s",c1,s1,c2,s2);
	if(c1[0]==c2[0] && c1[1]==c2[1]){
		printf("%c",'1');
		if(s1[0]==s2[0] && s1[1]==s2[1]){
		printf("%c",'1');
		if(s1[2]<='C' && s2[2]<='C'){
		    	printf("%c",'1');
		    if(s1[2]=='A' && s2[2]=='C') printf("%c",'0');
			else if(s1[2]=='C' && s2[2]=='A') printf("%c",'0');
			else printf("%c",'1');
		} 
		else if(s1[2]>'C' && s2[2]>'C'){
			printf("%c",'1');
		} 
		else printf("%c%c",'0','0');
		}
		else printf("%c%c%c",'0','0','0');
	} 
	else printf("%c%c%c%c",'0','0','0','0');
	fclose(stdin);
	fclose(stdout);
	return 0;
}
