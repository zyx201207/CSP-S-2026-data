#include<bits/stdc++.h>
using namespace std;
char b[9],d[9];
int a,c;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d",&a);
	for(int i=1;i<=3;i++)
		scanf(" %c",&b[i]);
	scanf("%d",&c);
	for(int i=1;i<=3;i++)
		scanf(" %c",&d[i]);
	if(a==c){
		printf("1");
		if(b[1]==d[1]&&b[2]==d[2]){
			printf("1");
			if( (b[3]>'C' && d[3]>'C') || (b[3]<'D' && d[3]<'D') ){
				printf("1");
				if((b[3]=='C'&&d[3]=='A')||(b[3]=='C'||d[3]=='A')){
					printf("0");
				}else{
					printf("1");
				}
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
