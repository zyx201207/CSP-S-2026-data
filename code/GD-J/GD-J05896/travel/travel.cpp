#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int a1=0,b1=0,a2=0,b2=0;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c1>>s1>>c2>>s2;
	for (int i=0;i<2;i++)
	{
		a1=(a1<<3)+(a1<<1)+(c1[i]^48);
		a2=(a2<<3)+(a2<<1)+(c2[i]^48);
	}
	if (a1==a2)
	{
		printf("1");
		for (int i=0;i<2;i++)
		{
			b1=(b1<<3)+(b1<<1)+(s1[i]^48);
			b2=(b2<<3)+(b2<<1)+(s2[i]^48);
		}
		if (b1==b2)
		{
			printf("1");
			if((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'))
			{
				printf("1");
				if (s1[2]=='B'||s2[2]=='B')
				{
					printf("1\n");
				}
				else
				{
					printf("0\n");
				}
			}
			else if ((s1[2]=='D'||s1[2]=='F')&&(s2[2]=='D'||s2[2]=='F'))
			{
				printf("11\n");
			}
			else
			{
				printf("00\n");
			}
		}
		else
		{
			printf("000\n");
		}
	}
	else
	{
		printf("0000\n");
	}
	return 0;
}
