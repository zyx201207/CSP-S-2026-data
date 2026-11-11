#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);	
	string s1,s2,c1,c2;
	bool pd=true;
	cin>>s1>>c1>>s2>>c2;
	for(int i=0;i<2;i++)
	{
		if(s1[i]!=s2[i])
		{
			pd=false;
		}
	}
	if(pd==false)
	{
		cout<<"0000";
		return 0;
	}
	else
	{
		bool pd1=true;
		for(int i=0;i<2;i++)
		{
			if(c1[i]!=c2[i])
			{
				pd1=false;
			}
		}
		if(pd1==false)
		{
			cout<<"1000";
			return 0;
		}
		else
		{
			if(((c1[2]=='A'||c1[2]=='B'||c1[2]=='C')&&(c2[2]=='D'||c2[2]=='F'))||((c2[2]=='A'||c2[2]=='B'||c2[2]=='C')&&(c1[2]=='D'||c1[2]=='F')))
			{
				cout<<"1100";
				return 0;
			}
			if((c1[2]=='A'&&c2[2]=='B')||(c1[2]=='B'&&c2[2]=='C')||(c1[2]=='D'&&c2[2]=='F')||(c2[2]=='A'&&c1[2]=='B')||(c2[2]=='B'&&c1[2]=='C')||(c2[2]=='D'&&c1[2]=='F'))
			{
				cout<<"1111";
				return 0;
			}
			cout<<"1110";
			return 0;
		}
	}
	return 0;
}
