#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2; 
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
			if((s1[s1.size()-1]=='D'&&s2[s2.size()-1]=='F')
			||(s1[s1.size()-1]=='F'&&s2[s2.size()-1]=='D')
			||(s1[s1.size()-1]!='F'&&s2[s2.size()-1]!='D'))
			{
				cout<<"1";
				if((s1[s1.size()-1]=='D'&&s2[s2.size()-1]=='F')
				||(s1[s1.size()-1]=='F'&&s2[s2.size()-1]=='D')
				||(s1[s1.size()-1]=='A'&&s2[s2.size()-1]=='B')
				||(s1[s1.size()-1]=='B'&&s2[s2.size()-1]=='A')
				||(s1[s1.size()-1]=='B'&&s2[s2.size()-1]=='C')
				||(s1[s1.size()-1]=='C'&&s2[s2.size()-1]=='B'))
				{
					cout<<"1";
				}
				else cout<<"0";
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}

