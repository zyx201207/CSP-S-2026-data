#include<bits/stdc++.h>
using namespace std;
char x[15],y[15],xx[15],yy[15];
int sum1,sum2,f[15]={1,1,1,2,2};
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%s%s%s%s",x+1,y+1,xx+1,yy+1);
	sum1=(x[1]-'0')*10+x[2]-'0';
	sum2=(xx[1]-'0')*10+xx[2]-'0';
	if(sum1==sum2) printf("1");
	else{
		printf("0000");
		return 0;
	}
	sum1=(y[1]-'0')*10+y[2]-'0';
	sum2=(yy[1]-'0')*10+yy[2]-'0';
	if(sum1==sum2) printf("1");
	else{
		printf("000");
		return 0;
	}
	if(f[y[3]-'A']==f[yy[3]-'A'])
		printf("1");
	else{
		printf("00");
		return 0;
	}
	if(f[y[3]-'A']==2||abs(y[3]-yy[3])==1)
		printf("1");
	else printf("0");
	return 0;
}
