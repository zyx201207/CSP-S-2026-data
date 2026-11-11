#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout); 
	string c1,c2,s1,s2;
	cin>>c1>>s1>>c2>>s2;
	
	for(int i=0;i<c1.size();i++)
	{
		if(c1[i]-'0'!=c2[i]-'0')
		{
			cout<<"0000";
			return 0;
		}
	}
	if(s1[0]-'0'!=s2[0]-'0'||s1[1]-'0'!=s2[1]-'0')
	{
		cout<<"1000";
	}
	else
	{
		if(s1[2]-'A'<3&&s2[2]-'A'<3||s1[2]-'A'>2&&s2[2]-'A'>2)
		{
			if(abs(s1[2]-'A'-(s2[2]-'A'))==1||s1[2]=='D'&&s2[2]=='F'||s1[2]=='F'&&s2[2]=='D')
			{
				cout<<"1111";
			}
			else 
			{
				cout<<"1110";
			}
		}
		else {
			cout<<"1100";
		}
	}
	return 0;
} 
