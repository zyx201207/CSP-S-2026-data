#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(NULL),cin.tie(0),cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		cout<<1;
		if(s1[0]==s2[0]&&s1[1]==s2[1])
		{
			cout<<1;
			bool f1=0,f2=0;
			if(s1[2]=='D'||s1[2]=='F')
			{
				f1=1;
			}
			if(s2[2]=='D'||s2[2]=='F')
			{
				f2=1;
			}
			if(f1==f2)
			{
				cout<<1;
				int x1=s1[2]-'A';
				int x2=s2[2]-'A';
				if(abs(x1-x2)==1)
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
