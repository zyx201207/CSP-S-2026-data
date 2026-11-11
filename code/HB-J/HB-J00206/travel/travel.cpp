#include<bits/stdc++.h>
using namespace std;
char a[2],b[3],x[2],y[3];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>x>>y;
	if(a[0]==x[0]&&a[1]==x[1])
	{
		printf("1");
	}else
	printf("0");
	if(a[0]==x[0]&&a[1]==x[1]&&b[0]==y[0]&&b[1]==y[1])
	{
		printf("1");
	}else
	printf("0");
	bool h=false,g=false;
	if(a[0]==x[0]&&a[1]==x[1]&&b[0]==y[0]&&b[1]==y[1])
	{
		if(b[2]=='A'||b[2]=='B'||b[2]=='C')
		{
			h=true;
		}
		if(y[2]=='A'||y[2]=='B'||y[2]=='C')
		{
			g=true;
		}
		if((h==true&&g==true)||(h==false&&g==false))
		{
			printf("1");
		}else
		printf("0");
	}else
	printf("0");
	if(a[0]==x[0]&&a[1]==x[1]&&b[0]==y[0]&&b[1]==y[1]&&((h==true&&g==true)||(h==false&&g==false)))
	{
		if(b[2]==y[2]+1||b[2]==y[2]-1)
		{
			if((b[2]=='C'&&y[2]=='D')||(b[2]=='D'&&y[2]=='C'))
			{
				printf("0");
				return 0;
			}
			printf("1");
		}else
		printf("0");
	}else
	printf("0");
	return 0;
}
