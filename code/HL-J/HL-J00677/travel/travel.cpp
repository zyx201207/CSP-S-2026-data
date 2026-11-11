#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char s1[5],s2[5],c1[2],c2[2];
	cin>>c1[0]>>c1[1];
	for(int i=0;i<3;i++)
		cin>>s1[i];
	cin>>c2[1]>>c2[1];
	for(int i=0;i<3;i++)
		cin>>s2[i];
	if(c1[0]!=c2[0]||c1[1]!=c2[1])
		cout<<"0000";
	else
	{
		cout<<'1';
		if(s1[1]==s2[1]&&s1[0]==s2[0])
		{
			cout<<'1';
			if(s1[2]=='A')
			{
				if(s2[2]=='B')
					cout<<"11";
				else if(s2[2]=='C')
					cout<<"10";
				else
					cout<<"00";
			}
			else if(s1[2]=='B')
			{
				if(s2[2]=='A'||s2[2]=='C')
					cout<<"11";
				else
					cout<<"00";
			}
			else if(s1[2]=='C')
			{
				if(s2[2]=='B')
					cout<<"11";
				else if(s2[2]=='A')
					cout<<"10";
				else
					cout<<"00";
			}
			else if(s1[2]=='D'&&s2[2]=='F'||s1[2]=='F'&&s2[2]=='D')
				cout<<"11";
			else
				cout<<"00";
		}
		else
			cout<<"000";
	}
		
	return 0;
} 
