#include<bits/stdc++.h>
using namespace std;
string s1,c1,s2,c2;
int cnt;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1[0]==c2[0] && c1[1]==c2[1])
	{	
		cout<<"1";
		if(s1[0]==c1[0] && s1[1]==s2[1])
		{
			cout<<"1";
			if((s1[2]>='A' && s1[2]<='C') && (s2[2]>='A' && s2[2]<='C'))
			{
				cout<<"1";
				if(s1[2]=='A' && s2[2]=='B')
					cout<<"1";
				else if(s1[2]=='B' && s2[2]=='A')
					cout<<"1";
				else if(s1[2]=='B' && s2[2]=='C')
					cout<<"1";
				else if(s1[2]=='C' && s2[2]=='B')
					cout<<"1";
				else 
					cout<<"0";
			}
			else if((c1[2]>='D' && c1[2]<='E') && (c2[2]>='D' && c2[2]<='E'))
				cout<<"11";
			else
				cout<<"00";
		}
		else
			cout<<"000";
	}
	else
		cout<<"0000";
	return 0;
}
