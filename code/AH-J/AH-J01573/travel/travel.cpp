#include<bits/stdc++.h>
using namespace std;
void hh(int a1,int b1,char* a2,char* b2){ 
	if(a1!=b1){
	printf("0000");
	return ;
	}
	if(a2[0]!=b2[0]||a2[1]!=b2[1]){
	printf("1000");
	return ;
	}
	if((a2[2]<=67&&a2[2]>=65)!=(b2[2]<=67&&b2[2]>=65)){
	printf("1100");
	return ;
	}else if((a2[2]<=70&&a2[2]>=68)!=(b2[2]<=70&&b2[2]>=68)){
	printf("1100");
	return ;
	}
	if(((a2[2]+1!=b2[2])&&(a2[2]-1!=b2[2]))&&!((a2[2]==68&&b2[2]==70)||(a2[2]==70&&b2[2]==68))){
		printf("1110");
		return ;
	}else{
	printf("1111");
	return ;
	}
}
char a2[3],b2[3];
int main(){
	int a1,b1;
	scanf("%d",&a1);
	for(int i=0;i<3;i++){
		cin>>a2[i];
	}
	scanf("%d",&b1);
	for(int i=0;i<3;i++){
		cin>>b2[i];
	}
	hh(a1,b1,a2,b2);
	return 0;
}
