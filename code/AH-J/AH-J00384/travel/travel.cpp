#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,s1,c2,s2;
	char s3,s4;
	int s=0;
	cin>>c1>>s1>>s3>>c2>>s2>>s4;
	if(c1==c2)
	{
		s++;
		if(s1==s2)
		{
			s++;
			if(s3=="A"||"B"||"C"&&s4=="A"||"B"||"C")
			{
				s++;
				if(s3=="A"&&s4=="B"||s3=="B"&&s4=="C"||"A"||s3=="C"&&s4=="B"||s3=="D"&&s4=="F"||s3=="F"&&s4=="D")
				{
					s++;
				}
			}
			else if(s3=="D""F"&&s4=="D""F")
			{
				s++;
				if(s3=="A"&&s4=="B"||s3=="B"&&s4=="C"||"A"||s3=="C"&&s4=="B"||s3=="D"&&s4=="F"||s3=="F"&&s4=="D")
				{
					s++;
				}
			}
		}
	}
	if(s==0)
	{
		cout<<"0000";
	}
	if(s==1)
	{
		cout<<"1000";
	}
	if(s==2)
	{
		cout<<"1100";
	}
	if(s==3)
	{
		cout<<"1110";
	}
	if(s==4)
	{
		cout<<"1111";
	}
	return 0;
}
