#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a==c)
	{
		printf("1");
		if(b[0]==d[0]&&b[1]==d[1])
		{
			printf("1");
			if((b[2]<='C'&&d[2]<='C')||(b[2]>='D'&&d[2]>='D'))
			{
				printf("1");
				if((b[2]=='A'&&d[2]=='B')||(b[2]=='B'&&d[2]=='C')||(b[2]=='D'&&d[2]=='F')) printf("1");
				else printf("0");
			}
			else printf("00");
		}
		else printf("000");
	}
	else printf("0000");
	return 0;
}
