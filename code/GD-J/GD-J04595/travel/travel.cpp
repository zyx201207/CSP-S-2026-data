#include<bits/stdc++.h>
using namespace std;
long long tsq;
char a[1001],b[1001],c[1001],d[1001];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%s%s%s%s",a,b,c,d);
	if(a[0]==c[0]&&a[1]==c[1]) {
		printf("1");
		if(b[0]==d[0]&&b[1]==d[1]) {
			printf("1");
			if((b[2]>='A'&&b[2]<='C'&&d[2]>='A'&&d[2]<='C')||(b[2]>='D'&&b[2]<='E'&&d[2]>='D'&&d[2]<='E')) {
				printf("1");
				if(b[2]!=d[2]&&abs(b[2]-d[2])==1) printf("1");
				else printf("0");
			}
			else {
				printf("00");
			}
		}
		else printf("000");
	}
	else printf("0000");
	return 0;
}
