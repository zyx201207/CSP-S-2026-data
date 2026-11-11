#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2)
	{
		cout<<"0000";
	}
	else
	{
		cout<<"1";
		if(s1.substr(0,2)==s2.substr(0,2))
		{
			cout<<"1";
			if(((s1[2]=='A'||s1[2]=='B')||s1[2]=='C')&&((s2[2]=='A'||s2[2]=='B')||s2[2]=='C'))
			{
				cout<<"1";
				if(abs(int(s1[2]-s2[2]))==1&&char(max((int)s1[2],(int)s2[2]))!='F')
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
			return 0;
		}
	}
	return 0;
}
