#include <bits/stdc++.h>
using namespace std;
long long n,m;
string s,x;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>s>>m>>x;
	if(n!=m)
	{
		cout<<"0000";
		return 0;
	}
	else
	{
		cout<<1;
		if(s[0]==x[0] && s[1]==x[1])
		{
			cout<<1;
			if(s[2]<='C' && x[2]<='C')
			{
				cout<<1;
				if(x[2]=='B' && (s[2]=='A' || s[2]=='C'))
				{
					cout<<1;
				}
				else
				if(s[2]=='B' && (x[2]=='A' || x[2]=='C'))
				{
					cout<<1;
				}
				else
				{
					cout<<0;
				}
			} 
			else
			if(s[2]>'C' && x[2]>'C')
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
			cout<<"000";
			return 0;
		}
	}
	return 0;
}
//Àî¼Î¾þ GD-J03853
