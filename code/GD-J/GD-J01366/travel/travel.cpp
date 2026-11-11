#include<bits/stdc++.h>
using namespace std;
char a[5],b[5],c[5],d[5];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%s%s%s%s",a,b ,c,d);
	if(a[0] == c[0] && a[1] == c[1]) printf("%d",1);
	else {
		printf("%s","0000");
		return 0;
	}
	if(b[0] == d[0] && b[1] == d[1]) printf("%d",1);
	else {
		printf("%s","000");
		return 0;
	}
	if(((b[2] >= 'A' && b[2] <= 'C') && (d[2] >= 'D' && d[2] <= 'F')) || ((d[2] >= 'A' && d[2] <= 'C') && (b[2] >= 'D' && b[2] <= 'F'))) {
		printf("%s","00");
		return 0;
	} else printf("%d",1);
	if((b[2] + 1 ) == d[2]) printf("%d",1);
	else printf("%d",0);
	return 0;
}
