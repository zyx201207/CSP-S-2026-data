#include<bits/stdc++.h>
using namespace std;

string c1,s1,c2,s2;//c是车厢，s是座位号 

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1[0]!=c2[0]||c1[1]!=c2[1])
	{
		cout<<"0000";
		return 0;
	}
	else
	{
		cout<<1;
	}
	
	
	if(s1[1]!=s2[1]||s2[0]!=s1[0])//判断同一排 
	{
		cout<<"000";
		return 0; 
	}
	else
	{
		cout<<1;
	}
	
	if(s1[2]=='D'&&s2[2]=='C')
	{
		cout<<"00";
		return 0;
	}
	
	if(s1[2]=='C'&&s2[2]=='D')
	{
		cout<<"00";
		return 0;
	}
	
	if(s1[2]=='F'&&s2[2]=='D' || s1[2]=='D'&&s2[2]=='F')//判断同一侧 
	{
		cout<<11;
		return 0;
	}
	else
	{
		if(s1[2]=='A'&&s2[2]=='D' || s1[2]=='B'&&s2[2]=='D' || s1[2]=='C'&&s2[2]=='D' || s1[2]=='A'&&s2[2]=='F' || s1[2]=='B'&&s2[2]=='F' || s1[2]=='C'&&s2[2]=='F' 
		|| s2[2]=='A'&&s1[2]=='D' || s2[2]=='B'&&s1[2]=='D' || s2[2]=='C'&&s1[2]=='D' || s2[2]=='A'&&s1[2]=='F' || s2[2]=='B'&&s1[2]=='F' || s2[2]=='C'&&s1[2]=='F')
		{
			cout<<00;
			return 0;
		}
		else if(s1[2]=='C'&&s2[2]=='D' || s1[2]=='D'&&s2[2]=='C')
		{
			cout<<00;
			return 0;
		}
		else
		{
			cout<<1;
			if(s1[2]=='B'||s2[2]=='B')//判断在ABC一侧是否相连 
			{
				cout<<1;
				return 0;
			}
			else
			{
				cout<<0;
				return 0;
			}
			
		}
	}
		
	return 0;
}
