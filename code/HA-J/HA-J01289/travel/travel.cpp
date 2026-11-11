#include<bits/stdc++.h>
using namespace std;
int a1,a2,b1,b2;
char a3,b3;
bool n,m;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d %d%c %d %d%c",&a1,&a2,&a3,&b1,&b2,&b3);
	if(a1==b1)printf("1");
	else printf("0");
	if(a1==b1&&a2==b2)printf("1");
	else printf("0");
	if(a1==b1&&a2==b2&&(('A'<=a3&&a3<='C'&&'A'<=b3&&b3<='C')||('D'<=a3&&a3<='E'&&'D'<=b3&&b3<='E')))printf("1");
	else printf("0");
	if(a1==b1&&a2==b2&&(('A'<=a3&&a3<='C'&&'A'<=b3&&b3<='C')||('D'<=a3&&a3<='E'&&'D'<=b3&&b3<='E'))&&(a3-1==b3||b3-1==a3))printf("1");
	else printf("0");
	return 0;
}
