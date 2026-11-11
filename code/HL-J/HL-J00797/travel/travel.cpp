#include<bits/stdc++.h>
using namespace std;
string s[6];
bool cp[5];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	for(int i=1;i<=4;i++)
	{
		cin>>s[i];
	}
	if(s[1]==s[3])
	{
		cp[1]=1;
	}
	else
	{
		cp[1]=0;
	}
	bool p=0;
	if(cp[1]=1)
	{
		if(s[2][0]==s[4][0]&&s[2][1]==s[4][1])
		{
			cp[2]=1;
			int num=s[2][2]-s[4][2];
			if((s[2][2]<='C'&&s[4][2]<='C')||(s[2][2]>='D'&&s[4][2]>='D'))
			{
				cp[3]=1;
				if(abs(num)==1)
				{
					cp[4]=1;
				}
					
			}
		}
	}
	for(int i=1;i<=4;i++)
	{
		cout<<cp[i];
	}
	return  0;
}