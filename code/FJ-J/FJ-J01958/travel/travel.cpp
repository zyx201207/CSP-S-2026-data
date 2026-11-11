#include<bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f3f3f3f3f
#define int long long 
signed main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		cout<<1;
	}
	else 
	{
		cout<<0<<0<<0<<0;
		return 0;
	}
	bool a=0;
	for(int i=0;s1[i];i++)
	{
		if(i<2)
		{
			if(s1[i]!=s2[i])
			{
				a=1;
			}
		} 
	}
	if(a==1)
	{
		cout<<0<<0;
		return 0;
	}
	else 
	{
		cout<<1;
	}
	for(int i=0;s1[i];i++)
	{
		if(i==2)
		{
			int a1=s1[i]-'A'+1;
			int a2=s2[i]-'A'+1;
			if(abs(a1-a2)==1)
			{
				if((a1==4&&a2==3)||(a1==3&&a2==4))
				{
					cout<<0<<0;
				}
				else
				{
					cout<<1<<1;
				}
			}
			else if((a1<=3&&a2<=3)||(a1>3&&a2>3))
			{
				cout<<1<<0;
			}
		}
	}
	return 0;
} 
