#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b,a_1,b_1,a_2,b_2;
	char ch1,ch2;
	scanf("%d %d %c %d %d %c",&a,&a_1,&ch1,&b,&b_1,&ch2);
	a_2=ch1-'A'+1;
	b_2=ch2-'A'+1;
	if(a==b){
		printf("1");
		if(a_1==b_1){
			printf("1");
			if((a_2<4&&b_2<4)||(a_2>3&&b_2>3)){
				printf("1");
				if(a_2>b_2)swap(a_2,b_2);
				if((a_2+1==b_2)||(a_2==4&&b_2==6))printf("1");
				else printf("0");
			}
			else printf("00");
		}
		else printf("000");
	}
	else printf("0000");
	return 0;
}
