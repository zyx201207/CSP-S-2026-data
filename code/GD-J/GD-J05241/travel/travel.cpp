#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,ans="0000";
inline bool check1()
{
	if(s1[2]>='D'||s2[2]>='D')
	{
		if(s1[2]<'D'||s2[2]<'D')
		{
			return false;
		}
	} 
	return abs(s1[2]-s2[2])<=2;
}

inline bool check2()
{
	if(s1[2]>='D'||s2[2]>='D')
	{
		return abs(s1[2]-s2[2])<=2;
	} 
	return abs(s1[2]-s2[2])<=1;
}

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		ans[0]='1';
		if(s1[0]==s2[0]&&s1[1]==s2[1])
		{	
			ans[1]='1';
			if(check1())
			{
				ans[2]='1';
				if(check2())
				{
					ans[3]='1';
				}
			}	
		} 
	}
	
	cout<<ans;
	
	return 0;
}
