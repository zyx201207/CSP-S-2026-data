#include<bits/stdc++.h>
using namespace std;
string r1,r2,x1,x2;
int main()
{
	freopen("travel.in","r","stdin");
	freopen("travel.out","w","stdout");
	cin>>r1>>r2>>x1>>x2;
	if(r1==x1) cout<<"1";
	else
	{
		cout<<"0000";
		return 0;
	}
	if(r2[0]==x2[0]&&r2[1]==x2[1]) cout<<"1";
	else
	{
		cout<<"000";
		return 0;
	}
	bool f=0;
	if(r1==x1&&r2[0]==x2[0]&&r2[1]==x2[1])
	{
		if(r2[2]>='A'&&r2[2]<='C')
		{
			if(x2[2]>='A'&&x2[2]<='C')
			{
				cout<<"1";
				f=1;
			}
		}
		if(r2[2]>='D'&&r2[2]<='E')
		{
			if(x2[2]>='D'&&x2[2]<='E')
			{
				cout<<"1";
				f=1;
			}
		}
	}
	if(!f) cout<<"00";
	else
	{
		if((char)(r2[2]+1)==(char)(x2[2])||(char)(r2[2])==(char)(x2[2]+1)) cout<<"1";
		else cout<<"0";
	}
	return 0;
} 
