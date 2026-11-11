#include<bits/stdc++.h>
using namespace std;

string a,x,b,y;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin>>a>>x>>b>>y;
	
	if(a==b)
	{
		printf("1");
		if(x[0]==y[0] && x[1]==y[1])
		{
			printf("1");
			if((x[2]>'C' && y[2]>'C') || (x[2]<='C' && y[2]<='C'))
			{
				printf("1");
				if(x[2]-1==y[2] || x[2]+1==y[2])
				{
					printf("1\n");
				}
				else
				{
					printf("0\n");
					return 0;
				}
			}
			else
			{
				printf("00\n");
				return 0;
			}
		}
		else
		{
			printf("000\n");
			return 0;
		}
	}
	else
	{
		printf("0000\n");
		return 0;
	}
}
