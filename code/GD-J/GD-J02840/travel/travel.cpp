#include<stdio.h>
int a,b,c,d;char e,f;
int p[]={0,0,0,1,1};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d%c%d%d%c",&a,&c,&e,&b,&d,&f);
	if(a!=b)printf("0000");
	else if(c!=d)printf("1000");
	else if(p[e-'A']!=p[f-'A'])printf("1100");
	else if(e-f!=1&&f-e!=1)printf("1110");
	else printf("1111");
	return 0;
}

