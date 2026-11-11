#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,ans;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	ans[3]='0';
	ans[4]='0';
	if(c1==c2)
	{
		if(s1[0]==s2[0] && s1[1]==s2[1])
		{
			if(s1[2]=='A' && s2[2]=='B')
				ans[3]='1';
			if(s1[2]=='B' && s2[2]=='A')
				ans[3]='1';
			if(s1[2]=='A' && s2[2]=='C')
				ans[3]='1';
			if(s1[2]=='C' && s2[2]=='A')
				ans[3]='1';
			if(s1[2]=='C' && s2[2]=='B')
				ans[3]='1';
			if(s1[2]=='B' && s2[2]=='C')
				ans[3]='1';
			if(s1[2]=='D' && s2[2]=='F')
				ans[3]='1';
			if(s1[2]=='F' && s2[2]=='D')
				ans[3]='1';
			
			if(ans[3]=='1')
			{
				if(s1[2]=='A' && s2[2]=='B')
					ans[4]='1';
				if(s1[2]=='B' && s2[2]=='A')
					ans[4]='1';
				if(s1[2]=='C' && s2[2]=='B')
					ans[4]='1';
				if(s1[2]=='B' && s2[2]=='C')
					ans[4]='1';
				if(s1[2]=='F' && s2[2]=='D')
					ans[4]='1';
				if(s1[2]=='D' && s2[2]=='F')
					ans[4]='1';
				if(ans[4]=='1')
					cout<<"1111";
				else
					cout<<"1110";
			}
			else
				cout<<"1100";
		}
		else
			cout<<"1000";
	}
	else
		cout<<"0000";
	return 0;
}
