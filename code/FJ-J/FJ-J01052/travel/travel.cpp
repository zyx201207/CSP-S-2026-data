#include<stdio.h>
char c1[5],s1[5],c2[5],s2[5];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%s%s%s%s",c1,s1,c2,s2);
	if(c1[0]!=c2[0]||c1[1]!=c2[1])
		printf("0000");
	else{
		putchar('1');
		if(s1[0]!=s2[0]||s1[1]!=s2[1])printf("000");
		else{
			putchar('1');
			if((s1[2]<'D')^(s2[2]<'D'))printf("00");
			else{
				putchar('1');
				putchar((s1[2]-s2[2])*(s1[2]-s2[2])==1?'1':'0');
			}
		}
	}
	return 0;
}
