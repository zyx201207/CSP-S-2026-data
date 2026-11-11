#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
typedef long long ll;

string c1,s1,c2,s2;

inline bool pdside(string cscs)
{
	if(cscs[2]=='A'||cscs[2]=='B'||cscs[2]=='C')
	{
		return false;
	}
	else
	{
		return true;
	}
}

inline bool ppside(string cscs,string scsc)
{
	if(cscs[2]=='D'&&scsc[2]=='F')
	{
		return true;
	}
	if(scsc[2]=='D'&&cscs[2]=='F')
	{
		return true;
	}
	if(cscs[2]=='A'&&scsc[2]=='B')
	{
		return true;
	}
	if(scsc[2]=='A'&&cscs[2]=='B')
	{
		return true;
	}
	if(cscs[2]=='B'&&scsc[2]=='C')
	{
		return true;
	}
	if(scsc[2]=='B'&&cscs[2]=='C')
	{
		return true;
	}
	return false;
}

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1!=c2)
	{
		printf("0000");
	}
	else
	{
		printf("1");
		if(s1[0]==s2[0]&&s1[1]==s2[1])
		{
			printf("1");
			if(pdside(s1)==pdside(s2))
			{
				printf("1");
				if(ppside(s1,s2))
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
	fclose(stdin);
	fclose(stdout);
	return 0;
}
