#include<bits/stdc++.h>
using namespace std;
int a,b;
char x[10],y[10];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%s%d%s",&a,x,&b,y);
	if(a!=b) printf("0000");
	else if(x[0]!=y[0]||x[1]!=y[1]) printf("1000");
	else if(x[2]=='A'&&y[2]=='B') printf("1111");
	else if(x[2]=='B'&&y[2]=='A') printf("1111");
	else if(x[2]=='B'&&y[2]=='C') printf("1111");
	else if(x[2]=='C'&&y[2]=='B') printf("1111");
	else if(x[2]=='D'&&y[2]=='E') printf("1111");
	else if(x[2]=='E'&&y[2]=='D') printf("1111");
	else if(x[2]=='A'&&y[2]=='C') printf("1110");
	else if(x[2]=='C'&&y[2]=='A') printf("1110");
	else printf("1100");
	fclose(stdin);
	fclose(stdout);
	return 0;
}
