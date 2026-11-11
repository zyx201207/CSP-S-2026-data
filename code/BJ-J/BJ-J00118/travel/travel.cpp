#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	string a2,b2;
	int a1,b1;
	cin>>a1>>a2>>b1>>b2;
	if(a1==b1)
	{
		cout<<"1";
		
		int n=(a2[0]-'0')*10+(a2[1]-'0');
		int m=(b2[0]-'0')*10+(b2[1]-'0');
		if(m==n)
		{
			cout<<"1";
			
			if((a2[2]>='A'&&a2[2]<='C'&&a2[2]>='A'&&a2[2]<='C')||(a2[2]>='D'&&a2[2]<='E'&&a2[2]>='D'&&a2[2]<='E'))
			{
				cout<<"1";
				
				if(abs((a2[2]-'A')-(b2[2]-'A'))==1)
				{
					cout<<"1";
				}
				else
				{
					cout<<"0";
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
