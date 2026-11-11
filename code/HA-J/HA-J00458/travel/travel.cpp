#include<bits/stdc++.h>
using namespace std;
int a1,a2,b1,b2;
char c1,c2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d %d%c %d %d%c",&a1,&b1,&c1,&a2,&b2,&c2);
	if(a1==a2){
		putchar('1');
		if(b1==b2){
			putchar('1');
			if((c1>67&&c2>67)||(c1<68&&c2<68)){
				putchar('1');
				if(abs((int)(c1-c2))==1)
					putchar('1');
				else printf("0");
			}
			else printf("00");
		}
		else printf("000");
	}
	else printf("0000");
	return 0;
}
