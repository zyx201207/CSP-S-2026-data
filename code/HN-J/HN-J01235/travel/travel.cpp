#include<iostream>
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b=0,c,d=0,i;
	scanf("%d ",&a);
	char e,f,g,h;
	scanf("%c%c%c\n",&e,&f,&g);
	if(e=='1') b+=10;
	b+=int(f-'0');
	scanf("%d %c%c%c",&i,&e,&f,&h);
	if(e=='1') d+=10;
	d+=int(f-'0');
	if(i!=a){
		printf("0000");
		return 0;
	}
	if(b!=d){
		printf("1000");
		return 0;
	}
	int j=int(g-'A'),k=int(h-'A');
	if(!((j>=3 && k>=3) || (j<3 && k<3))){
		printf("1100");
		return 0;
	}
	if(k-j!=1 || k+j==5){
		printf("1110");
		return 0;
	}
	printf("1111");
	return 0;
}
