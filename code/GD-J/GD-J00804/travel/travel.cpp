#include<stdio.h>

int c1,c2;
char s1[10],s2[10];

int main(){
	#ifndef STDIO
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	#endif
	scanf("%d",&c1);
	scanf(" %s",&s1);
	scanf("%d",&c2);
	scanf(" %s",&s2);
	if(c1!=c2){
		printf("0000");
		return 0;
	}
	printf("1");
	int line1=0,line2=0;
	char seat1=0,seat2=0;
	for(int i=0;s1[i]!='\0';i++){
		if(s1[i]>='0' && s1[i]<='9'){
			line1=line1*10+s1[i]-'0';
		}
		else{
			seat1=s1[i];
		}
	}
	for(int i=0;s2[i]!='\0';i++){
		if(s2[i]>='0' && s2[i]<='9'){
			line2=line2*10+s2[i]-'0';
		}
		else{
			seat2=s2[i];
		}
	}
	if(line1!=line2){
		printf("000");
		return 0;
	}
	printf("1");
	if((seat1<='C' && seat2<='C') || (seat1>'C' && seat2>'C')){
		printf("1");
	}
	else{
		printf("00");
		return 0;
	}
	if(seat1-1==seat2 || seat2-1==seat1){
		printf("1");
	}
	else{
		printf("0");
	}
	return 0;
} 
// orz
