#include <bits/stdc++.h>
using namespace std;

int side(char c)
{
	if(c=='A'||c=='B'||c=='C')return 1;
	return 2;
}

int AtoN(char c)
{
	if(c=='A')return 1;
	if(c=='B')return 2;
	if(c=='C')return 3;
	if(c=='D')return 4;
	return 5;
}

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie();

	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	char s1a=s1[0],s1b=s1[1],s1c=s1[2];
	char s2a=s2[0],s2b=s2[1],s2c=s2[2];

	if(c1==c2)
	{
		cout<<"1";
		if(s1a==s2a && s1b==s2b)
		{
			cout<<"1";
			if(side(s1c)==side(s2c))
			{
				cout<<"1";
				cout<<(abs(AtoN(s1c)-AtoN(s2c))==1);
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
