#include<bits/stdc++.h>
using namespace std;
int xl(char m[5],char n[5])
{
	if((m[2]=='A')&&(n[2]=='B'))
	{
		return 1;
	}
	if((m[2]=='B')&&(n[2]=='C'))
	{
		return 1;
	}
	if((m[2]=='D')&&(n[2]=='F'))
	{
		return 1;
	}
	if((n[2]=='A')&&(m[2]=='B'))
	{
		return 1;
	}
	if((n[2]=='B')&&(m[2]=='C'))
	{
		return 1;
	}
	if((n[2]=='D')&&(m[2]=='F'))
	{
		return 1;
	}
	return 0;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int Rt,Xt;
	char Rw[5],Xw[5];
	cin>>Rt>>Rw>>Xt>>Xw;
	if(Rt==Xt)
	{
		cout<<1;
		if((Rw[0]==Xw[0])&&(Rw[1]==Xw[1]))
		{
			cout<<1;
			if((Rw[2]=='A')||(Rw[2]=='B')||(Rw[2]=='C'))
			{
				if((Xw[2]=='A')||(Xw[2]=='B')||(Xw[2]=='C'))
				{
					cout<<1;
					cout<<xl(Rw,Xw);
					
				}
				else
				{
					cout<<"00";
					return 0;
				}
			}
			else
			{
				if((Xw[2]=='D')||(Xw[2]=='F'))
				{
					cout<<1;
					cout<<xl(Rw,Xw);
				}
				else
				{
					cout<<"00";
					return 0;
				}
			}
		}
		else
		{
			cout<<"000";
			return 0;
		}
	}
	else
	{
		cout<<"0000";
		return 0;
	}
	return 0;
}
