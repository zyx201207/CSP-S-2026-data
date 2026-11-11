#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b,c,d;
	char c1,c2;
	scanf("%d%d%c%d%d%c" ,&a,&b,&c1,&c,&d,&c2);
	if(a != c){
		printf("0000");
	}else{
		printf("1");
		if(b != d){
			printf("000");
		}else{
			printf("1");
			if((c1 <= 'C' && c2 <= 'C') || (c1 >= 'D' && c2 >= 'D')){
				printf("1");
				if((c1 == 'A' && c2 == 'C') || (c1 == 'C' && c2 == 'A')){
					printf("0");
				}else{
					printf("1");
				}
			}else{
				printf("00");
			}
		}
	}
	return 0;
}
