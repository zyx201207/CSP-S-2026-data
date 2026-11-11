#include<bits/stdc++.h>
using namespace std;
bool pd(char a)
{
	if(a=='A'||a=='B'||a=='C')
	{
		return 1;
	}
	return 0;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2,s3,s4;
	cin>>s1>>s2>>s3>>s4;
	if(s1==s3)
	{
		cout<<1;
		if(s2[0]==s4[0]&&s2[1]==s4[1])
		{
			cout<<1;
			if(pd(s2[2])==pd(s4[2]))
			{
				cout<<1;
				if(abs(s2[2]-s4[2])==1)
				{
					cout<<1;
				}
				else
				{
					cout<<"0";
				}
			}
			else
			{
				cout<<"00";
			}
		}
		else
		{
			cout<<"000";
		}
	}
	else
	{
		cout<<"0000";
	} 
}

