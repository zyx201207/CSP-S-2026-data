#include<bits/stdc++.h>
using namespace std;
int c1;
int c2;
string s1;
string s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	
	cin>>c1;
	cin>>s1;
	cin>>c2;
	cin>>s2;
	if(c1==c2) 
	{
		cout<<1;
		int t1=(s1[0]+'0')*10+(s1[1]+'0');
		int t2=(s2[0]+'0')*10+(s2[1]+'0');
		if(t1==t2)
		{
			cout<<1;
			if((s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C')||(s1[2]>='D'&&s1[2]<='F'&&s2[2]>='D'&&s2[2]<='F'&&s2[2]!='E'&&s1[2]!='E'))
			{
				cout<<1;
				if(s1[2]==s2[2]+1||s1[2]==s2[2]-1||(s2[2]=='D'&&s1[2]=='F')||(s2[2]=='F'&&s1[2]=='D')) cout<<1;
				else cout<<0;
			}
			else
			{
				cout<<0;
				cout<<0;
			}
		}
		else 
		{
			cout<<0;
			cout<<0;
			cout<<0;
		}
	}
	else 
	{
		cout<<0;
		cout<<0;
		cout<<0;
		cout<<0;
	}
	return 0;
}
