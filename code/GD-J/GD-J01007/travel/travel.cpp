#include<bits/stdc++.h>
using namespace std;
char a[5],b[5],c[5],d[5],hg[5]={1,1,1,2,2};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%s %s %s %s",a,b,c,d);
	if(a[0]==c[0]&&a[1]==c[1]){
		printf("1");
		if(b[0]==d[0]&&b[1]==d[1]){
			printf("1");
			if(hg[b[2]-'A']==hg[d[2]-'A']){
				printf("1");
				if(!((b[2]=='A'&&d[2]=='C')||(b[2]=='C'&&d[2]=='A'))){
					printf("1");
				}
				else printf("0");
			}
			else printf("00");
		}
		else printf("000");
	}
	else printf("0000");
	return 0;
}
