#include<bits/stdc++.h>
using namespace std;
int rc,xc;
char c1[10],c2[10];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d",&rc);
	for(int i = 1;i<=4;i++){
		scanf("%c",&c1[i]);
	}
	scanf("%d",&xc);
	for(int i = 1;i<=4;i++){
		scanf("%c",&c2[i]);
	}
	if(rc==xc){
		printf("1");
	}else{
		printf("0000");
		return 0;
	}if((c1[2]==c2[2])&&(c1[3]==c2[3])){
		printf("1");
	}else{
		printf("000");
		return 0;
	}
	bool lr = 0,lx = 0;
	if(c1[4]=='A'||c1[4]=='B'||c1[4]=='C'){
		lr = 1;
	}
	if(c2[4]=='A'||c2[4]=='B'||c2[4]=='C'){
		lx = 1;
	}
	if(lr == lx){
		printf("1");
	}else{
		printf("00");
		return 0;
	}
	if((c1[4]==c2[4]+1)||(c1[4]==c2[4]-1)){
		printf("1");
	}else{
		printf("0");
	}
	return 0;
}
