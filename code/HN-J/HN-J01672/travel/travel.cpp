#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	char s1[3],s2[3];
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)printf("1");
	else {printf("0000");return 0;}
	if(s1[0]==s2[0] && s1[1]==s2[1])printf("1");
	else printf("0");
	if((s1[2]-'A'+s2[2]-'A'<=3||s1[2]-'A'+s2[2]-'A'==8)&&(s1[0]==s2[0] && s1[1]==s2[1]))printf("1");
	else printf("0");
	if(s1[0]==s2[0] && s1[1]==s2[1]){
		if(s1[2]-'A'+s2[2]-'A'==8)printf("1");
		else if(s1[2]-'A'+s2[2]-'A'<=3&&max(s1[2]-'A',s2[2]-'A')-min(s1[2]-'A',s2[2]-'A')==1)printf("1");
		else printf("0");
	}
	else printf("0");
	return 0; 
}
