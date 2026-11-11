#include <bits/stdc++.h>
using namespace std;
char c1[3];
char s1[4];
char c2[3];
char s2[4];
string ans;
int main()	
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	for (int i=0;i<2;i++)
	{
		cin >>c1[i];
	}
	for (int i=0;i<3;i++)
	{
		cin >> s1[i];
	}
	for (int i=0;i<2;i++)
	{
		cin >>c2[i];
	}
	for (int i=0;i<3;i++)
	{
		cin >> s2[i];
	}
	
	if (c1[0]==c2[0]&&c1[1]==c2[1])
	{
		ans+="1";
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			ans+="1";
			if(((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'))||((s1[2]=='D'||s1[2]=='F')&&(s2[2]='D'||s2[2]=='F')))
			{
				ans+="1";
				if ((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&(s2[2]=='A'||s2[2]=='C'))||(s1[2]=='C'&&s2[2]=='B')||(s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D')){
					ans+="1";
				}
				else
				{
					ans+="0";
				}
				
				
			}
			else
			{
				ans+="00";
			}
		}
		else
		{
			ans+="000";
		}
		
	}
	else{
		
		ans+="0000";
	}

	cout <<ans;
	
	
	
	
	
	return 0;
}
