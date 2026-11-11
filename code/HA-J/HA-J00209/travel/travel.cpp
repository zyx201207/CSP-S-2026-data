#include<bits/stdc++.h>
using namespace std;
string m;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	int t=0,sum=0;
	cin>>c1>>s1>>c2>>s2;
	for(int i=0;i<2;i++)
		{
		if(c1[0]==c2[0]&&c1[1]==c2[1])
		m[1]+='1';
		else
		{
			m+='0';
		}	
		}
		for(int i=0;i<3;i++)
		{
			if((s1[0]==s2[0]&&s1[1]==s2[1])&&(s1[2]=='A'&&s2[1]=='B')&&(s1[2]=='B'&&s2[2]=='A')&&(s1[2]=='B'&&s2[1]=='C')&&(s1[2]=='C'&&s2[2]=='B'))
			{
			for(int i=1;i<4;i++ )
			{
				m[i]+='1';
			}
			}
			else if((s1[0]==s2[0]&&s1[1]==s2[1])&&(s1[2]=='F'&&s2[1]=='D')&&(s1[2]=='D'&&s2[2]=='F'))
			{
				for(int i=1;i<4;i++ )
			{
				m[i]+='1';
			}
			}
			else
			{
			for(int i=1;i<4;i++)
			{
				m[i]+='0';
			}
			}
		}
		cout<<m;
		
}
