#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	long long c1,s1,c2,s2;
	char op1,op2;
	scanf("%lld%lld%c%lld%lld%c",&c1,&s1,&op1,&c2,&s2,&op2);
	if(op1=='F') op1='E';
	if(op2=='F') op2='E';
	if(c1==c2){
		printf("1");
		if(s1==s2){
			printf("1");
			if((op1<'D' && op2<'D') || (op1>'C' && op2>'C')){
				printf("1");
				if(abs(op1-op2)==1){
					printf("1");
				}
				else{
					printf("0");
				}
			}
			else{
				printf("00");
			}
		}
		else{
			printf("000");
		}
	}
	else{
		printf("0000");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
