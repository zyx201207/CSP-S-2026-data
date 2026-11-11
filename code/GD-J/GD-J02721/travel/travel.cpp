#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,ans;
bool check(string s1,string s2)
{
	if (s1[2]>='A'&&s1[2]<='C')
		return s2[2]>='A'&&s2[2]<='C';
	else
		return (s2[2]=='D')||(s2[2]=='F');
}
bool check2(string s1,string s2)
{
	if (s1[2]>='A'&&s1[2]<='C')
		return (s2[2]!='D')&&(abs(s1[2]-s2[2])==1);
	else if (s1[2]=='D')
		return s2[2]=='F';
	else
		return s2[2]=='D';
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if (c1==c2)
		ans+='1';
	else
		ans+='0';
	if (c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1])
		ans+='1';
	else
		ans+='0';
	if (c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]&&check(s1,s2))
		ans+='1';
	else
		ans+='0';
	if (c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]&&check(s1,s2)&&check2(s1,s2))
		ans+='1';
	else
		ans+='0';
	cout<<ans;
}
