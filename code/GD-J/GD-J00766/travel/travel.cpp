#include <bits/stdc++.h>
using namespace std;
string ans,s1,s2;
int c1,c2;
bool f(char a,char b)
{
	return (s1[3]==a&&s2[3]==b)||(s2[3]==a&&s1[3]==b);
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	s1='0'+s1;
	s2='0'+s2;
	if(c1==c2)
	{
		ans+='1';
		if(s1[2]==s2[2]&&s1[1]==s2[1])
		{
			ans+='1';
			if(((s1[3]=='F'||s1[3]=='D')&&(s2[3]=='F'||s2[3]=='D'))||((s1[3]=='A'||s1[3]=='B'||s1[3]=='C')&&(s2[3]=='A'||s2[3]=='B'||s2[3]=='C')))
			{
				ans+='1';
				if(f('A','B')||f('C','B')||f('D','F'))
				ans+='1';
			}
		}
	}
	while(ans.size()<4)
		ans+='0';
	cout<<ans;
	return 0;
} 
