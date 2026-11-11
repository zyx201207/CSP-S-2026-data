#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	int a1,a2,b1,b2;
	scanf("%d",&c1);
	getchar();
	a1=getchar()-'0';
	a1=a1*10+(getchar()-'0');
	b1=getchar()-'A';
	if(b1==3) b1=4;
	
	scanf("%d",&c2);
	getchar();
	a2=getchar()-'0';
	a2=a2*10+(getchar()-'0');
	b2=getchar()-'A';
	if(b2==3) b2=4;
	
	
	if(c1==c2){
		putchar('1');
		if(a1==a2) putchar('1');
		else putchar('0');
		if(a1==a2&&(b1<3&&b2<3||b1>3&&b2>3)) putchar('1');
		else putchar('0');
		if(a1==a2&&(abs(b1-b2)==1)) putchar('1');
		else putchar('0');
	}
	else printf("0000");
	return 0;
}
