#include<bits/stdc++.h>
using namespace std;
int a,b;
string c,d;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>c>>b>>d;
	if(a==b)
	{
		cout<<"1";
		if(c[0]==d[0]&&c[1]==d[1])
		{
			cout<<"1";
			if(c[2]=='D'||c[2]=='F')
			{
				if(d[2]=='D'||d[2]=='F')
				{
					cout<<"11";
				}
				else
				{
					cout<<"00";
				}
			}
			else
			{
				if(d[2]!='D'&&d[2]!='F')
				{
					cout<<"1";
					if(abs(d[2]-c[2])==1)
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
