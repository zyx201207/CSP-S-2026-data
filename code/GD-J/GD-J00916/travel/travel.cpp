#include <bits/stdc++.h>

using namespace std;
long long c1,c2,sp1,sp2;
string s1,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	for(int i=0;i<s1.size()-1;i++)
	{
		sp1=sp1*10+(s1[i]-'0');
	}
	for(int i=0;i<s2.size()-1;i++)
	{
		sp2=sp2*10+(s2[i]-'0');
	}
	if(c1==c2)
	{
		cout<<1;
		if(sp1==sp2)
		{
			cout<<1;
			if((s1[2]>='A'&&s1[2]<='C')&&(s2[2]>='A'&&s2[2]<='C')||(s1[2]>='D'&&s1[2]<='F')&&(s2[2]>='D'&&s2[2]<='F'))
			{
				cout<<1;
				if(max(s1[2],s2[2])-min(s1[2],s2[2])==1)
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
