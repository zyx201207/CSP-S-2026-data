#include <stdio.h> 
#include <string.h>
int i, j, k, n, m;
char s[5], a[5], b[5], t[5];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%s%s%s%s", s, a, b, t);
	if(s[0]==b[0]&&s[1]==b[1]){
		printf("1");
		if(a[0]==t[0]&&a[1]==t[1]){
			printf("1");
			if(a[2]<='C'&&t[2]<='C'){
				printf("1");
				if(a[2]-t[2]==1||t[2]-a[2]==1) printf("1\n");
				else printf("0\n");
			} 
			else if(a[2]>'C'&&t[2]>'C'){
				printf("1");
				if(a[2]-t[2]==1||a[2]-t[2]==1) printf("1\n");
				else printf("0\n");
			}
			else printf("00\n");
		} 
		else printf("000\n");
	} 
	else printf("0000\n");
	fclose(stdin);
	fclose(stdout);
	return 0;
}
