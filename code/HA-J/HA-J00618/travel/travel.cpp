#include<bits/stdc++.h>
using namespace std;
int x,y;
int a,b;
char k1,k2;
int c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%2d %2d%c %2d %2d%c",&x,&a,&k1,&y,&b,&k2);
	c=k1-'A'+1,d=k2-'A'+1;
	if(c>d){
		swap(c,d);
	}
	if(x!=y){
		printf("0000");
		return 0;
	}
	if(a!=b){
		printf("1000");
		return 0;
	}
	if(c<=3&&d>=4){
		printf("1100");
		return 0;
	}
	if(c+1!=d){
		printf("1110");
		return 0;
	}
	printf("1111");
	return 0;
} 
