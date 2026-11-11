#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2,ans;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		ans=ans+"1";
		if(s1[0]==s2[0]&&s1[1]==s2[1])
		{
			ans=ans+"1";
			if(('A'<=s1[2]&&s1[2]<='C'&&'A'<=s2[2]&&s2[2]<='C'))
			{
				ans=ans+"1";
				long long t=s1[2]-'A'+s2[2]-'A';
				if(t%2!=0)
					ans=ans+'1';
				else
					ans=ans+'0';
			}
			else if('D'<=s1[2]&&s1[2]<='F'&&'D'<=s2[2]&&s2[2]<='F')
				ans=ans+"11";
			else
				ans=ans+"00";
		}
		else
			ans=ans+"000";
	}
	else
		ans=ans+"0000";
	cout<<ans;
}
