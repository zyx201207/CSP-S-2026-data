#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int a,b;
char x[10],y[10];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d %s %d %s",&a,x+1,&b,y+1);
	if(a==b){
		printf("1");
		if(x[1]==y[1]&&x[2]==y[2]){
			printf("1");
			bool A,B;
			A=(x[3]=='A'||x[3]=='B'||x[3]=='C');
			B=(y[3]=='A'||y[3]=='B'||y[3]=='C');
			if(A==B){
				printf("1");
				if(x[3]=='A'&&y[3]=='B'){
					printf("1");
				}else if(x[3]=='B'&&y[3]=='C'){
					printf("1");
				}else if(x[3]=='D'&&y[3]=='F'){
					printf("1");
				}else printf("0");
			}else{
				 printf("00");
			}
		}else{
			printf("000");
		}
	}else{
		printf("0000");
	}
	return 0;
}

