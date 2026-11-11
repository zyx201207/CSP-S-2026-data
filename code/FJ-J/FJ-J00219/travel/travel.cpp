#include<bits/stdc++.h>
using namespace std;
using ll=long long;
string c1,s1,c2,s2;
bool f(string a,string b)
{
	if(a[2]>='A'&&a[2]<='C')
	{
		if(b[2]>='A'&&b[2]<='C')
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	else
	{
		if(b[2]=='D'||b[2]=='F')
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		cout<<"1";
		if(s1[0]==s2[0]&&s1[1]==s2[1])
		{
			cout<<"1";
			if(f(s1,s2))
			{
				cout<<"1";
				if((s1[2]=='D'&&s2[2]=='F')||(abs(s1[2]-s2[2])==1))
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

