#include<bits/stdc++.h>
using namespace std;
string s,s1,s2,s3;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s>>s1>>s2>>s3;
	if(s!=s2)
	{
		cout<<"0000";
		return 0;
	}
	for(int i = 0;i<2;i++)
	{
		if(s1[i]!=s3[i])
		{
			cout<<"1000";
			return 0;
		}
	}
	if(((s1[2]==s3[2]-1||s1[2]-1==s3[2])&&s3[2]!='D')||(s1[2]=='D'&&s3[2]=='F'))
	{
		cout<<"1111";
		return 0;
	}
	if(s1[2]<='C'&&s3[2]<='C')
	{
		cout<<"1110";
		return 0;
	}
	cout<<"1100";
	return 0;
}
