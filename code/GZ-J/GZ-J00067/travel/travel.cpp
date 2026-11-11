//уейкаж GZ-J00067 
#include<bits/stdc++.h>
using namespace std;
char c1[4],c2[4],c3[4],c4[4];
int a1=0,a2=0,a3=0;
int main(){
	scanf("%s",&c1);
	scanf("%s",&c2);
	scanf("%s",&c3);
	scanf("%s",&c4);
	int flag=1;
	for(int i=0;i<=1;++i){
		if(c1[i]!=c3[i]){
			flag=0;
		}
	}
	if(flag==1){
		a1=1;
		printf("1");
	}else{
		printf("0");
	}
	flag=1;
	for(int i=0;i<=1;++i){
		if(a1==0||c2[i]!=c4[i]){
			flag=0;
		}
	}
	if(flag==1){
		a2=1;
		printf("1");
	}else{
		printf("0");
	}
	if(c2[2]<='C'&&c4[2]<='C'&&a2==1){
		a3=1;
		printf("1");
	}
	else{
		if(c2[2]>='D'&&c4[2]>='D'&&a2==1){
			a3=1;
			printf("1");
		}
	else printf("0");
	}
	if(c2[2]==c4[2]+1&&a3==1||c2[2]==c4[2]-1&&a3==1){
		printf("1");
	}else{
		printf("0");
	}
	
	return 0;
}
