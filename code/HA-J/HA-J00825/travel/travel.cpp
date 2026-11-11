#include<bits/stdc++.h>
using namespace std;
int main()
{
	struct s
	{
		long long x;
		string s;
	};
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	s a,b;
	cin>>a.x>>a.s>>b.x>>b.s;
	if(a.x==b.x)
	{
		cout<<"1";
		if((a.s[0]-'0')*10+(a.s[1]-'0')==(b.s[0]-'0')*10+(b.s[1]-'0'))
		{
			cout<<"1";
			if(((a.s[2]=='F'||a.s[2]=='D')&&(b.s[2]=='F'||b.s[2]=='D'))||((a.s[2]<='C'||a.s[2]>='A')&&(b.s[2]<='C'||b.s[2]>='A')))
			{
				cout<<"1";
				if(max(a.s[2],b.s[2])-min(a.s[2],b.s[2])==1)
				{
					cout<<"1";
					return 0;
				}
				else
				{
					cout<<"0";
					return 0;
				}
			}
			else
			{
				cout<<"00";
				return 0;
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
