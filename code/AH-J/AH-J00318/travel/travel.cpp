#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll check(char x,char y)
{
	if(x>y)	swap(x,y);
	if(x=='C'&&y=='D')	return 0;
	if(x>='A'&&x<='C'&&y>='A'&&y<='C')
	{
		if(char(x+1)==y)	return 1;
		else	return 0;
	}
	else	return 1;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a==c)	
	{
		printf("1");
		if(b.substr(0,2)==d.substr(0,2))
		{
			printf("1");
			if(b[2]>='A'&&b[2]<='C'&&d[2]>='A'&&d[2]<='C'||b[2]>='D'&&b[2]<='F'&&d[2]>='D'&&d[2]<='F')
			{
				printf("1");
				if(check(b[2],d[2])==1)	printf("1");
				else	printf("0");
			}
			else	printf("00");
		}
		else	printf("000");
	}
	else	printf("0000");
	return 0;
}
