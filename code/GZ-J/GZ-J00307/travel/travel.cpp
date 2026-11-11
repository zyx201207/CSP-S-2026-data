/*
	准考证号：GZ-J00307
	学校：华麟学校
	姓名：刘凌睿 
*/
#include<bits/stdc++.h>
using namespace std;
int a[10];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		a[1]=1;
		if(s1[0]==s2[0]&&s1[1]==s2[1])
		{
			a[2]=1;
			if(s1[2]>='D'&&s2[2]>='D')
			{
				a[3]=1;
				a[4]=1;
			}
			else if(s1[2]<'D'&&s2[2]<'D')
			{
				a[3]=1;
				if(int(s1[2])==int(s2[2])+1||int(s1[2])==int(s2[2])-1)
				{
					a[4]=1;
				}
			}
		}
	}
	for(int i=1;i<=4;i++)
	{
		cout<<a[i];
	}
	return 0;
}
