#include<bits/stdc++.h>
using namespace std;
string ans="0000";
string c1,s1,c2,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);  
	cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	bool f1=0;
	if(c1==c2)
	{
		ans="1000";
		f1=1;
	}
	char a=s1[2],b=s2[2];
	bool f=0;
	if(f1==1&&(s1[0]+s1[1]==s2[0]+s2[1]))
	{
		ans="1100";
		f=1;
	}
	if(f1==1&&f==1&&(a=='D'||a=='F'))
	{
		if(b=='D'||b=='F')
		{
			ans="1110";
			if(abs(a-b)==1)
			{
		         ans="1111";
			}
		}
	}
	else if(f1==1&&f==1&&(a=='A'||a=='B'||a=='C'))
	{
		if(b=='A'||b=='B'||b=='C')
		{
			ans="1110";
			if(abs(a-b)==1)
			{
				ans="1111";
			}
		}
	}
	cout<<ans;
}
