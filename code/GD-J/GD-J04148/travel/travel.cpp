#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1=="01"||c2=="01"||c1=="16"||c2=="16")
	{
		cout<<"0000";
		return 0;
	}
	if(c1==c2)
	{
		cout<<"1";
		if(s1[1]==s2[1]&&s1[0]==s2[0])
		{
			cout<<"1";
			int t1=0,t2=0;
			if(s1[2]<='C'&&s1[2]>='A')
			{
				t1=1;
			}
			else
			{
				t1=2;
			}
			if(s2[2]<='C'&&s2[2]>='A')
			{
				t2=1;
			}
			else
			{
				t2=2;
			}
			if(t1==t2)
			{
				cout<<"1";
				int sum=abs(int(s1[2])-int(s2[2]));
				if(sum==1)
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
