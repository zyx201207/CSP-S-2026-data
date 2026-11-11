#include<bits/stdc++.h>
using namespace std;
int c1,c2,r1,r2;
char s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d%c%d%d%c",&c1,&r1,&s1,&c2,&r2,&s2);
	if(c1!=c2){
		printf("0000");
		return 0;
	}
	else{
		if(r1!=r2){
			printf("1000");
			return 0;
		}
		else{
			if(!((s1=='D'||s1=='E')&&(s2=='D'||s2=='E')||(s1=='A'||s1=='B'||s1=='C')&&(s2=='A'||s2=='B'||s2=='C'))){
				printf("1100");
				return 0;
			}
			else{
				int k=s1-s2;
				if(abs(k)==1)printf("1111");
				else printf("1110");
			}
		}
	}
	return 0;
}
