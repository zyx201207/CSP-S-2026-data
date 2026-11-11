#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>s2>>s3>>s4;
	if(s1[1]==s3[1]&&s1[0]==s3[0])
	{
		if(s2[0]-'0'==s4[0]-'0'&&s2[1]-'0'==s4[1]-'0')
		{
			if(s2[2]>='A'&&s2[2]<='C'&&s4[2]>='A'&&s4[2]<='C')
			{
				if(s2[2]=='A'&&s3[2]=='B')
					cout<<"1111";
				else if(s2[2]=='B'&&s3[2]=='A')
					cout<<"1111";
				else if(s2[2]=='C'&&s3[2]=='B')
					cout<<"1111";
				else if(s2[2]=='B'&&s3[2]=='C')
					cout<<"1111";
				else
					cout<<"1110";
			}
			else if(s2[2]>='D'&&s2[2]<='F'&&s4[2]>='D'&&s4[2]<='F')
			{
					cout<<"1111";
			}
			else
				cout<<"1100";
		}
		else
			cout<<"1000";
	}
	else
		cout<<"0000";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
