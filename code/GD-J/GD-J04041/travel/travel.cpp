#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,s1,s2;
	cin>>c1>>s1>>c2>>s2;
	int cr=(c1[0]-'0')*10+(c1[1]-'0');
	int cx=(c2[0]-'0')*10+(c2[1]-'0');
	string cnt;
	int sr=(s1[0]-'0')*10+(s1[1]-'0');
	int sx=(s2[0]-'0')*10+(s2[1]-'0');
	if(cr==cx)
	{
		cnt+='1';
		if(sr==sx)
		{
			cnt+='1';
			if(s1[2]=='A'&&s2[2]=='B')
			{
				cnt+='1';
			}
			else if(s1[2]=='B'&&s2[2]=='A')
			{
				cnt+='1';
			}
			else if(s1[2]=='C'&&s2[2]=='A')
			{
				cnt+='1';
			}
			else if(s1[2]=='A'&&s2[2]=='C')
			{
				cnt+='1';
			}
			else if(s1[2]=='C'&&s2[2]=='B')
			{
				cnt+='1';
			}
			else if(s1[2]=='B'&&s2[2]=='C')
			{
				cnt+='1';
			}
			else if(s1[2]=='D'&&s2[2]=='F')
			{
				cnt+='1';
			}
			else if(s1[2]=='F'&&s2[2]=='D')
			{
				cnt+='1';
			}
			else
			{
				cnt+='0';
			}
			if(s1[2]=='A'&&s2[2]=='B')
			{
				cnt+='1';
			}
			else if(s1[2]=='B'&&s2[2]=='A')
			{
				cnt+='1';
			}
			else if(s1[2]=='C'&&s2[2]=='B')
			{
				cnt+='1';
			}
			else if(s1[2]=='B'&&s2[2]=='C')
			{
				cnt+='1';
			}
			else if(s1[2]=='D'&&s2[2]=='F')
			{
				cnt+='1';
			}
			else if(s1[2]=='F'&&s2[2]=='D')
			{
				cnt+='1';
			}
			else
			{
				cnt+='0';
			}
		}
		else
		{
			cnt+="000";
		}
	}
	else
	{
		cnt+="0000";
	}
	
	cout<<cnt;
	return 0;
}
