#include<bits/stdc++.h> 
using namespace std;
string t,s,c,d;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c>>s>>d>>t;
	if(c==d)
	{
		printf("1");
		int a=(s[0]-'0')*10+s[1]-'0';
		int b=(t[0]-'0')*10+t[1]-'0';
		if(a==b)
		{
			printf("1");
			char x=s[2];
			char y=t[2];
			if((x<='C')==(y<='C'))
			{
				printf("1");
				if(abs(y-x)==1)
				{
					printf("1");
				}
				else
				{
					printf("0");
				}
			} 
			else
			{
				printf("00");
			}
		}
		else
		{
			printf("000");
		}
	}
	else
	{
		printf("0000");
	}
	return 0;
}
