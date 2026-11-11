#include<bits/stdc++.h>
using namespace std;

int num1,num2;
char c1[10],c2[10],s1[10],s2[10];
int check[10]={0,0,0,1,1,1};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%s",c1+1);
	scanf("%s",s1+1);
	scanf("%s",c2+1);
	scanf("%s",s2+1);
	num1=(c1[1]-'0')*10+c1[2]-'0';
	num2=(c2[1]-'0')*10+c2[2]-'0';
	if(num1!=num2){
		printf("0000");
		return 0; 
	}
	num1=(s1[1]-'0')*10+s1[2]-'0';
	num2=(s2[1]-'0')*10+s2[2]-'0';
	if(num1!=num2){
		printf("1000");
		return 0; 
	}
	num1=check[s1[3]-'A'];
	num2=check[s2[3]-'A'];
	if(num1!=num2){
		printf("1100");
		return 0; 
	}
	num1=s1[3]-'A';
	num2=s2[3]-'A';
	if((num1==0&&num2==1)||(num1==0&&num2==1)){
		printf("1111");
		return 0;
	}
	if((num1==2&&num2==1)||(num1==2&&num2==1)){
		printf("1111");
		return 0;
	}
	if((num1==3&&num2==5)||(num1==3&&num2==5)){
		printf("1111");
		return 0;
	}
	else{
		printf("1110");
		return 0;
	}
	return 0;
} 
