#include<bits/stdc++.h>
using namespace std;
int x,y,xx,yy;
char z,zz;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d %d%c %d %d%c",&x,&y,&z,&xx,&yy,&zz);
	if(z=='F') z='E';
	if(zz=='F')  z='E';
	if(x!=xx) printf("0000");
	else {
		printf("1");
		if(y!=yy) printf("000");
		else {
			printf("1");
			if((z<'D'&&zz<'D')||(z>'C'&&zz>'C')) {
				printf("1");
				if(abs(z-zz)==1) printf("1");
				else printf("0");
			}
			else printf("00");
		}
	}
	return 0;
}