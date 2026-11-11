#include <bits/stdc++.h>
using namespace std;
int main ()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char cr[4],sr[4],cx[4],sx[4];
	scanf("%s%s%s%s",&cr,&sr,&cx,&sx);
	if(cr[1]==cx[1])
	{
		printf("1");
		if((sr[0]*10+sr[1]) == (sx[0]*10+sx[1]))
		{
			printf("1");
			if((sr[2]=='D' && sx[2]=='F') || (sr[2]=='F' && sx[2]=='D') || 
			(sr[2]=='A' && (sx[2]=='B' || sx[2]=='C')) || (sr[2]=='B' && (sx[2]=='A' || sx[2]=='C')) ||
			(sr[2]=='C' && (sx[2]=='A' || sx[2]=='b')))
			{
				printf("1");
				int a,b;
				a=int(sr[2]); b=int(sx[2]);
				if((a-b==1 || b-a==1) && (sr[2]!='C' && sx[2]!='D') && (sr[2]!='D' && sx[2]!='C'))
				{
					printf("1\n");
				}
				else
				{
					printf("0\n");
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
