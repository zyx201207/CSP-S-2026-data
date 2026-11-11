#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s,s1,s2,s3,s4;
	cin>>s1>>s2>>s3>>s4;
	s=s1+' '+s2+' '+s3+' '+s4;
//	for(int i=0;i<=12;i++)
//		printf("%c",s[i]);
	if(s[0]==s[7]&&s[1]==s[8]){
		printf("1");
	}
	else{
		printf("0000");
		return 0;
	}
	if(s[3]==s[10]&&s[4]==s[11]){
		printf("1");
	}
	else{
		printf("000");
		return 0;
	}
	if(s[5]+s[12]==('D'+'F')){
		printf("11");
	}
	else if(s[5]+s[12]==('A'+'B')){
		printf("11");
	}
	else if(s[5]+s[12]==('C'+'B')){
		printf("11");
	}
	else if(s[5]+s[12]==('A'+'C')){
		printf("10");
	}
	else if(s[5]+s[12]==('A'+'D')){
		printf("00");
	}
	else if(s[5]+s[12]==('A'+'F')){
		printf("00");
	}
	else if(s[5]+s[12]==('D'+'B')){
		printf("00");
	}
	else if(s[5]+s[12]==('F'+'B')){
		printf("00");
	}
	else if(s[5]+s[12]==('C'+'D')){
		printf("00");
	}
	else if(s[5]+s[12]==('C'+'F')){
		printf("00");
	}
	return 0;
}
