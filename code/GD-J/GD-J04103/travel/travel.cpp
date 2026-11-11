#include<bits/stdc++.h>
using namespace std;
int c1,c2;
char s1,ss1,sss1;
char s2,ss2,sss2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d %c%c%c %d %c%c%c",&c1,&s1,&ss1,&sss1,&c2,&s2,&ss2,&sss2);
//	printf("%d1\n%c2\n%c3\n%c4\n%d5\n%c6\n%c7\n%c8",c1,s1,ss1,sss1,c2,s2,ss2,sss2);
	if(c1==c2){
		printf("1");
		if(s1==s2&&ss1==ss2){
		printf("1");
		if(sss1=='A'||sss1=='B'||sss1=='C'){
			if(sss2=='A'||sss2=='B'||sss2=='C')printf("1");
			else printf("0");

		}else{
			if(sss2=='D'||sss2=='F')printf("1");
			else printf("0");
		}
		
		
		if(sss1=='A'){
			
			if(sss2=='B')printf("1");
			else printf("0");
			
		}else if(sss1=='B'){
			
			if(sss2=='A'||sss2=='C')printf("1");
			else printf("0");
			
		}else if(sss1=='C'){
			
			if(sss2=='B')printf("1");
			else printf("0");
			
		}else if(sss1=='D'){
			
			if(sss2=='F')printf("1");
			else printf("0");
			
		}else if(sss1=='F'){
			
			if(sss2=='D')printf("1");
			else printf("0");
		}
	}else{
		printf("000");
	}
	}else{
		printf("0000");
	}
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

