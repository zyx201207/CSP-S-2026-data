#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	int p1=(s1[0]-'0')*10+(s1[1]-'0');
	int p2=(s2[0]-'0')*10+(s2[1]-'0');
	char e1=s1[2],e2=s2[2];
	if(c1==c2)
	{
		cout<<"1";
		if(p1==p2)
		{
			cout<<"1";
			if(e1=='A'||e1=='B'||e1=='C')
			{
				if( e2!='D'&&e2!='F')
				{
					cout<<"1";
					if(e1=='A'&&e2=='C'||e1=='C'&&e2=='A')
					{
						cout<<"0";
						return 0;
					}
					else
					{
						cout<<"1";
						return 0;
					}
				}
				else
				{
					cout<<"00";
					return 0;
				}
			}
			else if(e1=='D'||e1=='F')
			{
				if(e2!='A'&&e2!='B'&&e2!='C')
				{
					cout<<"11";
					return 0;
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
	else cout<<"0000";
	
	return 0;
}
