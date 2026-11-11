#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b;
	string s1,s2,ans="";
	cin>>a>>s1>>b>>s2;
	if(a==b)
	{
		ans+='1';
		if(s1[0]==s2[0]&&s1[1]==s2[1])
		{
			ans+='1';
			if(s1[2]=='D'&&s2[2]=='F')ans+='1';
			else if(s1[2]=='F'&&s2[2]=='D')ans+='1';
			else if((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='A'&&s2[2]=='C'))ans+='1';
			else if((s1[2]=='B'&&s2[2]=='A')||(s1[2]=='B'&&s2[2]=='C'))ans+='1';
			else if((s1[2]=='C'&&s2[2]=='A')||(s1[2]=='C'&&s2[2]=='B'))ans+='1';
			else ans+='0';
			
			if(s1[2]=='D'&&s2[2]=='F')ans+='1';
			else if(s1[2]=='F'&&s2[2]=='D')ans+='1';
			else if(s1[2]=='A'&&s2[2]=='B')ans+='1';
			else if((s1[2]=='B'&&s2[2]=='A')||(s1[2]=='B'&&s2[2]=='C'))ans+='1';
			else if(s1[2]=='C'&&s2[2]=='B')ans+='1';
			else ans+='0';
		}
		else ans+="000";
	}
	else ans+="0000";
	cout<<ans;
	return 0;
}