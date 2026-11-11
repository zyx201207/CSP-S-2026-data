#include<bits/stdc++.h>
using namespace std;
string s,s2,z,z2;
char a[10]={'A','B','C','D','F'};
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s>>s2>>z>>z2;
	if(s==z)
	{
		cout<<1;
		if(s2[0]==z2[0] && s2[1]==z2[1])
		{
			cout<<1;
			int b=0,d=0;
			for(int i=0;i<=4;i++)
			{
				if(s2[2]==a[i] && i<=2)
				{
					b=1;	
				}	
				else if(s2[2]==a[i])
				{
					b=2;
				}
				if(z2[2]==a[i] && i<=2)
				{
					d=1;
				}
				else if(z2[2]==a[i])
				{
					d=2;
				}
			}	
			if(b==d)
			{
				cout<<1;
				if(s2[2]==char(int(z2[2])+1) || s2[2]==char(int(z2[2])-1))
				{
					cout<<1;
				}
				else
				{
					cout<<0;
				}
			}
			else
			{
				cout<<"00";
			}
		}	
		else
		{
			cout<<"000";
		}
	} 
	else
	{
		cout<<"0000";
	}
	return 0;
}
