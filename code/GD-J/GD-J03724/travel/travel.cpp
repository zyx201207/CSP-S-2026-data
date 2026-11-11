#include <bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
bool judgeline()
{
	int tmp1=(s1[0]-'0')*10+(s1[1]-'0');
	int tmp2=(s2[0]-'0')*10+(s2[1]-'0');
	if(tmp1==tmp2)
	{
		return true;
	}
	else
	{
		return false;
	}
//	cout<<tmp1<<" "<<tmp2<<endl;
}
bool judgeleft()
{
	char tmp1=s1[2];
	char tmp2=s2[2];
	if(tmp1=='A' || tmp1=='B' || tmp1=='C')
	{
		if(tmp2=='A' || tmp2=='B' || tmp2=='C')
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		if(tmp2=='D' || tmp2=='F')
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}
bool judgebeside()
{
	int tmp1=s1[2]-'0';
	int tmp2=s2[2]-'0';
	if((tmp1==tmp2+1) || (tmp2==tmp1+1))
	{
		return true;
	}
	else
	{
		return false;
	}
}
int main()
{
	ios::sync_with_stdio(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
//	cout<<s1<<" "<<s2<<endl;
	if(c1==c2)
	{
		cout<<"1";
		if(judgeline()==true)
		{
			cout<<"1";
			if(judgeleft()==true)
			{
				cout<<"1";
				if(judgebeside()==true)
				{
					cout<<"1";
				}
				else
				{
					cout<<"0";
				}
			}
			else
			{
				cout<<"00";
				return 0;
			}
		}
		else
		{
			cout<<"000";
			return 0;
		}
	}
	else
	{
		cout<<"0000"<<endl;
		return 0;
	}
	return 0;
}
