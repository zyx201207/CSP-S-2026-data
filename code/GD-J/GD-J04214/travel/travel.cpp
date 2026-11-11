#include<bits/stdc++.h>
using namespace std;
string cx,sx,cy,sy;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>cx>>sx>>cy>>sy;
	if(cx==cy) 
	{
		printf("1");
		if(sx[0]==sy[0]&&sx[1]==sy[1]) 
		{
			printf("1");
			if((sx[2]=='C'&&sy[2]=='D')||(sx[2]=='D'&&sy[2]=='C')) printf("00");
			else 
			{
				printf("1");
				if(abs((int)sx[2]-sy[2])==1) printf("1");
				else printf("0");
			}
		}
		else printf("000");	
	}
	else printf("0000");
	return 0;
}
