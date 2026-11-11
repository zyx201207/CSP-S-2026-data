#include <bits/stdc++.h>
using namespace std;

char s[11];
int che1,che2,p1,p2,l1,l2,c;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%s",s+1);
	che1=(s[1]-'0')*10+(s[2]-'0');
	scanf("%c",&c);
	scanf("%s",s+1);
	p1=(s[1]-'0')*10+(s[2]-'0');
	l1=s[3]-'A'+1;
	scanf("%c",&c);
	
	scanf("%s",s+1);
	che2=(s[1]-'0')*10+(s[2]-'0');
	scanf("%c",&c);
	scanf("%s",s+1);
	p2=(s[1]-'0')*10+(s[2]-'0');
	l2=s[3]-'A'+1;
	if(l1==6)
		l1=5;
	if(l2==6)
		l2=5;
	if(che1==che2)
		printf("1");
	else
		printf("0");
	if(che1==che2 && p1==p2)
		printf("1");
	else
		printf("0");
	int a=2,b=2;
	if(l1<=3)
		a=1;
	if(l2<=3)
		b=1;
	if(che1==che2 && p1==p2 && a==b)
		printf("1");
	else
		printf("0");
	if(che1==che2 && p1==p2 && a==b && abs(l1-l2)==1)
		printf("1");
	else
		printf("0");
	printf("\n");
}
