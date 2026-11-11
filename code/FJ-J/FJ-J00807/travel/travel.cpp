#include<bits/stdc++.h>
using namespace std;
char a[15];
int a1,a2,a3,a4;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	a1=a2=a3=a4=0;
	for(int i=1;i<=13;++i)
	{
		scanf("%c",&a[i]);
		if(i==13) break;
	}
	if(a[1]==a[8] && a[2]==a[9]) a1=1;
	if(a[5]==a[12] && a[4]==a[11] && a1==1) a2=1;
	if(a[6]<='C' && a[13]<='C' && a2==1) a3=1;
	else if(a[6]>'C' && a[13]>'C' && a2==1) a3=1;
	if( (a[6]-a[13]==1 || a[13]-a[6]==1) && a3==1) a4=1;
	printf("%d%d%d%d",a1,a2,a3,a4);
	return 0;
}
