#include<bits/stdc++.h>
using namespace std;
string a1,a2,b1,b2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>a2>>b1>>b2;
	if(a1==b1)
	{
		printf("1");
		if(a2.substr(0,2)==b2.substr(0,2))
		{
			printf("1");
			if((a2[2]<='C'&&b2[2]<='C')||(a2[2]>'C'&&b2[2]>'C'))
			{
				printf("1");
				if(abs(a2[2]-b2[2])<=1)printf("1");
				else printf("0");
			}
			else printf("00");
		}
		else printf("000");
	}
	else printf("0000");
	return 0;
}
