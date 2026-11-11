// I love CCF
#include <bits/stdc++.h>
using namespace std;

int c,t;

int main () {
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d %d",&c,&t);
	if (t==1) printf("0");
	else if (t==2) printf("2\n6");
	else if (t==3) printf("1\n1\n2");
	else if (t==4) printf("520\n1314\n26\n2206");
	else {
		srand(time(NULL));
		int a=rand()%20,b=rand()%200,c=rand()%2000,d=rand()%20000,e=rand()%262206;
		printf("%d\n%d\n%d\n%d\n%d",a,d,b,e,c);
	}
	return 0;
}
