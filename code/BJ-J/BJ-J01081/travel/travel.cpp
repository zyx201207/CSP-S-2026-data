#include <iostream>
#include <cstdio>
using namespace std;
int num(string s){
	int n=(s[0]-'0')+(s[1]-'0');
	return n;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	int c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	int r1=num(s1),r2=num(s2);
	char ch1=s1[2],ch2=s2[2];
	
	if(c1==c2){
		printf("1");
			
		if(r1==r2){
			printf("1");
			
			if(ch1<='C' && ch2<='C'){
				printf("1");
				
				if(char(ch1+1)==ch2 || char(ch2+1)==ch1){
					printf("1");
				}
				else printf("0");
			}
			else if(ch1>='D' && ch2>='D'){
				printf("1");
				
				if(ch1=='D' && ch2=='F' || ch1=='F' && ch2=='D'){
					printf("1");
				}
				else printf("0");
			}
			else printf("00");
			
		}
		else printf("000");
	} 
	else printf("0000");
	printf("\n");
	

	fclose(stdin);
	fclose(stdout);
	return 0;
}