#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int s1s=0,s2s=0,o1=0,o2=0;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)o1=1;
	cout<<o1;
	for(int i=0;i<3;i++)
	{
		s1s=s1[0]+s1[1];
		s2s=s2[0]+s2[1];
		break;
	}
	if(o1==0)o2=0;
	else if(s1s==s2s)o2=1;
	cout<<o2;
	for(int i=0;i<3;i++)
	{
		if(o2==1)
		{
			if(s1[2]=='A')
			{
				if(s2[2]=='B')cout<<"11";
				else if(s2[2]=='C')cout<<"10";
				else cout<<"00";
			}
			else if(s1[2]=='B')
			{
				if(s2[2]=='A')cout<<"11";
				else if(s2[2]=='C')cout<<"11";
				else cout<<"00";
			}
			else if(s1[2]=='C')
			{
				if(s2[2]=='A')cout<<"10";
				else if(s2[2]=='B')cout<<"11";
				else cout<<"00";
			}
			else if(s1[2]=='D')
			{
				if(s2[2]=='F')cout<<"11";
				else cout<<"00";
			}
			else if(s1[2]=='F')
			{
				if(s2[2]=='D')cout<<"11";
				else cout<<"00";
			}
		}
		else cout<<"00";
		break;
	}
}
