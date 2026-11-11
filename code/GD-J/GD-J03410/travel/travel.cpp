#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a1,s1;
	string a2,s2;
	cin>>a1>>a2>>s1>>s2;
	if(a1==s1)
	{
		if(a2[0]==s2[0] && a2[1]==s2[1])
		{
			if(a2[2]=='D' || a2[2]=='F') a2[2]='1';
			if(s2[2]=='D' || s2[2]=='F') s2[2]='1';
			if(a2[2]=='1' && s2[2]=='1') cout<<"1111";
			else if(a2[2]!='1' && s2[2]!='1')
			{
				if(a2[2]=='B' || s2[2]=='B') cout<<"1111";
				else cout<<"1110";
			}
			else cout<<"1100";
		}
		else cout<<"1000";
	}
	else cout<<"0000";
	return 0;
 } 
