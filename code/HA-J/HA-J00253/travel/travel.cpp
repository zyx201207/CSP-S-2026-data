#include<bits/stdc++.h>
using namespace std;
int a,b;
string s,x;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	int tie(0);
	cin>>a;
	for(int i=1;i<4;i++)
	{
		cin>>s[i];
	}
	cin>>b;
	for(int i=1;i<4;i++)
	{
		cin>>x[i];
	}
	if(a==b)
	{
		cout<<"1";
		if(s[1]==x[1]&&s[2]==x[2])
		{
			cout<<"1";
			if(('A'<='x[3]'&&'x[3]'<='C'&&'A'<='s[3]'&&'s[3]'<='C')||('D'<=x[3]&&x[3]<='F'&&'D'<=s[3]&&s[3]<='F'))
			{
				cout<<"1";
				if('s[3]'+1=='x[3]'||'s[3]'-1=='x[3]')
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
