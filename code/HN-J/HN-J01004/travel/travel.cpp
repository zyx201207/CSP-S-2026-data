#include<bits/stdc++.h>
using namespace std;
char a[10],b[10],c[10],d[10];
int a2,b2,c2,d2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%c%c %c%c%c %c%c %c%c%c",&a[0],&a[1],&b[0],&b[1],&b[2],&c[0],&c[1],&d[0],&d[1],&d[2]);
	if(a[0]==c[0]&&a[1]==c[1])a2=1;
	else{
		printf("%d%d%d%d\n",a2,b2,c2,d2);
		return 0;
	}
	if(b[0]==d[0]&&b[1]==d[1])b2=1;
	else{
		printf("%d%d%d%d\n",a2,b2,c2,d2);
		return 0;
	}
	if((b[2]=='A'&&(d[2]=='B'||d[2]=='C'))||(b[2]=='B'&&(d[2]=='A'||d[2]=='C'))||(b[2]=='C'&&(d[2]=='B'||d[2]=='A'))||(b[2]=='D'&&d[2]=='F')||(b[2]=='F'&&d[2]=='D'))c2=1;
	else{
		printf("%d%d%d%d\n",a2,b2,c2,d2);
		return 0;
	}
	if((b[2]=='D'&&d[2]=='C')||(b[2]=='C'&&d[2]=='D')){
		printf("%d%d%d%d\n",a2,b2,c2,d2);
		return 0;
	}
	if(b[2]==d[2]+1||b[2]+1==d[2]||(b[2]=='D'&&d[2]=='F')||(b[2]=='F'&&d[2]=='D'))d2=1;
	printf("%d%d%d%d",a2,b2,c2,d2);
	return 0;
}
