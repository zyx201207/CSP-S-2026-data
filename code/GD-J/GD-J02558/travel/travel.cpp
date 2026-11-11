#include<iostream>
using namespace std;
string a1,s1,a2,s2;
int main()
{

	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>a1>>s1>>a2>>s2;
	if(a1==a2)
	{
		cout<<1;
		if(s1[0]==s2[0]&&s1[1]==s2[1])
		{
			cout<<1;
			if(((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'))||((s1[2]=='D'||s1[2]=='E')&&(s2[2]=='D'||s2[2]=='E')))
			{
				cout<<1;
				if(s1[2]==s2[2]+1||s1[2]==s2[2]-1)
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
