#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel2.in","r",stdin);
	freopen("travel.out","w",stdout);
	int r1,r2,x1,x2;
	char r,x;
	scanf("%d %d%c %d %d%c",&r1,&r2,&r,&x1,&x2,&x);
	//printf("%d %d%c %d %d%c",r1,r2,r,x1,x2,x);
	if(r1==x1)printf("1");
	else{
		printf("0000");
		return 0;
	} 
	
	if(r2==x2)printf("1");
	else{
		printf("000");
		return 0;
	} 
	
	if((r<='C'&&x<='C')||(r>'C'&&x>'C')){
		printf("1");
	}else{
		printf("00");
		return 0;
	}
	
	if(max(r-x,x-r)==1){
		printf("1");
	}else{
		printf("0");
	}
	return 0;
}
