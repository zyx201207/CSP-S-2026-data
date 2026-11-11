#include <iostream>
#include <string>
using namespace std;
string s1,s2,s3,s4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	//scanf("%c%c%c%c",&s1,&s2,&s3,&s4);
	cin>>s1>>s2>>s3>>s4;
	if(s1!=s3)	printf("0000");
	else{
		printf("1");
		int s5=s2[0]-'0'+s2[1]-'0',s6=s4[0]-'0'+s4[1]-'0';
		if(s5!=s6)	printf("000");
		else{
			printf("1");
			char l=s2[2],r=s4[2];
			if((l>='A'&&l<='C'&&r>='A'&&r<='C')||(l>='D'&&l<='F'&&r>='D'&&r<='F')){
				printf("1");
				if(l-r==1||r-l==1) printf("1");
				else printf("0");
			} 
			else printf("00");
		}
	}
	return 0;
} 
