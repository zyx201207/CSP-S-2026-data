#include <bits/stdc++.h>
using namespace std;
int a1,b1,a2,b2;
char c1,c2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d %d%c %d %d%c",&a1,&b1,&c1,&a2,&b2,&c2);
	if(a1!=a2){
		printf("0000\n");
		return 0;
	}
	printf("1");
	if(b1!=b2){
		printf("000\n");
		return 0;
	}
	printf("1");
	if(c1>c2){
		swap(c1,c2);
	}
	if(c1<='C'&&c2>='D'){
		printf("00\n");
		return 0;
	}
	printf("1");
	if(c1=='A'&&c2=='B'){
		printf("1\n");
		return 0;
	}
	if(c1=='B'&&c2=='C'){
		printf("1\n");
		return 0;
	}
	if(c1=='D'&&c2=='F'){
		printf("1\n");
		return 0;
	}
	printf("0\n");
	return 0;
}
