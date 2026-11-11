#include<stdio.h>

int a,b,x,y;
char c,z;
bool a1,a2,a3,a4,s[6];

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	scanf("%d%d%c%d%d%c",&a,&b,&c,&x,&y,&z);
	s[c-64]=s[z-64]=1;
	a1=(a==x);
	a2=a1&&(b==y);
	a3=a2&&( (!(s[1]||s[2]||s[3]))||(!(s[4]||s[5])) );
	a4=a3&&(s[2]||s[4]);
	if(a1)printf("1");else printf("0");
	if(a2)printf("1");else printf("0");
	if(a3)printf("1");else printf("0");
	if(a4)printf("1");else printf("0");
	
	return 0;
}
