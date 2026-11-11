#include<bits/stdc++.h>
using namespace std;
bool gd(char a,char b,int c)
{
	bool f=false;
	if(c)
	{
		if(abs((int)a-(int)b)==1||((a=='A'||a=='C')&&(b=='A'||b=='C')))
		{
			f=true;
		}
		if((a=='C'||a=='D')&&(b=='C'||b=='D'))
		{
			f=false;
		}
	}
	else
	{
		if(abs((int)a-(int)b)==1&&!((a=='C'||a=='D')&&(b=='C'||b=='D')))
		{
			f=true;
		}
	}
	return f;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,s1,s2,ans1,ans2,ans3,ans4;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		ans1="1";
		if(s1[0]==s2[0]&&s1[1]==s2[1])
		{
			ans2="1";
			if(gd(s1[2],s2[2],1))
			{
				ans3="1";
				if(gd(s1[2],s2[2],0))
				{
					cout<<"1111";
					return 0;
				}
				else
				{
					cout<<"1110";
					return 0;
				}
			}
			else
			{
				cout<<"1100";
				return 0;
			}
		}
		else
		{
			cout<<"1000";
			return 0;
		}
	}
	else
	{
		cout<<"0000";
		return 0;
	}
	cout<<ans1<<ans2<<ans3<<ans4;
	return 0;
}
