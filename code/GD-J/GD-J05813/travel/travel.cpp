#include<bits/stdc++.h>
using namespace std;
string rc,rh,xc,xh;
char nf[5];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	for(int i=1;i<=4;i++)
		{
			nf[i]='0';
		}
	cin>>rc>>rh>>xc>>xh;
	if(rc==xc)
	{
		nf[1]='1';
		if(rh[0]==xh[0]&&rh[1]==xh[1])
		{
			nf[2]='1';
			if(rh[2]<='C'&&xh[2]<='C')
			{
				nf[3]='1';
				if(rh[2]+1==xh[2]||rh[2]-1==xh[2])
				{
					nf[4]='1';
					for(int i=1;i<=4;i++)
		         {
			       cout<<nf[i];
		         }
				}
				else
				{
				    	for(int i=1;i<=4;i++)
		         {
			       cout<<nf[i];
		         }
				}
			}
			else
			{
				if(rh[2]>'C'&&xh[2]>'C')
				{
					nf[3]='1';
					if(rh[2]+1==xh[2]||rh[2]-1==xh[2])
				{
					nf[4]='1';
					for(int i=1;i<=4;i++)
		         {
			       cout<<nf[i];
		         }
				}
				else
				{
					for(int i=1;i<=4;i++)
		         {
			       cout<<nf[i];
		         }
				}
				}
				else
				{
					for(int i=1;i<=4;i++)
		         {
			       cout<<nf[i];
		         }
				}
			}
		}
		else
		{
			for(int i=1;i<=4;i++)
		{
			cout<<nf[i];
		}
		}
	}
	else
	{
		for(int i=1;i<=4;i++)
		{
			cout<<nf[i];
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
