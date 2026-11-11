#include <bits/stdc++.h>
using namespace std;
int c1,c2,ju1,ju2;
string s1,s2;
bool result[5]={0},ce1,ce2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2)
    {
    	result[1]="1";
		if(s1[0]==s2[0] && s1[1]==s2[1])
		{
			result[2]="1";
			if(s1[2]=='A')
			{
				ce1=0,ju1=1;
			}
			if(s1[2]=='B')
			{
				ce1=0,ju1=2;
			}
			if(s1[2]=='C')
			{
				ce1=0,ju1=3;
			}
			if(s1[2]=='D')
			{
				ce1=1,ju1=4;
			}
			if(s1[2]=='F')
			{
				ce1=1,ju1=5;
			}
			if(s2[2]=='A')
			{
				ce2=0,ju2=1;
			}
			if(s2[2]=='B')
			{
				ce2=0,ju2=2;
			}
			if(s2[2]=='C')
			{
				ce2=0,ju2=3;
			}
			if(s2[2]=='D')
			{
				ce2=1,ju2=4;
			}
			if(s2[2]=='F')
			{
				ce2=1,ju2=5;
			}
			if(ce1==ce2)
			{
				result[3]="1";
				if((ju1==1 && ju2==2) || (ju1==2 && ju2==1) || (ju1==2 && ju2==3) || (ju1==3 && ju2==2) || (ju1==4 && ju2==5) || (ju1==5 && ju2==4))
				{
					result[4]="1";
				}
			}
		}
	}
	for(int i=1;i<=4;i++)
	{
		cout<<result[i];
	}
	return 0;
}

